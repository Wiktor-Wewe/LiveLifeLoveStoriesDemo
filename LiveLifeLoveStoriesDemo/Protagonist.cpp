#include "Protagonist.h"
#include <iostream>

void Protagonist::setName(std::string name)
{
	this->_name = name;
}

void Protagonist::setGSkins(std::vector<std::string> gskins)
{
	this->_gSkins = gskins;
}

void Protagonist::setGFaces(std::vector<std::string> gfaces)
{
	this->_gFaces = gfaces;
}

void Protagonist::setGHairs(std::vector<std::string> ghairs)
{
	this->_gHairs = ghairs;
}

void Protagonist::setGClothes(std::vector<std::string> glothes)
{
	this->_gClothes = glothes;
}

void Protagonist::setSkin(int id)
{
	this->_gSkinId = id;
}

void Protagonist::setFace(int id)
{
	this->_gFaceId = id;
}

void Protagonist::setHairs(int id)
{
	this->_gHairsId = id;
}

void Protagonist::setClothes(int id)
{
	this->_gClothesId = id;
}

std::string Protagonist::getName()
{
	return this->_name;
}

std::string Protagonist::getCurrentSkin()
{
	return this->_gSkins[this->_gSkinId];
}

std::string Protagonist::getCurrentFace()
{
	return this->_gFaces[this->_gFaceId];
}

std::string Protagonist::getCurrentHairs()
{
	return this->_gHairs[this->_gHairsId];
}

std::string Protagonist::getCurrentClothes()
{
	return this->_gClothes[this->_gClothesId];
}

void Protagonist::printInfoAboutPlayer()
{
	std::cout << std::endl;
	std::cout << "Name: " << this->_name << std::endl;
	std::cout << "Current skin: " << this->getCurrentSkin() << std::endl;
	std::cout << "Current face: " << this->getCurrentFace() << std::endl;
	std::cout << "Current hairs: " << this->getCurrentHairs() << std::endl;
	std::cout << std::endl;
}
