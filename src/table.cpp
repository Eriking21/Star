#include "tables.hpp"

// linux only
// #include <stdio.h>
#include <cstring>
#include <fcntl.h>
// #include <iostream>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

template <typename T = void>
static inline T *mmap(const char *path, size_t size) noexcept {

    int fd = open(path, O_RDWR | O_CREAT, 0660);
    if (fd == -1) exit(1);
    if (ftruncate(fd, size) == -1) close(fd), exit(2);
    void *map = mmap(0, size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (map == MAP_FAILED) close(fd), exit(3);
    close(fd);
    //    std::cout << "DONE: " << path << "\n";
    return (T *)(map);
}
// do not return nullptr exits

thread_local char path[32] = "./Table/TABLE.bin\0___000___.bin";
thread_local char *path_end = &path[sizeof(path) - 6];
BaseTable::Table::Table() : tables{*mmap<List_t>(path, size)} {}
BaseTable::Table::~Table() { munmap(&this->tables, size); }

const BaseTable::Info &BaseTable::Table::search(Info _info) const noexcept {
    int i = 0;
    for (Info &table : tables) {
        if (table.name[0] == 0) return (table = _info); // store + load
        else if (_info == table) return table;
        else {
            _info.node_id.position++;
            continue;
        }
    }
    exit(4);
}
void *const BaseTable::Table::load(Info _info) const noexcept {
    auto &info = search(_info);
    NodeRoute route;
    const auto code = info.node_id;
    const auto &[i, _, bits, mask] = code;
    const auto node_size = info.node_size;

    uint_t last_id = i;
    for (i = 0; i <= last_id; i++) {
        write_hex<true,HEX>(path_end, (const char(&)[sizeof(size_t) - 1]) code);
        route[i] = mmap<Node>(path, node_size);
        route[i >> bits]->nodes[i & mask] = route[i];
    }

    route[0]->info = &info;
    return route[0];
    //    std::cout << "erim: " << route[0]->info->name << '\n';
}

void BaseTable::Table::unload(const void *deep) const noexcept {
    const auto [last_id, position, bits, mask] = ((Info **)deep)[0][0].node_id;
    const auto node_size = ((Info **)deep)[0][0].node_size;
    NodeRoute route{(Node *)deep};
    uint_t i = 0;
    while (i < last_id) ++i, route[i] = route[i >> bits]->nodes[i & mask];
    do { munmap(route[i], node_size); } while (i--);
    return;
}