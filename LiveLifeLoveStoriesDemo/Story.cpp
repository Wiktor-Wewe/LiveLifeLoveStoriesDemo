#include "Story.h"

std::string Story::getName()
{
    return this->_name;
}

std::string Story::getInfo()
{
    return this->_info;
}

std::string Story::getAuthor()
{
    return this->_author;
}

std::string Story::getDate()
{
    return this->_date;
}

int Story::loadStory(std::fstream* file)
{
    short buff;

    if (!this->_isHeaderOkay(file)) {
        std::cout << "header error" << std::endl;
        return 1;
    }

    if (!this->_isSizeOkay(file)) {
        std::cout << "size error" << std::endl;
        return 2;
    }
        
    this->_loadGlobalInfo(file);
    std::cout << "name: " << this->_name << std::endl;
    std::cout << "info: " << this->_info << std::endl;
    std::cout << "author: " << this->_author << std::endl;
    std::cout << "date: " << this->_date << std::endl;
    std::cout << std::endl;

    this->_loadCharacters(file);
    this->_loadCCE(file);
    this->_loadEvents(file);
    this->_loadImages(file);
    this->_loadMPE(file);
    // load messages
    // load music
    // load sfx
    // load compilation info
    // check if end of file
    
    return 0;
}

int Story::loadStoryFake(std::fstream* file)
{
    //character wiktor
    std::vector<std::string> clothesWiktor;
    clothesWiktor.push_back("path1");
    clothesWiktor.push_back("path2");
    this->_Characters.push_back(Character(1, "Wiktor", clothesWiktor));

    //character kamil
    std::vector<std::string> clothesKamil;
    clothesKamil.push_back("path1");
    clothesKamil.push_back("path2");
    this->_Characters.push_back(Character(1, "Kamil", clothesKamil));

    //chooseClothesEvent
    std::vector<std::vector<std::string>> clothes;
    clothes.push_back(std::vector<std::string>()); 
    clothes.push_back(std::vector<std::string>()); 
    clothes[0].push_back("czerwona sukienka");
    clothes[0].push_back("dluga czerwona sukienka");
    clothes[1].push_back("czarna sukienka");
    clothes[1].push_back("dluga czarna sukienka");
    this->_CCEvents.push_back(ChooseClothesEvent(1, "Wybierz ciuchy", clothes, 1));

    //Events
    std::vector<std::string> playeroption1;
    playeroption1.push_back("Wiadomosc 1");
    playeroption1.push_back("Pokaz okno wyboru");
    playeroption1.push_back("Stworz postac");
    playeroption1.push_back("Wybierz ciuchy");

    std::vector<int> nextmessages;
    nextmessages.push_back(1);
    nextmessages.push_back(2);
    nextmessages.push_back(3);
    nextmessages.push_back(4);
    this->_Events.push_back(Event(1, playeroption1, nextmessages, std::vector<int>(), 0, 0));
    this->_Events.push_back(Event(2, std::vector<std::string>(), std::vector<int>(), std::vector<int>(), 1, 0));
    this->_Events.push_back(Event(3, std::vector<std::string>(), std::vector<int>(), std::vector<int>(), 0, 1));

    //Images
    this->_Images.push_back(Image(1, "placeholder1", "path1"));

    //MakeProtagonistEvent
    std::vector<std::vector<std::string>> faces;
    faces.push_back(std::vector<std::string>());
    faces.push_back(std::vector<std::string>());
    faces.push_back(std::vector<std::string>());
    faces[0].push_back("shape1 face1");
    faces[0].push_back("shape1 face2");
    faces[1].push_back("shape2 face1");
    faces[1].push_back("shape2 face2");
    faces[2].push_back("shape3 face1");
    faces[2].push_back("shape3 face2");

    std::vector<std::vector<std::string>> skins;
    skins.push_back(std::vector<std::string>());
    skins.push_back(std::vector<std::string>());
    skins.push_back(std::vector<std::string>());
    skins[0].push_back("black skin1");
    skins[0].push_back("black skin2");
    skins[1].push_back("white skin1");
    skins[1].push_back("white skin2");
    skins[2].push_back("yellow skin1");
    skins[2].push_back("yellow skin2");

    std::vector<std::vector<std::string>> hairs;
    hairs.push_back(std::vector<std::string>());
    hairs.push_back(std::vector<std::string>());
    hairs.push_back(std::vector<std::string>());
    hairs[0].push_back("black hairs1");
    hairs[0].push_back("black hairs2");
    hairs[1].push_back("yellow hairs1");
    hairs[1].push_back("yellow hairs2");
    hairs[2].push_back("brown hairs1");
    hairs[2].push_back("brown hairs2");

    this->_MPEvent = new MakeProtagonistEvent(1, "Pierwszy test", "Wybierz ciuszka", faces, skins, hairs, 1);

    //messages
    std::vector<int> musicId;
    musicId.push_back(1);
    musicId.push_back(2);

    std::vector<int> sfxId;
    sfxId.push_back(1);
    sfxId.push_back(3);

    Message m1 = Message(1, "Wiadomosc 1", musicId, sfxId, 1, 2, 1, 2, 0);
    Message m2 = Message(2, "Wiadomosc 2 - zaraz zobaczysz okno wyboru", musicId, sfxId, 2, 1, 2, 0, 1);
    Message m3 = Message(3, "Wiadomosc 3 - zaraz zobaczysz keator postaci", musicId, sfxId, 3, 2, 1, 0, 2);
    Message m4 = Message(4, "Wiadomosc 4 - zaraz zobaczysz wybor ciuchow", musicId, sfxId, 3, 2, 1, 0, 3);
    this->_Messages.push_back(m1);
    this->_Messages.push_back(m2);
    this->_Messages.push_back(m3);
    this->_Messages.push_back(m4);

    //Music
    Music music1 = Music(1, "Music 1", "Path1");
    Music music2 = Music(2, "Music 2", "Path2");
    Music music3 = Music(3, "Music 3", "Path3");
    this->_Musics.push_back(music1);
    this->_Musics.push_back(music2);
    this->_Musics.push_back(music3);

    //Protagonist
    this->_Player = new Protagonist();

    //Sfx
    Sfx sfx1 = Sfx(1, "sfx 1", "path 1");
    Sfx sfx2 = Sfx(2, "sfx 2", "path 2");
    Sfx sfx3 = Sfx(3, "sfx 3", "path 3");

    this->_Sfxs.push_back(sfx1);
    this->_Sfxs.push_back(sfx2);
    this->_Sfxs.push_back(sfx3);

    return 0;
}

