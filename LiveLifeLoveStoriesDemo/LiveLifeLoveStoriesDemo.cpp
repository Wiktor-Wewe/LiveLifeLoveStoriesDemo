#include <iostream>
#include "Story.h"
#include <fstream>

int main()
{
    std::fstream file;
    file.open("file.wewe", std::ios::in);
    if (!file.good()) {
        std::cout << "error file" << std::endl;
    }

    Story s1 = Story();
    if (s1.loadStory(&file) == 0) {
        std::cout << "loadind complete" << std::endl;
        s1.play();
    }
    else {
        std::cout << "someting went wrong" << std::endl;
    }

    return 0;
}