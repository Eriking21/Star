#include "tables.hpp"

// linux only
// #include <stdio.h>
#include <cstring>
#include <fcntl.h>
#include <iostream>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define mk_mmap(FD, SIZE)                                                      \
    mmap(0, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, FD, 0)

thread_local char path[32] = "./Table/Ref0000000000000000.bin";

template <typename T>
static inline T *mmap(const char *path, size_t size) {
    std::cout << path;
    int fd = open(path, O_RDWR | O_CREAT | O_TRUNC, 0660);
    if (fd == -1) exit(1);
    if (ftruncate(fd, size) == -1) close(fd), exit(2);
    void *map = mk_mmap(fd, size);
    if (map == MAP_FAILED) close(fd), exit(3);
    close(fd);
    std::cout << path << "\n";
    return (T *)(map);
}
// do not return nullptr exits

TABLE::HEAD::HEAD() : tables{*mmap<List_t>("./Tables", size)} {}
TABLE::HEAD::~HEAD() {
    munmap(this, size);
    std::cout << "HEAD TERMINATED\n";
}

void TABLE::HEAD::unload(Info **info) const{
    if (info == nullptr || info[0] == nullptr) return;
    std::cout << "done\n";
    munmap(info, info[0][0].node_size);
}

void *TABLE::HEAD::retrieve_block(void *, unsigned long) { return nullptr; }

void *TABLE::HEAD::load(Named_Info info) {

    Info &table = [&]() -> Info & {
        for (Named_Info &table : tables) {
            std::cout << table.name << '\n';
            if (!memcmp(table.name, info.name, sizeof(info.name))) return table;
            else if (table.name[0] == 0) return (table = info);
            else {
                info.list_position++;
                continue;
            }
        }
        exit(4);
    }();
    // std::cout << "oi";
    // void *ptr = mmap<void>(path, table.node_size);
    // void *k[pow2(bits_of(table.node_links_count))];

    return nullptr;
}
