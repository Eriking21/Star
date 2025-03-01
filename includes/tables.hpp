#pragma once
/**
 * Copyright 2025 Erivaldo Jair Xavier Mate
 * @brief If you can't deal with performance search for "unsafe"
 **/
#include "macros.hpp"
#include <typeinfo>
#ifdef ERIM_TABLE_NAMESPACE
namespace ERIM_TABLE_NAMESPACE {
#endif

template <typename T>
struct Vectorized {
    using type = T[1];
};

template <typename T, unsigned N>
struct Vectorized<T[N]> {
    using type = T[N];
    static constexpr unsigned count = N;
    static constexpr bool is_vectorized = true;
};
template <typename U> struct Vectorized<U *> : Vectorized<U> {};
template <typename U> struct Vectorized<U &> : Vectorized<U> {};
template <typename U> struct Vectorized<U &&> : Vectorized<U> {};

#ifndef mk_Table
/**  @note create a Table (with a pointer to a list of items sharing same
 * Format). **/
#    define mk_table(NAME) Table<struct NAME##_Format> NAME
#    define mk_tables(...) FOR_EACH(mk_table, __VA_ARGS__)
#endif

struct BaseTable {
  protected:
    using uint_t = Half_t<half_t>;
    static constexpr auto NAME_SIZE = 128 - sizeof(size_t) * 2;
    static constexpr char HEX[]{'d', 'e', 'f', 'h', 'i', 'j', 'k', 'm',
                                'n', 'o', 'p', 'u', 'v', 'w', 'x', 'y'};
    struct Info {
        union {
            struct {
                mutable uint_t last = 0;
                uint_t position = 0;
                uint_t mask;
                uint_t bits;
            } node_id;
            char node_code[sizeof(size_t)];
        };

        size_t node_size;
        char name alignas(sizeof(size_t) * 2)[NAME_SIZE];
        constexpr const char *name_cstr() const noexcept { return name; }
        constexpr size_t count() const noexcept { return pow2(node_id.bits); }
        constexpr bool operator==(const Info &other) const noexcept {
            return !__builtin_memcmp(this->name, other.name, NAME_SIZE);
        }
        constexpr Info(auto name, size_t node_size, uint_t nodes_bits)
            requires(requires { name[0]; })
            : node_id{0, 0, nodes_bits, uint_t((pow2(nodes_bits))-1)},
              node_size(node_size) {
            unsigned i = 0;
            do this->name[i] = name[i];
            while (name[i] && (++i < NAME_SIZE));
            while (++i < (NAME_SIZE - 1)) this->name[i] = 0;
        }
    };
    struct Table {
        using List_t = Info[128];
        static constexpr size_t max_ids = size_t(1) + uint_t(-1);
        static constexpr uint_t max_depth = (bits_of(uint_t) >> 1);
        static constexpr uint_t size = sizeof(List_t);

        void *const load(const Info info) const noexcept;

        void unload(const void *ptr) const noexcept;
        void unload(auto *p) const noexcept { return unload((const void *)p); };

        void *const search_allocated_node(uint_t, void *) const noexcept;
        const Info &search(Info info) const noexcept;

        List_t &tables;
        Table();
        ~Table();

        typedef union Node {
            const Info *info;
            Node *nodes[max_ids];
        } *NodeRoute[max_ids];
    } static inline const table;
};

template <typename Format>
class Table : BaseTable {
    union Node {
        Info *info;
        struct {
            Node *nodes[MAX_OPT(base2_of(Format::NODES_COUNT), 4)];
            Format data[MAX_OPT(Format::ITEMS_COUNT, 256 - sizeof(nodes))];
        };
        static constexpr inline Info const_info() noexcept {
            return {typeid(Table).name(), sizeof(Node),
                    bsrl(sizeof(data) / sizeof(Format))};
        }
    } *const ptr;

  public:
    constexpr const Info &info() const noexcept { return ptr->info[0]; }
    constexpr Table(void *const ptr) noexcept : ptr((Node *)ptr) {}
    Table() noexcept : Table(table.load(Node::const_info())) {}
    ~Table() noexcept { table.unload<Node>(ptr); }

    Format &operator[](auto i) const noexcept
        requires(requires { ptr->data[i]; }) {
        Node *deep = ptr;
        auto r = i % Node::ITEMS;
        if ((i /= Node::ITEMS) != 0) {
            if constexpr (requires { i.is_allocable; }) {
                deep = ((Node *)table.search_allocated_node(i, this));
            } else {
                uint_t pos, j = bsrl(i);
                j -= (j & Node::const_info().node_id.mask);
                do pos = i >> j, deep = deep->nodes[pos], i ^= (pos << j);
                while (j -= Node::const_info().node_id.bits);
            }
        }
        return deep->data[r];
    };
};

template <typename U> struct Table<U *> : Table<U> {};
template <typename U> struct Table<U &> : Table<U> {};
template <typename U> struct Table<U &&> : Table<U> {};

#ifdef ERIM_TABLE_NAMESPACE
}
#endif

/**
 *                          Link
 *
 * @param first  is a reference to a Table (static/global Pointer to an
 *Array)chain_t
 * @param second is an array like structure type to index the refered
 *Tablechain_tchain_t
 * @param third  is an Optional Indexor for an aditional chain Table
 **/
template <auto(&mainTable), class... CHAINS>
struct Link;

template <auto &mainTable, class Key1>
struct Link<mainTable, Key1> {
    using index_t = typename Vectorized<Key1>::type;
    constexpr auto &operator[](auto i) { return mainTable[index[i]]; }
    index_t index;
};

template <auto &mainTable, class Key1, class Key2, class... CHAINS>
struct Link<mainTable, Key1, Key2, CHAINS...> {
  private:
    static inline Table<Link<mainTable, Key1>> out;

  public:
    static constexpr auto N = Vectorized<Key1>::count;
    using index_t = Link<out, Key2, CHAINS...>::index_t;
    constexpr auto &operator[](auto i) {
        return mainTable[out[i % N][index[i / N]]];
    }
    index_t index;
};