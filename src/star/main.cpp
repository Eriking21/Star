// #pragma once
#include "iostream"
#include "tables.hpp"
mk_tables(Users, Movies, hot);

struct Users_Format {
    // Link<Movies, int[14]> watched;
    //  Chain<Movies, int, Link<global_table<32>, int>> watcheds;
    //  Chain<Movies, int, Link<global_table<32>, int>> publisheds;
};

struct hot_Format {};

struct Movies_Format {
    char d[4];
    static constexpr auto ENTRIES_COUNT = 50ull;
    static constexpr auto NODES_COUNT = 4ull;
    Link<Movies, int[40], long> watched;

    // Link<Chain<int, int, hot>,Users> watched;
    // Link<Chain<int, int, hot>,7,Users> wathed;
    // Chain<int, int, hot> watched;
};
Table<hot_Format> k;

// #include <typeinfo>
int main(int, char **) {
    std::cout << '\n'
              << Movies.ptr->info().node_size << '\n'
              << hot.ptr->info().node_size << '\n'
              << Users.ptr->info().node_size << '\n'
              << Movies.ptr->info().node_size << '\n';
}