#include "Compilator.h"

void Compilator::compile(std::fstream* file, std::string fileName)
{
	this->_loadFileToMemory(file);
    this->_writeMemoryToFile(fileName);
}

void Compilator::_loadFileToMemory(std::fstream* file)
{
	std::string line;
    
    std::cout << "script info:\n\n";
    
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
            //std::cout << "try to handle character header" << std::endl;
            this->_loadCharacter(file);
            break;
        case 2: // cce
            //std::cout << "try to handle cce header" << std::endl;
            this->_loadCCE(file);
            break;
        case 3: // event
            //std::cout << "try to handle event header" << std::endl;
            this->_loadEvent(file);
            break;
        case 4: // image
            //std::cout << "try to handle image header" << std::endl;
            this->_loadImage(file);
            break;
        case 5: // mpe
            //std::cout << "try to handle mpe header" << std::endl;
            this->_loadMPE(file);
            break;
        case 6: // message
            //std::cout << "try to handle message header" << std::endl;
            this->_loadMessage(file);
            break;
        case 7: // music
            //std::cout << "try to handle music header" << std::endl;
            this->_loadMusic(file);
            break;
        case 8: // sfx
            //std::cout << "try to handle sfx header" << std::endl;
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
    path = this->_readText(line);

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
    int sizeOfFile = 0x0000;

    // write header
    compiledFile.write(reinterpret_cast<const char*>("wewescriptcompiled"), 0x12); // type
    compiledFile.write(reinterpret_cast<const char*>(&sNULL), sizeof(short)); // just NULL
    compiledFile.write(reinterpret_cast<const char*>(&sizeOfFile), sizeof(int)); // for size of file
    
    this->_writeFileInfo(&compiledFile);
    this->_writeCharacters(&compiledFile);
    this->_writeCCE(&compiledFile);
    this->_writeEvents(&compiledFile);
    this->_writeImages(&compiledFile);
    this->_writeMPE(&compiledFile);
    this->_writeMessages(&compiledFile);
    this->_writeMusics(&compiledFile);
    this->_writeSfx(&compiledFile);
    this->_writeCompilationInfo(&compiledFile);
    this->_overwriteSizeOfFile(&compiledFile);
    compiledFile.close();
    std::cout << "compilation complete" << std::endl;
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

    file->write(reinterpret_cast<const char*>(&sizeOfDate), sizeof(int));
    file->write(this->_date.c_str(), this->_date.size());

    file->write(reinterpret_cast<const char*>(&ffff), sizeof(short));
}

void Compilator::_writeCharacters(std::fstream* file)
{
    short characterHeader = 0x0001;
    short numberOfCharacters = this->_Characters.size();
    short buff;

    // write characters header
    file->write(reinterpret_cast<const char*>(&characterHeader), sizeof(short));
    
    // write number of characters
    file->write(reinterpret_cast<const char*>(&numberOfCharacters), sizeof(short));

    for (int i = 0; i < this->_Characters.size(); i++) {
        // write id
        buff = this->_Characters[i].getId();
        file->write(reinterpret_cast<const char*>(&buff), sizeof(short));
        // write size of name and name
        buff = this->_Characters[i].getName().size();
        file->write(reinterpret_cast<const char*>(&buff), sizeof(short));
        file->write(this->_Characters[i].getName().c_str(), this->_Characters[i].getName().size());
        // write number of spirites
        buff = this->_Characters[i].getSprites().size();
        file->write(reinterpret_cast<const char*>(&buff), sizeof(short));
        // write all size of path and path
        for (int j = 0; j < this->_Characters[i].getSprites().size(); j++) {
            buff = this->_Characters[i].getSprites()[j].size();
            file->write(reinterpret_cast<const char*>(&buff), sizeof(short));
            file->write(this->_Characters[i].getSprites()[j].c_str(), this->_Characters[i].getSprites()[j].size());
        }
    }
}

