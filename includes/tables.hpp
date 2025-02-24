#pragma once
/**
 * Copyright 2025 Erivaldo Jair Xavier Mate
 * @brief If you can't deal with performance search for "unsafe"
 **/

#ifdef ERIM_TABLE_NAMESPACE
namespace ERIM_TABLE_NAMESPACE {
#endif

#ifndef mk_Table
/**  @note create a Table (pointer to a list of items sharing same Format). **/
#    include "macros.hpp"
#    define mk_table(NAME)                                                     \
        static constexpr auto NAME##_Name = #NAME;                             \
        Table<struct NAME##_Format, NAME##_Name> NAME
#    define mk_tables(NAMES...) FOR_EACH(mk_table, NAMES)
#endif

void *alloc(unsigned long, const char * = nullptr); // exits_on_error
template <typename T, auto&... Name>
struct Table {

    template <typename U = T>
    struct __attribute((packed)) Frame__ {
        static constexpr const char* table_name = OPTIONAL(T::table_name, (nullptr,...,Name));
        static constexpr auto links_count = OPTIONAL(T::links_count, 1ull);
        static constexpr auto entries_count = OPTIONAL(T::entries_count, 64ull);
        Frame__ *links[links_count];
        U data[entries_count];
        auto operator[](auto i) {}
        using type = U;
    };

    template <typename U> struct Frame__<U *> : Frame__<U> {};
    template <typename U> struct Frame__<U &> : Frame__<U> {};
    template <typename U> struct Frame__<U &&> : Frame__<U> {};
    using Frame = Frame__<>;
    auto operator[](auto i) { return ptr[0][i]; }
    Table() : ptr((Frame *)alloc(sizeof(Frame), Frame::table_name)) {}
    const Frame *ptr;
};

#ifdef ERIM_TABLE_NAMESPACE
}
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

#define Vectorized_ignores(X)                                                  \
    template <typename T> struct Vectorized<T X> : Vectorized<T> {}
FOR_EACH(Vectorized_ignores, const, volatile, &, &&, *);

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