int Story::play()
{
    Message* currentMessage = this->_findMessageById(1);
    if (currentMessage) {
        ChooseClothesEvent* currentCCE = NULL;
        MakeProtagonistEvent* currentMPE = NULL;
        Event* currentEvent = NULL;
        
        while (1)
        {
            if (currentMessage) {
                std::cout << currentMessage->getText() << std::endl;
                int nextMessage = currentMessage->getNextMessage();

                std::string buff;
                std::cin >> buff;
                
                if (nextMessage != 0) {
                    currentMessage = this->_findMessageById(nextMessage);
                }
                else {
                    int nextEvent = currentMessage->getNextEvent();
                    currentMessage = NULL;

                    currentEvent = this->_findEventById(nextEvent);
                }
            }
            else if (currentEvent) {
                std::vector<std::string> playerOptions = currentEvent->getPlayerOptions();
                if (!playerOptions.empty()) {
                    for (int i = 0; i < playerOptions.size(); i++) {
                        std::cout << "[" << i << "] " << playerOptions[i] << std::endl;
                    }
                    std::cout << std::endl;
                    
                    int nextMessage;
                    std::cin >> nextMessage;

                    std::vector<int> nextMessages = currentEvent->getNextMessages();
                    currentEvent = NULL;
                    currentMessage = this->_findMessageById(nextMessages[nextMessage]);
                }
                else {
                    int mpei = currentEvent->getMpei();
                    int ccei = currentEvent->getCcei();
                    if (mpei != 0) {
                        currentEvent = NULL;
                        currentMPE = this->_getMpei();
                    }
                    else if (ccei != 0) {
                        currentEvent = NULL;
                        currentCCE = this->_findCceById(ccei);
                    }
                    else {
                        std::cout << "cant find whats next" << std::endl;
                    }
                }
            }
            else if (currentMPE) {
                std::cout << currentMPE->getText() << std::endl;
                std::cout << "DefaultName = " << currentMPE->getName() << std::endl;
                std::cout << "Podaj imie: ";
                std::string name;
                std::cin >> name;
                this->_getPlayer()->setName(name);

                int playerInput = 0;
                
                std::cout << "Wybierz kolor skory" << std::endl;
                for (int i = 0; i < currentMPE->getSkins().size(); i++) {
                    std::cout << "[" << i << "] " << currentMPE->getSkins()[i][0] << std::endl;
                }
                std::cin >> playerInput;
                this->_getPlayer()->setGSkins(currentMPE->getSkins()[playerInput]);

                std::cout << "Wybierz twarz" << std::endl;
                for (int i = 0; i < currentMPE->getFaces().size(); i++) {
                    std::cout << "[" << i << "] " << currentMPE->getFaces()[i][0] << std::endl;
                }
                std::cin >> playerInput;
                this->_getPlayer()->setGFaces(currentMPE->getFaces()[playerInput]);

                std::cout << "Wybierz kolor wlosow" << std::endl;
                for (int i = 0; i < currentMPE->getHairs().size(); i++) {
                    std::cout << "[" << i << "] " << currentMPE->getHairs()[i][0] << std::endl;
                }
                std::cin >> playerInput;
                this->_getPlayer()->setGHairs(currentMPE->getHairs()[playerInput]);

                this->_getPlayer()->printInfoAboutPlayer();

                int nextMessageId = currentMPE->getNextMessageId();
                currentMessage = this->_findMessageById(nextMessageId);
                currentMPE = NULL;
            }
            else if (currentCCE) {
                std::cout << currentCCE->getText() << std::endl;
                for (int i = 0; i < currentCCE->getClothes().size(); i++) {
                    std::cout << "[" << i << "] " << currentCCE->getClothes()[i][0] << std::endl;
                }
                int playerInput1 = 0;
                std::cin >> playerInput1;
                this->_getPlayer()->setGClothes(currentCCE->getClothes()[playerInput1]);

                for (int i = 0; i < currentCCE->getClothes()[playerInput1].size(); i++) {
                    std::cout << "[" << i << "] " << currentCCE->getClothes()[playerInput1][i] << std::endl;
                }
                int playerInput2 = 0;
                std::cin >> playerInput2;
                this->_getPlayer()->setCurrentClothesId(playerInput2);

                std::cout << "Player clothes: " << this->_getPlayer()->getCurrentClothes() << std::endl;
                int nextMessageId = currentCCE->getNextMessageId();
                currentCCE = NULL;
                currentMessage = this->_findMessageById(nextMessageId);
            }
            else {
                return 0;
            }
        }
    }
    else {
        return 1; //cant find starting message
    }

    return 0;
}

