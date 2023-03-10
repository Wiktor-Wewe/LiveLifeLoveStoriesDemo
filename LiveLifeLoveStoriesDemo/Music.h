#pragma once
#include <string>
class Music
{
public:
	Music(int id, std::string name, std::string path) 
	{
		this->_id = id;
		this->_name = name;
		this->_path = path;
	}

private:
	int _id;
	std::string _name;
	std::string _path;
};

