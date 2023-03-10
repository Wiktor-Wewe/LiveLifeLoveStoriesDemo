#include "MakeProtagonistEvent.h"

int MakeProtagonistEvent::getId()
{
    return this->_id;
}

std::string MakeProtagonistEvent::getName()
{
    return this->_name;
}

std::string MakeProtagonistEvent::getText()
{
    return this->_text;
}

std::vector<std::vector<std::string>> MakeProtagonistEvent::getFaces()
{
    return this->_faces;
}

std::vector<std::vector<std::string>> MakeProtagonistEvent::getSkins()
{
    return this->_skins;
}

std::vector<std::vector<std::string>> MakeProtagonistEvent::getHairs()
{
    return this->_hairs;
}

int MakeProtagonistEvent::getNextMessageId()
{
    return this->_nextMessageId;
}
