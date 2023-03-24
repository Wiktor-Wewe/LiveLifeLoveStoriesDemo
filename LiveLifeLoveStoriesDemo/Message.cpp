#include "Message.h"

int Message::getId()
{
	return this->_id;
}

std::string Message::getText()
{
	return this->_text;
}

std::vector<int> Message::getAllMusicId()
{
	return this->_musicId;
}

std::vector<int> Message::getAllSfxId()
{
	return this->_sfxId;
}

int Message::getSpriteId()
{
	return this->_spriteId;
}

int Message::getClothesId()
{
	return this->_clothesId;
}

int Message::getBgImageId()
{
	return this->_bgImageId;
}

int Message::getNextMessage()
{
	return this->_nextMessage;
}

int Message::getNextEvent()
{
	return this->_nextEvent;
}
