#pragma once
#include <string>
#include <vector>

class Protagonist
{
public:
	Protagonist(std::string name)
	{
		this->_name = name;

		this->_gSkinId = 0;
		this->_gFaceId = 0;
		this->_gHairsId = 0;
		this->_gClothesId = 0;
		
		this->_gSkins = std::vector<std::string>();
		this->_gFaces = std::vector<std::string>();
		this->_gHairs = std::vector<std::string>();
		this->_gClothes = std::vector<std::string>();
	}
	void setName(std::string name);
	void setGSkins(std::vector<std::string> gskins);
	void setGFaces(std::vector<std::string> gfaces);
	void setGHairs(std::vector<std::string> ghairs);
	void setGClothes(std::vector<std::string> glothes);
	void setSkin(int id);
	void setFace(int id);
	void setHairs(int id);
	void setClothes(int id);

	std::string getName();
	std::string getCurrentSkin();
	std::string getCurrentFace();
	std::string getCurrentHairs();
	std::string getCurrentClothes();

	void printInfoAboutPlayer();

private:
	std::string _name;
	
	std::vector<std::string> _gSkins;
	int _gSkinId;

	std::vector<std::string> _gFaces;
	int _gFaceId;
	
	std::vector<std::string> _gClothes;
	int _gClothesId;

	std::vector<std::string> _gHairs;
	int _gHairsId;
};

