/**
 * @file tables.cpp
 * @version 1.1
 * @date 2025
 *
 * @brief Implementation of the BaseTable::Table class for managing table data.
 *
 * This file contains the implementation of the BaseTable::Table class, which
 * provides functionalities for loading, unloading, and searching table data
 * using memory-mapped files.
 *
 * The main functionalities implemented in this file are:
 * - Memory-mapping a file to load table data.
 * - Constructor and destructor for the Table class.
 * - Searching for a table entry.
 * - Loading a table entry.
 * - Unloading a table entry.
 *
 * The code uses Linux-specific system calls and libraries for memory mapping.
 *
 * @note The code uses advanced C++ features such as templates, thread-local
 * storage, and structured bindings.
 *
 * @warning The code exits the program on errors without providing detailed
 * error messages.
 *
 * @copyright
 * (C) 2025 Erivaldo Mate. All rights reserved.
 */

#include "tables.hpp"
// linux only
#include <cstring>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

/**
 * @brief Memory-maps a file.
 *
 * This function opens a file, truncates it to the specified size, and maps it
 * into memory.
 *
 * @tparam T The type of the mapped memory.
 * @param path The path to the file to be mapped.
 * @param size The size of the file to be mapped.
 * @return A pointer to the mapped memory.
 */
template <typename T = void>
static inline T *mmap(const char *path, size_t size) noexcept {
    int fd = open(path, O_RDWR | O_CREAT, 0660);
    if (fd == -1) exit(1);
    if (ftruncate(fd, size) == -1) close(fd), exit(2);
    void *map = mmap(0, size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (map == MAP_FAILED) close(fd), exit(3);
    close(fd);
    return (T *)(map);
}

static thread_local char path[32] = "./Table/TABLE.bin\0___000___.bin";
static thread_local char *path_end = &path[sizeof(path) - 6];

/**
 * @brief Constructor for the Table class.
 *
 * This constructor initializes the table by memory-mapping the file specified
 * in the path.
 */
BaseTable::Table::Table() : tables{*mmap<List_t>(path, size)} {}

/**
 * @brief Destructor for the Table class.
 *
 * This destructor unmaps the memory-mapped file.
 */
BaseTable::Table::~Table() { munmap(&this->tables, size); }

/**
 * @brief Searches for a table entry.
 *
 * This function searches for a table entry that matches the given Info object.
 * If a matching entry is found, it is returned. If an empty entry is found, the
 * given Info object is stored in it and returned.
 *
 * @param _info The Info object to search for.
 * @return A reference to the matching or newly stored Info object.
 */
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

/**
 * @brief Loads a table entry.
 *
 * This function loads a table entry that matches the given Info object by
 * memory-mapping the corresponding file and setting up the node route.
 *
 * @param _info The Info object to load.
 * @return A pointer to the loaded table entry.
 */
void *const BaseTable::Table::load(Info _info) const noexcept {
    auto &info = search(_info);
    NodeRoute route;
    const auto code = info.node_id;
    const auto &[i, _, bits, mask] = code;
    const auto node_size = info.node_size;

    uint_t last_id = i;
    for (i = 0; i <= last_id; i++) {
        write_hex<true, HEX>(path_end,
                             (const char(&)[sizeof(size_t) - 1]) code);
        route[i] = mmap<Node>(path, node_size);
        route[i >> bits]->nodes[i & mask] = route[i];
    }

    route[0]->info = &info;
}

/**
 * @brief Unloads a table entry.
 *
 * This function unloads a table entry by unmapping the memory-mapped files.
 * It traverses the node route, Flat as a list then unmaps each node.
 *
 * @param deep A pointer to the table entry to unload.
 */
void BaseTable::Table::unload(const void *deep) const noexcept {
    const auto [last_id, position, bits, mask] = ((Info **)deep)[0][0].node_id;
    const auto node_size = ((Info **)deep)[0][0].node_size;
    NodeRoute route{(Node *)deep};
    uint_t i = 0;
    while (i < last_id) ++i, route[i] = route[i >> bits]->nodes[i & mask];
    do { munmap(route[i], node_size); } while (i--);
    return;
}