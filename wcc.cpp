#include <cxxopts.hpp>
#include <iostream>
#include <fstream>

int count_bytes(std::ifstream* file) {
    int count = 0;
    std::string line;
    while (std::getline(*file, line)) {
        count += line.size() + 1;
    }
    return count;
}


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

    std::ifstream InputFile(filepath);
    int character_count = count_bytes(&InputFile);
    InputFile.close();

    std::cout << character_count << std::endl;
    
}