Event* Story::_findEventById(int id)
{
    for (int i = 0; i < this->_Events.size(); i++) {
        if (this->_Events[i].getId() == id) {
            return &this->_Events[i];
        }
    }
    return NULL;
}

Message* Story::_findMessageById(int id)
{
    for (int i = 0; i < this->_Messages.size(); i++) {
        if (this->_Messages[i].getId() == id) {
            return &this->_Messages[i];
        }
    }
    return NULL;
}


MakeProtagonistEvent* Story::_getMpei()
{
    return this->_MPEvent;
}

ChooseClothesEvent* Story::_findCceById(int id)
{
    for (int i = 0; i < this->_CCEvents.size(); i++) {
        if (this->_CCEvents[i].getId() == id) {
            return &this->_CCEvents[i];
        }
    }
    return NULL;
}

Protagonist* Story::_getPlayer()
{
    return this->_Player;
}

void Story::_setName(std::string name)
{
    this->_name = name;
}

void Story::_setInfo(std::string info)
{
    this->_info = info;
}

void Story::_setAuthor(std::string author)
{
    this->_author = author;
}

void Story::_setDate(std::string date)
{
    this->_date = date;
}

bool Story::_isHeaderOkay(std::fstream* file)
{
    char header[0x13];
    file->read(header, 0x13);

    if (strcmp(header, "wewescriptcompiled") == 0) {
        return true;
    }

    return false;
}

bool Story::_isSizeOkay(std::fstream* file)
{
    int sizeFromFile;
    file->read(reinterpret_cast<char*>(&sizeFromFile), sizeof(int));
    this->_swapBytes(sizeFromFile);
    
    file->seekg(0, std::ios::end);
    int realSize = file->tellg();

    file->seekg(0x18, std::ios::beg);

    if (realSize == sizeFromFile) {
        return true;
    }

    return false;
}

