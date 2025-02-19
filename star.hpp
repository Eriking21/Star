/**
 * Copyright 2025 Erivaldo Jair Xavier Mate
 * @brief If you cant deal with performance search for "unsafe"
 **/

#pragma once

#ifndef mk_table 
//// @note create a Table (pointer to a list of items sharing same Format).
#define mk_table(NAME)struct NAME##_Format* NAME
#endif

#ifndef mk_tables
#include "macro_for_each_100"
#define mk_tables(NAMES...) FOR_EACH(mk_table, NAMES)
#endif

#ifdef EXPORT_ERIM_NAMESPACE
namespace erim::star {
#endif

template <typename U, auto MaxSize>
concept type_smaller_than = sizeof(U) <= MaxSize;

template <auto &table, typename Index_t, unsigned Number_of_Indexes = 1>
struct Link {
    Index_t keys[Number_of_Indexes];

    typedef Index_t key_t;
    typedef decltype(*table) data_t;
    static constexpr auto key_size = sizeof(key_t);
    static constexpr auto data_size = sizeof(data_t);
    static constexpr auto number_of_keys = Number_of_Indexes;

    constexpr data_t &operator[](auto i) { return table[keys[i]]; }
};

template <auto &table, typename Index_t, typename link_t>

struct Chain : link_t {
    Index_t sub_keys[];

    using link_t::data_size;
    using link_t::key_size;
    using typename link_t::data_t;
    static constexpr auto qtd = (data_size - key_size) / sizeof(sub_keys);
    static_assert(link_t::number_of_keys == 1);

    constexpr data_t &operator[](auto i) {
        for (Chain *c = this->link_t[0]; true; i -= qtd, c = c->link_t[0])
            if (i < qtd) return table[c->sub_keys[i]];
    }
};

/**
 * @examples
 * Chain<Block32,Movies,int,long> movies;
 * Link<Movies,int,4> movies;
 **/
#ifdef EXPORT_ERIM_NAMESPACE
}
#endif
