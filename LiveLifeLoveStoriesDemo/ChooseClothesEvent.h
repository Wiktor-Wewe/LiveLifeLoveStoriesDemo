#pragma once
#include <string>
#include <vector>
class ChooseClothesEvent
{
public:
	ChooseClothesEvent(int id, std::string text, std::vector<std::vector<std::string>> clothes)
	{
		this->_id = id;
		this->_text = text;
		this->_clothes = clothes;
		this->_currentClothes = 0;
	}
	int getId();

private:
	int _id;
	std::string _text;
	std::vector<std::vector<std::string>> _clothes;
	int _currentClothes;
};

