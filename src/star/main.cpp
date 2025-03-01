// #pragma once
#include "tables.hpp"
#include <cstdio>
#include <iostream>
mk_tables(Users, Movies, hot);

struct Users_Format {
    // Link<Movies, int[14]> watched;
    //  Chain<Movies, int, Link<global_table<32>, int>> watcheds;
    //  Chain<Movies, int, Link<global_table<32>, int>> publisheds;
};

struct hot_Format {};

struct Movies_Format {
    char d[4];
    static constexpr auto ITEMS_COUNT = 50ull;
    static constexpr auto NODES_COUNT = 4ull;
    Link<Movies, int[40], long> watched;

    // Link<Chain<int, int, hot>,Users> watched;
    // Link<Chain<int, int, hot>,7,Users> wathed;
    // Chain<int, int, hot> watched;
};
Table<hot_Format> k;

// #include <typeinfo>
int main(int, char **) {
    int i = 1025, j, k, l, m;

    std::cout << Movies.info().node_id.last << '\n'
              << hot.info().node_id.last << '\n'
              << Users.info().node_id.last << '\n'
              << Movies.info().node_id.last << '\n';
}