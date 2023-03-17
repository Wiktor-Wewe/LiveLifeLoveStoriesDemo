#include "Compilator.h"

void Compilator::compile(std::fstream* file)
{
	this->_loadFileToMemmory(file);
}

void Compilator::_loadFileToMemmory(std::fstream* file)
{
	std::string line;

    while (!file->eof()) {
        std::getline(*file, line);
        int header = this->_findHeader(line);
        switch (header) {
        case 1: // character
            std::cout << "try to handle character header" << std::endl;
            this->_loadCharacter(file);
            break;
        case 2: // cce
            std::cout << "try to handle cce header" << std::endl;
            this->_loadCCE(file);
            break;
        case 3: // event
            std::cout << "try to handle event header" << std::endl;
            this->_loadEvent(file);
            break;
        case 4: // image
            std::cout << "try to handle image header" << std::endl;
            this->_loadImage(file);
            break;
        case 5: // mpe
            break;
        case 6: // message
            break;
        case 7: // music
            break;
        case 8: // sfx
            break;
        default:
            std::cout << "skipped line: " << line << std::endl;
            break;
        }
    }
	

}

int Compilator::_findHeader(std::string line)
{
    if (line.find("<character>") != std::string::npos) return 1;
    if (line.find("<cce>") != std::string::npos) return 2;
    if (line.find("<event>") != std::string::npos) return 3;
    if (line.find("<image>") != std::string::npos) return 4;
    if (line.find("<mpe>") != std::string::npos) return 5;
    if (line.find("<message>") != std::string::npos) return 6;
    if (line.find("<music>") != std::string::npos) return 7;
    if (line.find("<sfx>") != std::string::npos) return 8;

	return 0;
}

void Compilator::_loadCharacter(std::fstream* file)
{
    std::string line;

    int id;
    std::string name;
    std::vector<std::string> sprites;

    std::getline(*file, line);
    id = this->_readId(line);
    
    std::getline(*file, line);
    name = this->_readText(line);

    std::getline(*file, line);
    sprites = this->_readVectorText(line);

    this->_Characters.push_back(Character(id, name, sprites));
}

void Compilator::_loadCCE(std::fstream* file)
{
    std::string line;

    int id;
    std::string text;
    std::vector<std::vector<std::string>> clothes;
    int nextMessageId;

    std::getline(*file, line);
    id = this->_readId(line);

    std::getline(*file, line);
    text = this->_readText(line);

    std::getline(*file, line);
    clothes = this->_readDoubleVectorText(file);

    std::getline(*file, line);
    nextMessageId = this->_readId(line);

    this->_CCEvents.push_back(ChooseClothesEvent(id, text, clothes, nextMessageId));
}

void Compilator::_loadEvent(std::fstream* file)
{
    std::string line;

    int id;
    std::vector<std::string> playerOptions;
    std::vector<int> nextMessages;
    std::vector<int> nextEvents;
    int mpeid;
    int cceid;

    std::getline(*file, line);
    id = this->_readId(line);

    std::getline(*file, line);
    playerOptions = this->_readVectorText(line);

    std::getline(*file, line);
    nextMessages = this->_readVectorInt(line);

    std::getline(*file, line);
    nextEvents = this->_readVectorInt(line);

    std::getline(*file, line);
    mpeid = this->_readId(line);

    std::getline(*file, line);
    cceid = this->_readId(line);

    this->_Events.push_back(Event(id, playerOptions, nextMessages, nextEvents, mpeid, cceid));
}

void Compilator::_loadImage(std::fstream* file)
{
    std::string line;

    int id;
    std::string name;
    std::string path;

    std::getline(*file, line);
    id = this->_readId(line);

    std::getline(*file, line);
    name = this->_readText(line);

    std::getline(*file, line);
    path = this->_readText(line);

    this->_Images.push_back(Image(id, name, path));
}

int Compilator::_readId(std::string line)
{
    line = this->cutString(line, line.find(":")+1, line.size()-1);
    return std::stoi(line);
}

std::string Compilator::_readText(std::string line)
{
    line = this->cutString(line, line.find("\"")+1, line.size() - 2);
    return line;
}

std::vector<int> Compilator::_readVectorInt(std::string line)
{
    std::vector<int> list;
    std::string s;
    int l;

    line = this->cutString(line, line.find(":") + 1, line.size());
    for (int i = 0; i < line.size(); i++) {
        if (line[i] != ' ' && line[i] != ',' && line[i] != ';') {
            s += line[i];
        }

        if (line[i] == ',' || line[i] == ';') {
            l = std::stoi(s);
            list.push_back(l);
            s.clear();
        }
    }

    return list;
}

std::vector<std::string> Compilator::_readVectorText(std::string line)
{
    std::vector<std::string> list;
    std::string buff;
    int quote = 0;

    line = this->cutString(line, line.find("\""), line.size());

    for (int i = 0; i < line.size(); i++) {
        if (line[i] == '"') {
            quote++;
        }
        if (quote % 2 == 1 && line[i] != '"') {
            buff += line[i];
        }
        if (line[i] == ',' || line[i] == ';') {
            list.push_back(buff);
            buff.clear();
        }
    }

    return list;
}

std::vector<std::vector<std::string>> Compilator::_readDoubleVectorText(std::fstream* file)
{
    std::vector<std::vector<std::string>> list;
    std::vector<std::string> listOfPaths;
    std::string buff;

    std::getline(*file, buff);

    while (buff[0] != '}') {
        std::getline(*file, buff);
        if (buff[0] != '}') {
            listOfPaths = this->_readVectorText(buff);
            list.push_back(listOfPaths);
        }
    }

    return list;
}

std::string Compilator::cutString(std::string line, int start, int end)
{
    std::string result;
    for (int i = start; i < end; i++) {
        result += line[i];
    }
    return result;
}
