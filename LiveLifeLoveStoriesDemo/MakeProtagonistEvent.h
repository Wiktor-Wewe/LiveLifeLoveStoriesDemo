#pragma once
#include <string>
#include <vector>

class MakeProtagonistEvent
{
public:
	MakeProtagonistEvent(int id, std::string name, std::string text,
		std::vector<std::vector<std::string>> faces,
		std::vector<std::vector<std::string>> skins,
		std::vector<std::vector<std::string>> hairs)
	{
		this->_id = id;
		this->_name = name;
		this->_text = text;
		this->_faces = faces;
		this->_skins = skins;
		this->_hairs = hairs;
	}
	int getId();

private:
	int _id;
	std::string _name;
	std::string _text;

	std::vector<std::vector<std::string>> _faces;
	std::vector<std::vector<std::string>> _skins;
	std::vector<std::vector<std::string>> _hairs;
};

