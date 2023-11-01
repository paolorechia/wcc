#include <cxxopts.hpp>
#include <iostream>
#include <fstream>
#include "count.h.in"

int main(int argc, char *argv[]) { 
    cxxopts::Options options("wcc", "Cheap copy of wc");
    options.add_options()
        ("f,file", "Input file", cxxopts::value<std::string>())
        ("c,character", "Count characters", cxxopts::value<bool>()->default_value("false"))
        ("h,help", "Display help");

    options.parse_positional({"file"});
    auto parsed = options.parse(argc, argv);

    if (parsed.count("help") || parsed.count("file") <= 0 || parsed.count("c") <= 0) {
        std::cout << options.help() << std::endl;
        exit(0);
    }
    auto filepath = parsed["file"].as<std::string>();

    int character_count = count_bytes(filepath);
    std::cout << character_count << std::endl;
    
}