void Compilator::_writeCCE(std::fstream* file)
{
    short CCEHeader = 0x0002;
    short numberOfCCE = this->_CCEvents.size();
    short buff;

    // write cce header
    file->write(reinterpret_cast<const char*>(&CCEHeader), sizeof(short));

    // write number of cce
    file->write(reinterpret_cast<const char*>(&numberOfCCE), sizeof(short));

    for (int i = 0; i < this->_CCEvents.size(); i++) {
        // write id
        buff = this->_CCEvents[i].getId();
        file->write(reinterpret_cast<const char*>(&buff), sizeof(short));
        // write size of text and text
        buff = this->_CCEvents[i].getText().size();
        file->write(reinterpret_cast<const char*>(&buff), sizeof(short));
        file->write(this->_CCEvents[i].getText().c_str(), this->_CCEvents[i].getText().size());
        // write number of vectors y
        buff = this->_CCEvents[i].getClothes().size();
        file->write(reinterpret_cast<const char*>(&buff), sizeof(short));
        // write info from vectors y
        for (int j = 0; j < this->_CCEvents[i].getClothes().size(); j++) {
            // write number of vectors x
            buff = this->_CCEvents[i].getClothes()[j].size();
            file->write(reinterpret_cast<const char*>(&buff), sizeof(short));
            // write info from vectors x
            for (int k = 0; k < this->_CCEvents[i].getClothes()[j].size(); k++) {
                // write size of paths and paths
                buff = this->_CCEvents[i].getClothes()[j][k].size();
                file->write(reinterpret_cast<const char*>(&buff), sizeof(short));
                file->write(this->_CCEvents[i].getClothes()[j][k].c_str(), this->_CCEvents[i].getClothes()[j][k].size());
            }
        }
        // write next message id
        buff = this->_CCEvents[i].getNextMessageId();
        file->write(reinterpret_cast<const char*>(&buff), sizeof(short));
    }
}

void Compilator::_writeEvents(std::fstream* file)
{
    short EventHeader = 0x0003;
    short numberOfEvents = this->_Events.size();
    short buff;

    // write events header
    file->write(reinterpret_cast<const char*>(&EventHeader), sizeof(short));

    // write number of events
    file->write(reinterpret_cast<const char*>(&numberOfEvents), sizeof(short));

    for (int i = 0; i < this->_Events.size(); i++) {
        // write id
        buff = this->_Events[i].getId();
        file->write(reinterpret_cast<const char*>(&buff), sizeof(short));

        // write number of player options
        buff = this->_Events[i].getPlayerOptions().size();
        file->write(reinterpret_cast<const char*>(&buff), sizeof(short));

        // write all player options
        for (int j = 0; j < this->_Events[i].getPlayerOptions().size(); j++) {
            // write size of player option and player option
            buff = this->_Events[i].getPlayerOptions()[j].size();
            file->write(reinterpret_cast<const char*>(&buff), sizeof(short));
            file->write(this->_Events[i].getPlayerOptions()[j].c_str(), this->_Events[i].getPlayerOptions()[j].size());
        }

        // write number of next messages
        buff = this->_Events[i].getNextMessages().size();
        file->write(reinterpret_cast<const char*>(&buff), sizeof(short));

        // write all next messages
        for (int j = 0; j < this->_Events[i].getNextMessages().size(); j++) {
            // write next message id
            buff = this->_Events[i].getNextMessages()[j];
            file->write(reinterpret_cast<const char*>(&buff), sizeof(short));
        }

        // write number of next events
        buff = this->_Events[i].getNextEvents().size();
        file->write(reinterpret_cast<const char*>(&buff), sizeof(short));

        // write all next events
        for (int j = 0; j < this->_Events[i].getNextEvents().size(); j++) {
            // write next event id
            buff = this->_Events[i].getNextEvents()[j];
            file->write(reinterpret_cast<const char*>(&buff), sizeof(short));
        }

        // write mpei
        buff = this->_Events[i].getMpei();
        file->write(reinterpret_cast<const char*>(&buff), sizeof(short));

        // write ccei
        buff = this->_Events[i].getCcei();
        file->write(reinterpret_cast<const char*>(&buff), sizeof(short));
    }
}

void Compilator::_writeImages(std::fstream* file)
{
    short EventHeader = 0x0004;
    short numberOfImages = this->_Images.size();
    short buff;

    // write images header
    file->write(reinterpret_cast<const char*>(&EventHeader), sizeof(short));

    // write number of events
    file->write(reinterpret_cast<const char*>(&numberOfImages), sizeof(short));

    for (int i = 0; i < this->_Images.size(); i++) {
        // write id
        buff = this->_Images[i].getId();
        file->write(reinterpret_cast<const char*>(&buff), sizeof(short));

        // size of name and name
        buff = this->_Images[i].getName().size();
        file->write(reinterpret_cast<const char*>(&buff), sizeof(short));
        file->write(this->_Images[i].getName().c_str(), this->_Images[i].getName().size());

        // size of path and path
        buff = this->_Images[i].getPath().size();
        file->write(reinterpret_cast<const char*>(&buff), sizeof(short));
        file->write(this->_Images[i].getPath().c_str(), this->_Images[i].getPath().size());
    }
}

