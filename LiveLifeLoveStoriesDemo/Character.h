#pragma once
#include <string>
#include <vector>

class Character
{
public:
	Character(int id, std::string name, std::vector<std::string> spritesPaths) 
	{
		this->_id = id;
		this->_name = name;
		this->_spritesPaths = spritesPaths;
		this->_currentSprite = 0;
	}
	int getId();
	std::string getName();
	std::vector<std::string> getSprites();


private:
	
	int _id;
	std::string _name;
	std::vector<std::string> _spritesPaths;
	int _currentSprite;
};