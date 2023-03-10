#pragma once
#include <string>
#include <vector>

class MakeProtagonistEvent
{
public:
	MakeProtagonistEvent(int id, std::string name, std::string text,
		std::vector<std::vector<std::string>> faces,
		std::vector<std::vector<std::string>> skins,
		std::vector<std::vector<std::string>> hairs,
		int nextMessageId)
	{
		this->_id = id;
		this->_name = name;
		this->_text = text;
		this->_faces = faces;
		this->_skins = skins;
		this->_hairs = hairs;
		this->_nextMessageId = nextMessageId;
	}
	int getId();
	std::string getName();
	std::string getText();
	std::vector<std::vector<std::string>> getFaces();
	std::vector<std::vector<std::string>> getSkins();
	std::vector<std::vector<std::string>> getHairs();
	int getNextMessageId();

private:
	int _id;
	std::string _name;
	std::string _text;

	std::vector<std::vector<std::string>> _faces;
	std::vector<std::vector<std::string>> _skins;
	std::vector<std::vector<std::string>> _hairs;
	int _nextMessageId;
};

