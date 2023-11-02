#include <iostream>
#include <fstream>


int count_bytes(std::string filepath) {
    int count = 0;
    std::ifstream InputFile(filepath);
    std::string line;
    while (std::getline(InputFile, line)) {
        count += line.size() + 1;
    }
    InputFile.close();
    return count;
}
