#include <cxxopts.hpp>
#include <iostream>
#include <fstream>


int wc(std::ifstream* file) {
    return 0;
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
    int character_count = wc(&InputFile);
    InputFile.close();

    std::cout << character_count << std::endl;
    
}