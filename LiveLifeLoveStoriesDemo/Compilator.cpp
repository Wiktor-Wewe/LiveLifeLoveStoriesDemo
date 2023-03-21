#include "Compilator.h"

void Compilator::compile(std::fstream* file, std::string fileName)
{
	this->_loadFileToMemory(file);
    this->_writeMemoryToFile(fileName);
}

void Compilator::_loadFileToMemory(std::fstream* file)
{
	std::string line;
    
    std::cout << "try to handle info of script" << std::endl;
    
    std::getline(*file, line);
    this->_loadName(line);

    std::getline(*file, line);
    this->_loadInfo(line);

    std::getline(*file, line);
    this->_loadAuthor(line);

    std::getline(*file, line);
    this->_loadDate(line);

    std::cout << "name: " << this->_name << std::endl;
    std::cout << "info: " << this->_info << std::endl;
    std::cout << "author: " << this->_author << std::endl;
    std::cout << "date: " << this->_date << std::endl;
    std::cout << std::endl;


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
            std::cout << "try to handle mpe header" << std::endl;
            this->_loadMPE(file);
            break;
        case 6: // message
            std::cout << "try to handle message header" << std::endl;
            this->_loadMessage(file);
            break;
        case 7: // music
            std::cout << "try to handle music header" << std::endl;
            this->_loadMusic(file);
            break;
        case 8: // sfx
            std::cout << "try to handle sfx header" << std::endl;
            this->_loadSfx(file);
            break;
        default:
            //std::cout << "skipped line: " << line << std::endl;
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

void Compilator::_loadName(std::string line)
{
    this->_name = this->_readText(line);
}

void Compilator::_loadInfo(std::string line)
{
    this->_info = this->_readText(line);
}

void Compilator::_loadAuthor(std::string line)
{
    this->_author = this->_readText(line);
}

void Compilator::_loadDate(std::string line)
{
    this->_date = this->_readText(line);
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

void Compilator::_loadMPE(std::fstream* file)
{
    std::string line;

    int id;
    std::string name;
    std::string text;
    std::vector<std::vector<std::string>> faces;
    std::vector<std::vector<std::string>> skins;
    std::vector<std::vector<std::string>> hairs;
    int nextmessageid;

    std::getline(*file, line);
    id = this->_readId(line);
    
    std::getline(*file, line);
    name = this->_readText(line);

    std::getline(*file, line);
    text = this->_readText(line);

    std::getline(*file, line);
    faces = this->_readDoubleVectorText(file);

    std::getline(*file, line);
    skins = this->_readDoubleVectorText(file);

    std::getline(*file, line);
    hairs = this->_readDoubleVectorText(file);

    std::getline(*file, line);
    nextmessageid = this->_readId(line);

    this->_MPEvent = new MakeProtagonistEvent(id, name, text, faces, skins, hairs, nextmessageid);
}

void Compilator::_loadMessage(std::fstream* file)
{
    std::string line;

    int id;
    std::string text;
    std::vector<int> musicid;
    std::vector<int> sfxid;
    int spriteid;
    int clothesid;
    int bgimageid;
    int nextmessage;
    int nextevent;

    std::getline(*file, line);
    id = this->_readId(line);

    std::getline(*file, line);
    text = this->_readText(line);

    std::getline(*file, line);
    musicid = this->_readVectorInt(line);
    
    std::getline(*file, line);
    sfxid = this->_readVectorInt(line);

    std::getline(*file, line);
    spriteid = this->_readId(line);

    std::getline(*file, line);
    clothesid = this->_readId(line);

    std::getline(*file, line);
    bgimageid = this->_readId(line);

    std::getline(*file, line);
    nextmessage = this->_readId(line);

    std::getline(*file, line);
    nextevent = this->_readId(line);

    this->_Messages.push_back(Message(id, text, musicid, sfxid, spriteid, clothesid, bgimageid, nextmessage, nextevent));
}

void Compilator::_loadMusic(std::fstream* file)
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

    this->_Musics.push_back(Music(id, name, path));
}

void Compilator::_loadSfx(std::fstream* file)
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
    path = this->_readText(path);

    this->_Sfxs.push_back(Sfx(id, name, path));
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

void Compilator::_writeMemoryToFile(std::string FileName)
{
    std::fstream compiledFile(this->_makeNewName(FileName), std::ios::out | std::ios::binary);
    short sNULL = 0x0000;
    double sizeOfFile = 0x00000000;

    // write header
    compiledFile.write(reinterpret_cast<const char*>("wewescriptcompiled"), 0x12); // type
    compiledFile.write(reinterpret_cast<const char*>(&sNULL), sizeof(short)); // just NULL
    compiledFile.write(reinterpret_cast<const char*>(&sizeOfFile), sizeof(double)); // for size of file
    
    this->_writeFileInfo(&compiledFile);
    this->_writeCharacters(&compiledFile);
    // _write cce
    // _write events
    // _write images
    // _write mpe
    // _write messages
    // _write musics
    // _write sfx
    // _write compilation info/
    // write end of file
    // overwrite size of file
    compiledFile.close();
    std::cout << "compilation complete" << std::endl;
    std::cout << "file: " << this->_makeNewName(FileName) << " was created" << std::endl;
}

std::string Compilator::_makeNewName(std::string fileName)
{
    std::string newName;

    if (fileName.size() > 4) {
        if (fileName[fileName.size() - 1] == 's' &&
            fileName[fileName.size() - 2] == 'e' &&
            fileName[fileName.size() - 3] == 'w' &&
            fileName[fileName.size() - 4] == '.'
        ) {
            return fileName + 'c';
        }
    }

    for (int i = 0; i < fileName.size(); i++) {
        if (i == fileName.find_last_of('.')) {
            return newName + ".wesc";
        }
        newName += fileName[i];
    }
}

void Compilator::_writeFileInfo(std::fstream* file)
{
    short ffff = 0xffff;
    int sizeOfName = this->_name.size();
    int sizeOfInfo = this->_info.size();
    int sizeOfAuthor = this->_author.size();
    int sizeOfDate = this->_date.size();

    file->write(reinterpret_cast<const char*>(&sizeOfName), sizeof(int));
    file->write(this->_name.c_str(), this->_name.size());

    file->write(reinterpret_cast<const char*>(&sizeOfInfo), sizeof(int));
    file->write(this->_info.c_str(), this->_info.size());

    file->write(reinterpret_cast<const char*>(&sizeOfAuthor), sizeof(int));
    file->write(this->_author.c_str(), this->_author.size());

    file->write(reinterpret_cast<const char*>(&sizeOfDate), sizeof(sizeOfDate));
    file->write(this->_date.c_str(), this->_date.size());

    file->write(reinterpret_cast<const char*>(&ffff), sizeof(short));
}

void Compilator::_writeCharacters(std::fstream* file)
{

}
