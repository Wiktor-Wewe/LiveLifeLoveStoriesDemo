#include <iostream>
#include "Story.h"
#include <fstream>

int main(int argc, char* argv[])
{
    if (argc < 2) {
        std::cout << "Usage: " << std::endl;
        std::cout << "LiveLifeLoveStoriesDemo [script file]" << std::endl;
        return 0;
    }

    std::fstream file;
    file.open(argv[1], std::ios::in);
    if (!file.good()) {
        std::cout << "error file" << std::endl;
    }

    Story s1 = Story();
    if (s1.loadStoryFake(&file) == 0) {
        std::cout << "loadind complete" << std::endl;
        s1.play();
    }
    else {
        std::cout << "someting went wrong" << std::endl;
    }

    return 0;
}