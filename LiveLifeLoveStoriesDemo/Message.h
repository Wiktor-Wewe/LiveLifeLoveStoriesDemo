#pragma once
#include <string>
#include <vector>

class Message
{
public:
	Message(int id, std::string text, std::vector<int> musicId, std::vector<int> sfxId,
		int spriteId, int clothesId, int bgImageId, int nextMessage, int nextEvent)
	{
		this->_id = id;
		this->_text = text;
		this->_musicId = musicId;
		this->_sfxId = sfxId;
		this->_spriteId = spriteId;
		this->_clothesId = clothesId;
		this->_bgImageId = bgImageId;
		this->_nextMessage = nextMessage;
		this->_nextEvent = nextEvent;
	}
	int getId();
	std::string getText();
	int getNextMessage();
	int getNextEvent();

private:
	int _id;
	std::string _text;
	std::vector<int> _musicId;
	std::vector<int> _sfxId;
	int _spriteId;
	int _clothesId;
	int _bgImageId;
	int _nextMessage;
	int _nextEvent;
};

