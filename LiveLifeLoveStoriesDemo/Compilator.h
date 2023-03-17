#pragma once
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include "Character.h"
#include "ChooseClothesEvent.h"
#include "Event.h"
#include "Image.h"
#include "MakeProtagonistEvent.h"
#include "Message.h"
#include "Music.h"
#include "Protagonist.h"
#include "Sfx.h"

class Compilator
{
public:
	void compile(std::fstream* file, std::string fileName);

private:
	std::vector<Character> _Characters;
	std::vector<ChooseClothesEvent> _CCEvents;
	std::vector<Event> _Events;
	std::vector<Image> _Images;
	MakeProtagonistEvent* _MPEvent;
	std::vector<Message> _Messages;
	std::vector<Music> _Musics;
	Protagonist* _Player;
	std::vector<Sfx> _Sfxs;

	//read
	void _loadFileToMemory(std::fstream* file);
	int _findHeader(std::string line);
	void _loadCharacter(std::fstream* file);
	void _loadCCE(std::fstream* file);
	void _loadEvent(std::fstream* file);
	void _loadImage(std::fstream* file);
	void _loadMPE(std::fstream* file);
	void _loadMessage(std::fstream* file);
	void _loadMusic(std::fstream* file);
	void _loadSfx(std::fstream* file);

	int _readId(std::string line);
	std::string _readText(std::string line);
	std::vector<int> _readVectorInt(std::string line);
	std::vector<std::string> _readVectorText(std::string line);
	std::vector<std::vector<std::string>> _readDoubleVectorText(std::fstream* file);

	std::string cutString(std::string line, int start, int end);

	//write
	void _writeMemoryToFile(std::string fileName);
};