void Compilator::_writeMPE(std::fstream* file)
{
    short EventHeader = 0x0005;
    short buff;

    // write MPE header
    file->write(reinterpret_cast<const char*>(&EventHeader), sizeof(short));

    // write id
    buff = this->_MPEvent->getId();
    file->write(reinterpret_cast<const char*>(&buff), sizeof(short));

    // write size of name and name
    buff = this->_MPEvent->getName().size();
    file->write(reinterpret_cast<const char*>(&buff), sizeof(short));
    file->write(this->_MPEvent->getName().c_str(), this->_MPEvent->getName().size());

    // write size of text and text
    buff = this->_MPEvent->getText().size();
    file->write(reinterpret_cast<const char*>(&buff), sizeof(short));
    file->write(this->_MPEvent->getText().c_str(), this->_MPEvent->getText().size());

    // write size of faces vector Y
    buff = this->_MPEvent->getFaces().size();
    file->write(reinterpret_cast<const char*>(&buff), sizeof(short));

    // write content of faces vector Y 
    for (int i = 0; i < this->_MPEvent->getFaces().size(); i++) {
        // write size of faces vector X
        buff = this->_MPEvent->getFaces()[i].size();
        file->write(reinterpret_cast<const char*>(&buff), sizeof(short));

        // write content of faces vector X
        for (int j = 0; j < this->_MPEvent->getFaces()[i].size(); j++) {
            // write size of face and face 
            buff = this->_MPEvent->getFaces()[i][j].size();
            file->write(reinterpret_cast<const char*>(&buff), sizeof(short));
            file->write(this->_MPEvent->getFaces()[i][j].c_str(), this->_MPEvent->getFaces()[i][j].size());
        }
    }

    // write size of skins vector Y
    buff = this->_MPEvent->getSkins().size();
    file->write(reinterpret_cast<const char*>(&buff), sizeof(short));

    // write content of skins vector Y 
    for (int i = 0; i < this->_MPEvent->getSkins().size(); i++) {
        // write size of skins vector X
        buff = this->_MPEvent->getSkins()[i].size();
        file->write(reinterpret_cast<const char*>(&buff), sizeof(short));

        // write content of skins vector X
        for (int j = 0; j < this->_MPEvent->getSkins()[i].size(); j++) {
            // write size of skin and skin
            buff = this->_MPEvent->getSkins()[i][j].size();
            file->write(reinterpret_cast<const char*>(&buff), sizeof(short));
            file->write(this->_MPEvent->getSkins()[i][j].c_str(), this->_MPEvent->getSkins()[i][j].size());
        }
    }

    // write size of hairs vector Y
    buff = this->_MPEvent->getHairs().size();
    file->write(reinterpret_cast<const char*>(&buff), sizeof(short));

    // write content of hairs vector Y 
    for (int i = 0; i < this->_MPEvent->getHairs().size(); i++) {
        // write size of hairs vector X
        buff = this->_MPEvent->getHairs()[i].size();
        file->write(reinterpret_cast<const char*>(&buff), sizeof(short));

        // write content of hairs vector X
        for (int j = 0; j < this->_MPEvent->getHairs()[i].size(); j++) {
            // write size of skin and skin
            buff = this->_MPEvent->getHairs()[i][j].size();
            file->write(reinterpret_cast<const char*>(&buff), sizeof(short));
            file->write(this->_MPEvent->getHairs()[i][j].c_str(), this->_MPEvent->getHairs()[i][j].size());
        }
    }

    // write next message id
    buff = this->_MPEvent->getNextMessageId();
    file->write(reinterpret_cast<const char*>(&buff), sizeof(short));
}

void Compilator::_writeMessages(std::fstream* file)
{
    short EventHeader = 0x0006;
    short numberOfMessages = this->_Messages.size();
    short buff;

    // write messages header
    file->write(reinterpret_cast<const char*>(&EventHeader), sizeof(short));

    // write number of messages
    file->write(reinterpret_cast<const char*>(&numberOfMessages), sizeof(short));

    for (int i = 0; i < this->_Messages.size(); i++) {
        // write id
        buff = this->_Messages[i].getId();
        file->write(reinterpret_cast<const char*>(&buff), sizeof(short));

        // write size of text and text
        buff = this->_Messages[i].getText().size();
        file->write(reinterpret_cast<const char*>(&buff), sizeof(short));
        file->write(this->_Messages[i].getText().c_str(), this->_Messages[i].getText().size());

        // write number of music id and all music id
        buff = this->_Messages[i].getAllMusicId().size();
        file->write(reinterpret_cast<const char*>(&buff), sizeof(short));
        
        for (int j = 0; j < this->_Messages[i].getAllMusicId().size(); j++) {
            buff = this->_Messages[i].getAllMusicId()[j];
            file->write(reinterpret_cast<const char*>(&buff), sizeof(short));
        }

        // write number of sfx id and all sfx id
        buff = this->_Messages[i].getAllSfxId().size();
        file->write(reinterpret_cast<const char*>(&buff), sizeof(short));

        for (int j = 0; j < this->_Messages[i].getAllSfxId().size(); j++) {
            buff = this->_Messages[i].getAllSfxId()[j];
            file->write(reinterpret_cast<const char*>(&buff), sizeof(short));
        }

        // write sprite id
        buff = this->_Messages[i].getSpriteId();
        file->write(reinterpret_cast<const char*>(&buff), sizeof(short));

        // write clothes id
        buff = this->_Messages[i].getClothesId();
        file->write(reinterpret_cast<const char*>(&buff), sizeof(short));

        // write bg image id
        buff = this->_Messages[i].getBgImageId();
        file->write(reinterpret_cast<const char*>(&buff), sizeof(short));

        // write next message id
        buff = this->_Messages[i].getNextMessage();
        file->write(reinterpret_cast<const char*>(&buff), sizeof(short));

        // write next event id
        buff = this->_Messages[i].getNextEvent();
        file->write(reinterpret_cast<const char*>(&buff), sizeof(short));
    }
}

