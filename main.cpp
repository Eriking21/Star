// #pragma once
#include "iostream"
#include "star.hpp"
mk_tables(Users, Movies);

struct Users_Format {
  Chain<Movies, int, Link<global_table<32>, int>> watcheds;
  //Chain<Movies, int, Link<global_table<32>, int>> publisheds;

};

struct Movies_Format {
  Chain<Users, int, Link<global_table<32>, int>> watchers;
};

int main(int, char **) { std::cout << "erim\n"; }
