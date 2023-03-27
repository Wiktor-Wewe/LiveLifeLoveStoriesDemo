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

    this->_loadCharacters(file);
    // load cce
    // load events
    // load images
    // load mpe
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
    char buffString[0xff];
    this->_wipeStrBuff(buffString, 0xff);

    // read story name
    file->read(reinterpret_cast<char*>(&buff), sizeof(int));
    file->read(buffString, buff);
    this->_name = buffString;
    this->_wipeStrBuff(buffString, 0xff);

    // read story info
    file->read(reinterpret_cast<char*>(&buff), sizeof(int));
    file->read(buffString, buff);
    this->_info = buffString;
    this->_wipeStrBuff(buffString, 0xff);
    
    // read author
    file->read(reinterpret_cast<char*>(&buff), sizeof(int));
    file->read(buffString, buff);
    this->_author = buffString;
    this->_wipeStrBuff(buffString, 0xff);

    // read date
    file->read(reinterpret_cast<char*>(&buff), sizeof(int));
    file->read(buffString, buff);
    this->_date = buffString;
    this->_wipeStrBuff(buffString, 0xff);
}

void Story::_loadCharacters(std::fstream* file)
{

}

void Story::_swapBytes(int &x)
{
    x = x >> 8;
}

void Story::_wipeStrBuff(char* buff, int size)
{
    for (int i = 0; i < size; i++) {
        buff[i] = NULL;
    }
}