void Story::_loadGlobalInfo(std::fstream* file)
{
    int buff;
    unsigned short ffff = 0x0000;
    char buffString[0xff];
    this->_wipeStrBuff(buffString, 0xff);

    // read story name
    file->read(reinterpret_cast<char*>(&buff), sizeof(int));
    file->read(buffString, buff);
    this->_name = buffString;
    this->_wipeStrBuff(buffString);

    // read story info
    file->read(reinterpret_cast<char*>(&buff), sizeof(int));
    file->read(buffString, buff);
    this->_info = buffString;
    this->_wipeStrBuff(buffString);
    
    // read author
    file->read(reinterpret_cast<char*>(&buff), sizeof(int));
    file->read(buffString, buff);
    this->_author = buffString;
    this->_wipeStrBuff(buffString);

    // read date
    file->read(reinterpret_cast<char*>(&buff), sizeof(int));
    file->read(buffString, buff);
    this->_date = buffString;
    this->_wipeStrBuff(buffString);

    // check if end of global info
    file->read(reinterpret_cast<char*>(&ffff), sizeof(short));
    if (ffff != 0xffff) {
        std::cout << "0xffff is missing" << std::endl;
    }
}

void Story::_loadCharacters(std::fstream* file)
{
    // check if header is okay
    unsigned short header = 0x0000;
    file->read(reinterpret_cast<char*>(&header), sizeof(short));
    if (header != 0x0001) {
        std::cout << "character header error" << std::endl;
    }

    unsigned short numberOfCharacters = 0x0000;
    unsigned short buffId = 0x0000;
    unsigned short sizeOfName = 0x0000;
    char name[0xff];
    this->_wipeStrBuff(name, 0xff);
    std::string strName;
    std::vector<std::string> paths;
    unsigned short numberOfSpritesPaths = 0x0000;
    unsigned short sizeOfPath = 0x0000;
    char path[0xff];
    this->_wipeStrBuff(path, 0xff);
    std::string strPath;

    file->read(reinterpret_cast<char*>(&numberOfCharacters), sizeof(short));
    
    for (short i = 0; i < numberOfCharacters; i++) {
        paths.clear();
        file->read(reinterpret_cast<char*>(&buffId), sizeof(short));
        file->read(reinterpret_cast<char*>(&sizeOfName), sizeof(short));
        file->read(name, sizeOfName);
        strName = name;
        this->_wipeStrBuff(name);
        file->read(reinterpret_cast<char*>(&numberOfSpritesPaths), sizeof(short));
        for (short j = 0; j < numberOfSpritesPaths; j++) {
            file->read(reinterpret_cast<char*>(&sizeOfPath), sizeof(short));
            file->read(path, sizeOfPath);
            strPath = path;
            this->_wipeStrBuff(path);
            paths.push_back(strPath);
        }
        this->_Characters.push_back(Character(buffId, strName, paths));
    }
}

void Story::_loadCCE(std::fstream* file)
{
    // check if header is okay
    unsigned short header = 0x0000;
    file->read(reinterpret_cast<char*>(&header), sizeof(short));
    if (header != 0x0002) {
        std::cout << "CCE header error" << std::endl;
    }

    unsigned short numberOfCCE = 0x0000;
    unsigned short buffId = 0x0000;
    unsigned short sizeOfText = 0x0000;
    char text[0xff];
    this->_wipeStrBuff(text, 0xff);
    std::string strText;
    std::vector<std::vector<std::string>> clothesY;
    std::vector<std::string> clothesX;
    unsigned short sizeOfClothesY = 0x0000;
    unsigned short sizeOfClothesX = 0x0000;
    unsigned short sizeOfPath = 0x0000;
    char path[0xff];
    this->_wipeStrBuff(path, 0xff);
    std::string strPath;
    unsigned short nextMessageId = 0x0000;

    file->read(reinterpret_cast<char*>(&numberOfCCE), sizeof(short));
    for (short i = 0; i < numberOfCCE; i++) {
        file->read(reinterpret_cast<char*>(&buffId), sizeof(short));
        file->read(reinterpret_cast<char*>(&sizeOfText), sizeof(short));
        file->read(text, sizeOfText);
        strText = text;
        this->_wipeStrBuff(text);
        file->read(reinterpret_cast<char*>(&sizeOfClothesY), sizeof(short));
        for (short j = 0; j < sizeOfClothesY; j++) {
            file->read(reinterpret_cast<char*>(&sizeOfClothesX), sizeof(short));
            for (short k = 0; k < sizeOfClothesX; k++) {
                file->read(reinterpret_cast<char*>(&sizeOfPath), sizeof(short));
                file->read(path, sizeOfPath);
                strPath = path;
                this->_wipeStrBuff(path);
                clothesX.push_back(strPath);
            }
            clothesY.push_back(clothesX);
            clothesX.clear();
        }
        file->read(reinterpret_cast<char*>(&nextMessageId), sizeof(short));
        this->_CCEvents.push_back(ChooseClothesEvent(buffId, strText, clothesY, nextMessageId));
        clothesY.clear();
    }
}

