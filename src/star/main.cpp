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
    static constexpr auto entries_count = 50ull;
    static constexpr auto links_count = 4ull;
    Link<Movies, int[40],long> watched;

    // Link<Chain<int, int, hot>,Users> watched;
    // Link<Chain<int, int, hot>,7,Users> wathed;
    // Chain<int, int, hot> watched;
};

//#include <typeinfo>
int main(int, char **) { std::cout << (char*)Movies.ptr; }