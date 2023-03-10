#pragma once
#include <string>
#include <vector>

class Protagonist
{
public:
	Protagonist(std::string name)
	{
		this->_name = name;
		this->_gClothesId = -1;
		this->_gSpriteId = -1;

		this->_gClothes = std::vector<std::string>();
		this->_gSprites = std::vector<std::string>();
	}

private:
	std::string _name;
	
	std::vector<std::string> _gSprites;
	int _gSpriteId;
	
	std::vector<std::string> _gClothes;
	int _gClothesId;
};

