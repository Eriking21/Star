// #pragma once
#include "iostream"
#include "table.hpp"
mk_tables(Users, Movies, hot);

// struct Users_Format {
//     Link<Movies, int[14]> watched;
//     // Chain<Movies, int, Link<global_table<32>, int>> watcheds;
//     // Chain<Movies, int, Link<global_table<32>, int>> publisheds;
// };

// struct hot_Format {
//     char d[100];
// };

// struct Movies_Format {
//     Link<Movies, int[4],long> watched;

//     // Link<Chain<int, int, hot>,Users> watched;
//     // Link<Chain<int, int, hot>,7,Users> wathed;
//     // Chain<int, int, hot> watched;
// };

struct s{
    char r[3];
};
int main(int, char **) { std::cout << sizeof(s); }
