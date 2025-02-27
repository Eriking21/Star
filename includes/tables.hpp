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

struct TABLE {
    struct Info {
        union {
            struct {
                mutable half_t last_node_id;
                Half_t<half_t> node_links_count;
                Half_t<half_t> list_position;
            };
            Hex_convertible_t<alignof(size_t)> node_code;
        };
        size_t node_size;
        constexpr const Info &get_Info() const { return *this; }
    };
    struct Name {
        char name[128 - sizeof(Info)];
        operator const decltype(name) & () const { return name; }
        Name(const char *name) {
            unsigned i = 0;
            do this->name[i] = name[i];
            while (*name && ++i < (sizeof(this->name) - 1));
            while (i < (sizeof(this->name) - 1)) this->name[i++] = 0;
        }
        constexpr const char *get_name() const { return name; }
    };
    struct Named_Info : Name, Info {
        Named_Info(const Name n, const Info i) : Name(n), Info(i) {};
        Named_Info(const Named_Info &) = default;
        Named_Info(Named_Info &&) = default;
        Named_Info &operator=(const Named_Info &) = default;
        Named_Info &operator=(Named_Info &&) = default;
    };

    struct HEAD {
        using List_t = Named_Info[128];
        static constexpr unsigned size = sizeof(List_t);
        void *retrieve_block(void *, unsigned long);
        void *load(const Named_Info info);
        void unload(TABLE &);
        List_t& tables;
        HEAD();
    } static inline head;
};

template <typename T>
class Table : TABLE {
    struct Node {
        static constexpr size_t Z = (MAX_OPT(base2_of(T::links_count), 2));
        static constexpr size_t N = MAX_OPT(T::entries_count, 64);
        mutable Node *nodes[Z];
        T data[N];
    } *const ptr;

  public:
    Table(void *ptr) : ptr{(Node *)ptr} {}
    Table()
        : Table{head.load({typeid(Table).name(),
                           {.node_links_count = sizeof(Node::Z),
                            .node_size = sizeof(Node)}})} {}

    // ~Table() { unload_info(*this); }

    static inline constexpr unsigned long block_size() { return sizeof(Node); }
    template <typename U>
        requires(requires(U *j, size_t k) { k = *j; })
    T &operator[](U i) const noexcept {
        static constexpr unsigned K = bsrl(Node::Z);
        Node *deep = ptr;
        unsigned r = i % Node::N, j;
        if ((i /= Node::N) != 0) {
            // Allocate only if needed
            // Inflate index: to avoid first frame
            j = (bsrl(i) - (bsrl(i) % K));
            i += pow2(j);
            if constexpr (requires { i.is_allocable; })
                deep = ((Node *)head.retrieve_block(this, i));
            else // Travel deep nodes
                while (deep = deep->nodes[i >> j], i &= pow2(j) - 1, j -= K);
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