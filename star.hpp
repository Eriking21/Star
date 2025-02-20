/**
 * Copyright 2025 Erivaldo Jair Xavier Mate
 * @brief If you cant deal with performance search for "unsafe"
 **/

#pragma once

#ifndef mk_table
/** @note create a Table (pointer to a list of items sharing same Format). **/
#define mk_table(NAME) struct NAME##_Format *NAME
#endif

#ifdef ERIM_STAR_NAMESPACE
/// To block collisions and to allow suitable aliasing of those structs
/// TO Encript wrap Index_t with class with integral cast operator.
namespace ERIM_STAR_NAMESPACE {
#endif

#ifndef mk_tables
#include "macro_for_each.hpp"
#define mk_tables(NAMES...) FOR_EACH(mk_table, NAMES)
#endif

template <auto line_bytes, auto... diffs> char global_table[line_bytes];

template <auto &table, typename Idx_t, unsigned Count = 0, unsigned Pad = 0>
struct Link {
  using key_t = Idx_t;
  using data_t = decltype(*table);
  static constexpr auto key_count = Count ? Count : 1;
  static constexpr auto key_size = sizeof(key_t);
  static constexpr auto link_size = key_size * key_count + Pad;
  static constexpr auto link_table = table;

  template <unsigned C = Count> using COUNT_to = Link<table, Idx_t, C, Pad>;

  Idx_t keys[key_count];
  char padding[Pad];
  constexpr data_t &operator[](auto i) { return table[keys[i]]; }
} __attribute__((packed));

template <auto &table, typename Idx_t, class link_t, class L = link_t::data_t>
struct Chain : private link_t {

  using data_t = decltype(*table);
  using key_t = typename link_t::key_t;
  using link_t::key_size;
  using link_t::link_size;
  static constexpr auto sub_key_size = sizeof(Idx_t);
  static constexpr auto sub_key_count = (sizeof(L) - link_size) / sub_key_size;

  struct Line : link_t {
    Idx_t sub_keys[sub_key_count];
  } __attribute__((packed));

  //   constexpr data_t &operator[](auto i) {
  //     Line *c = *(Line *)(&this->link_t[0]);
  //     while (i >= sub_key_count)
  //       c = *(Line *)(&c->link_t[0]);
  //     return table[c->sub_keys[i]];
  //   }
};

#ifdef ERIM_STAR_NAMESPACE
}
#endif
