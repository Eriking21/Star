#include "tables.hpp"
// #include <typeinfo>

// linux only
// #include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

//do not return nullptr exits
void* alloc(unsigned long size,const char* Name){
    return (void*)Name;
}