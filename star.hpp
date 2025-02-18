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

template<auto& vector,typename Idx,unsigned qtd=1>
struct Link{  
  Idx keys[qtd];
  decltype(*vector)& operator[](auto i=0){
    return vector[keys[i]]; //unsafe
  }
}

#ifdef USE_ERIM_NAMESPACE
}
#endif

