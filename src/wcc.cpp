#include <iostream>
#include <fstream>
#include "count.h.in"
#include "opt_parser.h.in"

int main(int argc, char *argv[]) {
    auto filepath = parse_options(argc, argv);
    int character_count = count_bytes(filepath);
    std::cout << character_count << std::endl;
}