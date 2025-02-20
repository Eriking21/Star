/**
 * Copyright 2025 Erivaldo Jair Xavier Mate
 * @brief If you cant deal with performance search for "unsafe"
 **/

#pragma once

#ifndef mk_table
/** @note create a Table (pointer to a list of items sharing same Format). **/
#define mk_table(NAME) struct NAME##_Format *NAME
#endif

#ifdef ERIM_LINK_NAMESPACE
/// To block collisions and to allow suitable aliasing of those structs
/// TO Encript wrap Index_t with class with integral cast operator.
namespace ERIM_LINK_NAMESPACE {
#endif

#ifndef mk_tables
#include "macro_for_each.hpp"
#define mk_tables(NAMES...) FOR_EACH(mk_table, NAMES)
#endif

template <typename U> class Box {
    U secret;
} __attribute__((packed));

/**
 *
 *                          Link
 *
 * @param first is an array like structure type to index the table
 * @param last  is a reference to a Table (static/global Pointer to an Array)
 * @param before_last add optional padding to indent the struct
 **/
template <class Key_Cls, auto A, auto... B>
    requires(sizeof...(B) <= 1)
struct Link;

template <class KEYS, auto &TABLE, auto Pad>
struct Link<KEYS, Pad, TABLE> : Box<char[Pad]>, Link<KEYS, TABLE> {};

template <class Key_Cls, auto &Table_v>
struct Link<Key_Cls, Table_v> : Key_Cls {

    using data_t = decltype(*Table_v);
    constexpr data_t &operator[](auto i) { return Table_v[Link::Key_Cls[i]]; }
} __attribute__((packed));

template <class Key_t, unsigned Key_Count, auto &Table_v>
struct Link<Key_t[Key_Count], Table_v> {
    using key_t = Key_t;
    using Keys_t = Key_t[Key_Count];
    using data_t = decltype(*Table_v);
    static constexpr auto key_size = sizeof(key_t);
    constexpr data_t &operator[](auto i) { return Table_v[keys[i]]; }
    Keys_t keys;
} __attribute__((packed));

/**
 *                          Chain
 *
 * @param first  is the chain key type, represent the chain part
 * @param second is the inner key type, base typr of an array of keys
 * @param last  is a reference to a Table (static/global Pointer to an Array)
 * @param before_last add optional padding to indent the struct
 **/
template <class Key_t, class SubKey_t, auto A, auto... B>
    requires(sizeof...(B) <= 1 || ((B * ... * 1) == 0))
struct Chain;

template <class K1, class K2, auto TABLE>
struct Chain<K1, K2, TABLE> : Chain<K1, K2, 0, TABLE> {};

template <class K1, class K2, auto PAD, auto &TABLE>
struct Chain<K1, K2, PAD, TABLE> {
    static constexpr auto key_count =
        (sizeof(*TABLE) - sizeof(K1) - PAD) / sizeof(K2);
    using keys_t = K2[key_count];
    using line_t = Chain<Box<K1>, keys_t, PAD,
                         sizeof(*TABLE) - sizeof(K1) - sizeof(keys_t) - PAD>;
    using main_key_t = K1;
    K1 main_key;
    constexpr K2 operator[](auto i) {
        line_t *line = (line_t *)(TABLE[this->main_key]);
        while (i >= key_count)
            line = *(line_t *)(TABLE[line->main_key]), i -= key_count;
        return line->keys[i];
    }
} __attribute__((packed));

template <class K1, class Keys>
struct Chain<Box<K1>, Keys, 0, 0> {
    K1 main_key;
    Keys keys;
} __attribute__((packed));

template <class K1, class Keys, auto PAD>
struct Chain<Box<K1>, Keys, PAD, 0> {
    K1 main_key;
    char pad[PAD];
    Keys keys;
} __attribute__((packed));

template <class K1, class K, auto P, auto R>
struct Chain<Box<K1>, K, P, R> : Chain<Box<K1>, K, P, 0>, Box<char[R]> {
};

#ifdef ERIM_LINK_NAMESPACE
}
#endif