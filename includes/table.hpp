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
#    include "macro_for_each.h"
#    define mk_table(NAME) Table<struct NAME##_Format> NAME
#    define mk_tables(NAMES...) FOR_EACH(mk_table, NAMES)
#endif

template <typename T>
struct Table {

    static constexpr unsigned links_count = OPTIONAL(T::links_count, 1);
    static constexpr unsigned entries_count = OPTIONAL(T::entries_count, 64);
    template <typename U = T>
        requires(true)
    struct Frame__ {
        Frame__ (*links)[links_count];
        U data[entries_count];
        auto operator[](auto i) {}
        using type = U;
    };

    template <typename U> struct Frame__<U *> : Frame__<U> {};
    template <typename U> struct Frame__<U &> : Frame__<U> {};
    template <typename U> struct Frame__<U &&> : Frame__<U> {};
    using Frame = Frame__<>;
    auto operator[](auto i) { return ptr[0][i]; }
    Table();
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
    static constexpr bool does_nothing = true;
};

#define __Vectorized_ignore(X)                                                 \
    template <typename T> struct Vectorized<T X> : Vectorized<T> {}
FOR_EACH(__Vectorized_ignore, const, volatile, &, &&, *);
template <typename T>
using vectorized_t = Vectorized<T>::type;

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

template <auto(&mainTable), class KEY>
struct Link<mainTable, KEY> {
    using index_t = KEY;
    constexpr auto &operator[](auto i) { return mainTable[index[i]]; }
    index_t index;
};

template <auto &mainTable, class Key1, class Key2, class... CHAINS>
struct Link<mainTable, Key1, Key2, CHAINS...> : Key2 {
  private:
    static Table<Link<mainTable, class key1>> out;

  public:
    static constexpr auto N = Key1::count;
    using index_t = Link<out, Key2, CHAINS...>::index_t;
    constexpr auto &operator[](auto i) {
        return mainTable[out[i % N][index[i / N]]];
    }
    index_t index;
};

template <auto(&mainTable), class... CHAINS>
    requires((..., !vectorized_t<CHAINS>::does_nothing), sizeof...(CHAINS))
struct Link<mainTable, CHAINS...> : Link<mainTable, vectorized_t<CHAINS>...> {};
