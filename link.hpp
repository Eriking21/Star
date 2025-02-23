#pragma once
/**
 * Copyright 2025 Erivaldo Jair Xavier Mate
 * @brief If you cant deal with performance search for "unsafe"
 **/

#ifndef mk_table
/**  @note create a Table (pointer to a list of items sharing same Format). **/
#    define mk_table(NAME) struct NAME##_Format *NAME
#endif

#ifdef ERIM_LINK_NAMESPACE
/// To block collisions and to allow suitable aliasing of those structs
/// TO Encript wrap Index_t with class with integral cast operator.
namespace ERIM_LINK_NAMESPACE {
#endif

#ifndef mk_tables
#    include "macro_for_each.hpp"
#    define mk_tables(NAMES...) FOR_EACH(mk_table, NAMES)
#endif

/**
 *                          Link
 *
 * @param first is an array like structure type to index the table
 * @param last  is a reference to a Table (static/global Pointer to an Array)
 * @param before_last add optional padding to indent the struct
 **/
template <typename T, auto...>
struct Box {
    T data;
    using type = T;
    constexpr operator auto &() { return data; }
} __attribute__((packed));

template <typename T>
concept __Indexable = requires(T v) { v.*T::keys, T::count, v[0]; };
template <typename T>
concept __Index_with_key = requires(T key_v, T k[2]) { k[key_v.*T::key]; };

template <auto *(&Table_v), class Keys_t, class... chain_t>
struct Link;

template <class Key_t, unsigned Key_Count, typename T, T *(&Table_v)>
struct Link<Table_v, Key_t[Key_Count]> : Box<Key_t[Key_Count]> {
    static constexpr auto keys = &Box<Key_t[Key_Count]>::data;
    static constexpr auto count = Key_Count;
};

template <class Keys_t, class Chain_t, typename T, T *(&Table_v)>
struct Link<Table_v, Keys_t, Chain_t> : Box<Chain_t> {
    static constexpr auto key = &Box<Chain_t>::data;
};

template <__Indexable Keys_t, class T, T *(&Table_v)>
struct __attribute__((packed)) Link<Table_v, Keys_t> : Keys_t {
    using data_t = T;
    constexpr data_t &operator[](auto i) { return Table_v[Link::Keys_t[i]]; }
};

template <__Indexable Keys_t, class T, T *(&Table_v), __Index_with_key Chain_t>
struct __attribute__((packed)) Link<Table_v, Keys_t, Chain_t> : Chain_t {

    struct __attribute__((packed)) Chain_Format : Chain_t, Keys_t {};
    static Chain_Format *chain_table;

    constexpr T operator[](auto i) {
        auto *chain = &chain_table[this->*Chain_t::key];
        while (i < Keys_t::count)
            chain = chain_table[chain->key], i -= Keys_t::count;
        return Table_v[chain->keys[i]];
    }
};

#ifdef ERIM_LINK_NAMESPACE
}
#endif