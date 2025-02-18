/**
 * Copyright 2025 Erivaldo Jair Xavier Mate
 * @brief If you cant deal with performance search for "unsafe"
 **/

#pragma once

#ifndef mk_table
#define mk_table(NAME) struct NAME##_Format* NAME
#endif

#ifdef EXPORT_ERIM_NAMESPACE
namespace erim::star{
#endif

template<auto& table,typename Idx_t,unsigned qtd=1>
struct Link{  
  Idx_t keys[qtd];
  constexpr decltype(*table)& operator[](auto i=0){
    return table[keys[i]]; //unsafe
  }
}

template<auto& chain_table, auto& table, typename Idx_t, typename Chain_Idx_t = Idx_t>
struct Chain {  
  Chain_Idx_t prev;
  Idx_t keys[];

  static constexpr unsigned qtd = (sizeof(decltype(*chain_table))
- sizeof(Chain_Idx_t))/sizeof(Idx_t));

  constexpr decltype(*table)& operator[](auto i=0){
   for ( Chain* c = this;true; i-=qtd){
      c = (Chain*)&chain_table[c->prev];
      if (i<qtd) return table[c->keys[i]];
  }
}

/**
 * @examples
 * Chain<Block32,Movies,int,long> movies;
 * Link<Movies,int,4> movies;
**/
#ifdef USE_ERIM_NAMESPACE
}
#endif

