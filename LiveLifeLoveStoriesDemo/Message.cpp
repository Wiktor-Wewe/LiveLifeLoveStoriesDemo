#include "Message.h"

int Message::getId()
{
	return this->_id;
}

std::string Message::getText()
{
	return this->_text;
}

int Message::getNextMessage()
{
	return this->_nextMessage;
}

int Message::getNextEvent()
{
	return this->_nextEvent;
}