void Story::_loadEvents(std::fstream* file)
{
    // check if header is okay
    unsigned short header = 0x0000;
    file->read(reinterpret_cast<char*>(&header), sizeof(short));
    if (header != 0x0003) {
        std::cout << "Event header error" << std::endl;
    }

    unsigned short numberOfEvents = 0x0000;
    unsigned short buffId = 0x0000;
    unsigned short numberOfPlayerOptions = 0x0000;
    unsigned short sizeOfPlayerOption = 0x0000;
    char playerOption[0xff];
    this->_wipeStrBuff(playerOption, 0xff);
    std::string strPlayerOption;
    std::vector<std::string> playerOptions;
    unsigned short numberOfNextMessages = 0x0000;
    unsigned short nextMessage = 0x0000;
    std::vector<int> nextMessages;
    unsigned short numberOfNextEvents = 0x0000;
    unsigned short nextEvent = 0x0000;
    std::vector<int> nextEvents;
    unsigned short mpei = 0x0000;
    unsigned short ccei = 0x0000;

    file->read(reinterpret_cast<char*>(&numberOfEvents), sizeof(short));
    for (short i = 0; i < numberOfEvents; i++) {
        file->read(reinterpret_cast<char*>(&buffId), sizeof(short));
        file->read(reinterpret_cast<char*>(&numberOfPlayerOptions), sizeof(short));
        for (short j = 0; j < numberOfPlayerOptions; j++) {
            file->read(reinterpret_cast<char*>(&sizeOfPlayerOption), sizeof(short));
            file->read(playerOption, sizeOfPlayerOption);
            strPlayerOption = playerOption;
            this->_wipeStrBuff(playerOption);
            playerOptions.push_back(strPlayerOption);
        }
        file->read(reinterpret_cast<char*>(&numberOfNextMessages), sizeof(short));
        for (short j = 0; j < numberOfNextMessages; j++) {
            file->read(reinterpret_cast<char*>(&nextMessage), sizeof(short));
            nextMessages.push_back(nextMessage);
        }
        file->read(reinterpret_cast<char*>(&numberOfNextEvents), sizeof(short));
        for (short j = 0; j < numberOfNextEvents; j++) {
            file->read(reinterpret_cast<char*>(&nextEvent), sizeof(short));
            nextEvents.push_back(nextEvent);
        }
        file->read(reinterpret_cast<char*>(&mpei), sizeof(short));
        file->read(reinterpret_cast<char*>(&ccei), sizeof(short));

        this->_Events.push_back(Event(buffId, playerOptions, nextMessages, nextEvents, mpei, ccei));

        playerOptions.clear();
        nextMessages.clear();
        nextEvents.clear();
    }
}

void Story::_loadImages(std::fstream* file)
{
    // check if header is okay
    unsigned short header = 0x0000;
    file->read(reinterpret_cast<char*>(&header), sizeof(short));
    if (header != 0x0004) {
        std::cout << "Image header error" << std::endl;
    }

    unsigned short numberOfImages = 0x0000;
    unsigned short buffId = 0x0000;
    unsigned short sizeOfName = 0x0000;
    char name[0xff];
    this->_wipeStrBuff(name, 0xff);
    std::string strName;
    unsigned short sizeOfPath = 0x0000;
    char path[0xff];
    this->_wipeStrBuff(path, 0xff);
    std::string strPath;

    file->read(reinterpret_cast<char*>(&numberOfImages), sizeof(short));
    for (short i = 0; i < numberOfImages; i++) {
        file->read(reinterpret_cast<char*>(&buffId), sizeof(short));
        file->read(reinterpret_cast<char*>(&sizeOfName), sizeof(short));
        file->read(name, sizeOfName);
        strName = name;
        this->_wipeStrBuff(name);
        file->read(reinterpret_cast<char*>(&sizeOfPath), sizeof(short));
        file->read(path, sizeOfPath);
        strPath = path;
        this->_wipeStrBuff(path);
        this->_Images.push_back(Image(buffId, strName, strPath));
    }
}

