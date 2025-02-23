#include "table.hpp"
//linux only 
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>

template <typename T>
Table<T>::Table() {
    mmap();

}