void Compilator::_writeMusics(std::fstream* file)
{
    short EventHeader = 0x0007;
    short numberOfMusics = this->_Musics.size();
    short buff;

    // write musics header
    file->write(reinterpret_cast<const char*>(&EventHeader), sizeof(short));

    // write number of musics
    file->write(reinterpret_cast<const char*>(&numberOfMusics), sizeof(short));

    for (int i = 0; i < this->_Musics.size(); i++) {
        // write id
        buff = this->_Musics[i].getId();
        file->write(reinterpret_cast<const char*>(&buff), sizeof(short));

        // write size of name and name
        buff = this->_Musics[i].getName().size();
        file->write(reinterpret_cast<const char*>(&buff), sizeof(short));
        file->write(this->_Musics[i].getName().c_str(), this->_Musics[i].getName().size());

        // write size of path and path
        buff = this->_Musics[i].getPath().size();
        file->write(reinterpret_cast<const char*>(&buff), sizeof(short));
        file->write(this->_Musics[i].getPath().c_str(), this->_Musics[i].getPath().size());
    }
}

void Compilator::_writeSfx(std::fstream* file)
{
    short EventHeader = 0x0008;
    short numberOfSfx = this->_Sfxs.size();
    short buff;

    // write musics header
    file->write(reinterpret_cast<const char*>(&EventHeader), sizeof(short));

    // write number of musics
    file->write(reinterpret_cast<const char*>(&numberOfSfx), sizeof(short));

    for (int i = 0; i < this->_Sfxs.size(); i++) {
        // write id
        buff = this->_Sfxs[i].getId();
        file->write(reinterpret_cast<const char*>(&buff), sizeof(short));

        // write size of name and name
        buff = this->_Sfxs[i].getName().size();
        file->write(reinterpret_cast<const char*>(&buff), sizeof(short));
        file->write(this->_Sfxs[i].getName().c_str(), this->_Sfxs[i].getName().size());

        // write size of path and path
        buff = this->_Sfxs[i].getPath().size();
        file->write(reinterpret_cast<const char*>(&buff), sizeof(short));
        file->write(this->_Sfxs[i].getPath().c_str(), this->_Sfxs[i].getPath().size());
    }
}

void Compilator::_writeCompilationInfo(std::fstream* file)
{
    // write day and time
    std::string dayTimeInfo = "Day and time: ";
    file->write(dayTimeInfo.c_str(), dayTimeInfo.size());

    // get current day and time
    time_t rawtime;
    struct tm timeinfo;
    char timeToWrite[80];

    std::time(&rawtime);
    localtime_s(&timeinfo, &rawtime);

    std::strftime(timeToWrite, sizeof(timeToWrite), "%d-%m-%Y %I:%M:%S", &timeinfo);
    
    // write current day and time to file
    file->write(timeToWrite, 19);

    // write user info
    std::string userInfo = "User info: ";
    file->write(userInfo.c_str(), userInfo.size());

    // get current user and write or default
    std::string defaultUser = "DefaultUser???";
    char* user_name = nullptr;
    size_t len;
    errno_t err = _dupenv_s(&user_name, &len, "USERNAME");
    if (err == 0 && user_name != nullptr) {
        file->write(user_name, len);
    }
    else {
        file->write(defaultUser.c_str(), defaultUser.size());
    }

    // write compilator and engine info
    std::string compilatorAndEngineInfo = "Compilator: 1.0v, Engine: 1.0v, Developer Test";
    file->write(compilatorAndEngineInfo.c_str(), compilatorAndEngineInfo.size());

    // write end of file
    int end = 0x00ff00ff;
    file->write(reinterpret_cast<const char*>(&end), sizeof(int));
}

void Compilator::_overwriteSizeOfFile(std::fstream* file)
{
    int sizeOfFile = file->tellp();
    file->seekp(0x14);
    file->write(reinterpret_cast<const char*>(&sizeOfFile), sizeof(int));
}
