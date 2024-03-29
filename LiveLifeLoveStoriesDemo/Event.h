#pragma once
#include <vector>
#include <string>
class Event
{
public:
	Event(int id, std::vector<std::string> playerOptions, std::vector<int> nextMessages,
	std::vector<int> nextEvents, int mpei, int ccei)
	{
		this->_id = id;
		this->_playerOptions = playerOptions;
		this->_nextMessages = nextMessages;
		this->_nextEvents = nextEvents;
		this->_makeProtagonistEventId = mpei;
		this->_chooseClothesEventId = ccei;
	}
	int getId();
	std::vector<std::string> getPlayerOptions();
	std::vector<int> getNextMessages();
	std::vector<int> getNextEvents();
	int getMpei();
	int getCcei();

private:
	int _id;
	std::vector<std::string> _playerOptions;
	std::vector<int> _nextMessages;
	std::vector<int> _nextEvents;
	int _makeProtagonistEventId;
	int _chooseClothesEventId;
};