void Story::_loadMPE(std::fstream* file)
{
    // check if header is okay
    unsigned short header = 0x0000;
    file->read(reinterpret_cast<char*>(&header), sizeof(short));
    if (header != 0x0005) {
        std::cout << "MPE header error" << std::endl;
    }

    unsigned short buffId = 0x0000;
    unsigned short sizeOfName = 0x0000;
    char name[0xff];
    this->_wipeStrBuff(name, 0xff);
    std::string strName;
    unsigned short sizeOfText = 0x0000;
    char text[0xff];
    this->_wipeStrBuff(text, 0xff);
    std::string strText;

    unsigned short sizeOfFacesY = 0x0000;
    unsigned short sizeOfFacesX = 0x0000;
    unsigned short sizeOfFace = 0x0000;
    char face[0xff];
    this->_wipeStrBuff(face, 0xff);
    std::string strFace;
    std::vector<std::vector<std::string>> facesY;
    std::vector<std::string> facesX;
    
    unsigned short sizeOfSkinsY = 0x0000;
    unsigned short sizeOfSkinsX = 0x0000;
    unsigned short sizeOfSkin = 0x0000;
    char skin[0xff];
    this->_wipeStrBuff(skin, 0xff);
    std::string strSkin;
    std::vector<std::vector<std::string>> skinsY;
    std::vector<std::string> skinsX;

    unsigned short sizeOfHairsY = 0x0000;
    unsigned short sizeOfHairsX = 0x0000;
    unsigned short sizeOfHair = 0x0000;
    char hair[0xff];
    this->_wipeStrBuff(hair, 0xff);
    std::string strHair;
    std::vector<std::vector<std::string>> hairsY;
    std::vector<std::string> hairsX;

    unsigned short nextMessageId = 0x0000;

    file->read(reinterpret_cast<char*>(&buffId), sizeof(short));
    file->read(reinterpret_cast<char*>(&sizeOfName), sizeof(short));
    file->read(name, sizeOfName);
    strName = name;
    file->read(reinterpret_cast<char*>(&sizeOfText), sizeof(short));
    file->read(text, sizeOfText);
    strText = text;

    file->read(reinterpret_cast<char*>(&sizeOfFacesY), sizeof(short));
    for (short y = 0; y < sizeOfFacesY; y++) {
        file->read(reinterpret_cast<char*>(&sizeOfFacesX), sizeof(short));
        for (short x = 0; x < sizeOfFacesX; x++) {
            file->read(reinterpret_cast<char*>(&sizeOfFace), sizeof(short));
            file->read(face, sizeOfFace);
            strFace = face;
            this->_wipeStrBuff(face);
            facesX.push_back(strFace);
        }
        facesY.push_back(facesX);
        facesX.clear();
    }

    file->read(reinterpret_cast<char*>(&sizeOfSkinsY), sizeof(short));
    for (short y = 0; y < sizeOfSkinsY; y++) {
        file->read(reinterpret_cast<char*>(&sizeOfSkinsX), sizeof(short));
        for (short x = 0; x < sizeOfSkinsX; x++) {
            file->read(reinterpret_cast<char*>(&sizeOfSkin), sizeof(short));
            file->read(skin, sizeOfSkin);
            strSkin = skin;
            this->_wipeStrBuff(skin);
            skinsX.push_back(strSkin);
        }
        skinsY.push_back(skinsX);
        skinsX.clear();
    }

    file->read(reinterpret_cast<char*>(&sizeOfHairsY), sizeof(short));
    for (short y = 0; y < sizeOfHairsY; y++) {
        file->read(reinterpret_cast<char*>(&sizeOfHairsX), sizeof(short));
        for (short x = 0; x < sizeOfHairsX; x++) {
            file->read(reinterpret_cast<char*>(&sizeOfHair), sizeof(short));
            file->read(hair, sizeOfHair);
            strHair = hair;
            this->_wipeStrBuff(hair);
            hairsX.push_back(strHair);
        }
        hairsY.push_back(hairsX);
        hairsX.clear();
    }

    file->read(reinterpret_cast<char*>(&nextMessageId), sizeof(short));
    
    this->_MPEvent = new MakeProtagonistEvent(buffId, strName, strText, facesY, skinsY, hairsY, nextMessageId);
}

void Story::_swapBytes(int& x)
{
    x = ((x & 0x00FF) << 16) | ((x & 0xFF0000) >> 16) | (x & 0x0000FF00);
    x = ((x & 0xFF00FF00) >> 8) | ((x & 0x00FF00FF) << 8);
}

void Story::_wipeStrBuff(char* buff)
{
    int i = 0;
    while (buff[i] != NULL) {
        buff[i] = NULL;
        i++;
    }

}

void Story::_wipeStrBuff(char* buff, int size)
{
    memset(buff, 0, size);
}
