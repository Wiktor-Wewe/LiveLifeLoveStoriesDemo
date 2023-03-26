#include <iostream>
#include "Story.h"
#include <fstream>
#include "Compilator.h"

bool isNameWes(std::string name) {
    if (name.size() > 4) {
        if (name[name.size() - 1] == 's' &&
            name[name.size() - 2] == 'e' &&
            name[name.size() - 3] == 'w' &&
            name[name.size() - 4] == '.'
            ) {
            return true;
        }
    }
    return false;
}

bool isNameWesc(std::string name) {
    if (name.size() > 5) {
        if (name[name.size() - 1] == 'c' &&
            name[name.size() - 2] == 's' &&
            name[name.size() - 3] == 'e' &&
            name[name.size() - 4] == 'w' &&
            name[name.size() - 5] == '.'
            ) {
            return true;
        }
    }
    return false;
}

void play(std::string fileName) {
    std::fstream file;
    file.open(fileName, std::ios::in);
    if (!file.good()) {
        std::cout << "error file" << std::endl;
        return;
    }

    Story s1 = Story();
    if (s1.loadStory(&file) == 0) {
        std::cout << "loadind complete" << std::endl;
        s1.play();
    }
    else {
        std::cout << "someting went wrong" << std::endl;
    }
}

void compile(std::string fileName) {
    std::fstream file;
    file.open(fileName, std::ios::in);
    if (!file.good()) {
        std::cout << "error file" << std::endl;
        return;
    }

    Compilator c;
    c.compile(&file, fileName);
}

int main(int argc, char* argv[])
{
    if (argc < 2) {
        std::cout << "Usage: " << std::endl;
        std::cout << "LiveLifeLoveStoriesDemo rawScript.wes - compile and make script.wesc" << std::endl;
        std::cout << "LiveLifeLoveStoriesDemo -f rawScript.* - force compile and make script.wesc" << std::endl;
        std::cout << "LiveLifeLoveStoriesDemo script.wesc - play story" << std::endl;
        std::cout << "LiveLifeLoveStoriesDemo -p script.* - force play story" << std::endl;
        return 0;
    }

    if (argv[1] == "-f") {
        compile(argv[2]);
    }

    if (argv[1] == "-p") {
        play(argv[2]);
    }

    if (isNameWes(argv[1])) {
        compile(argv[1]);
    }

    if (isNameWesc(argv[1])) {
        play(argv[1]);
    }

    return 0;
}