#pragma once
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
#include <fstream>
#include <iostream>

class Story
{
public:
	Story()
	{
		this->_Characters = std::vector<Character>();
		this->_CCEvents = std::vector<ChooseClothesEvent>();
		this->_Events = std::vector<Event>();
		this->_Images = std::vector<Image>();
		this->_MPEvent = (MakeProtagonistEvent*)malloc(sizeof(MakeProtagonistEvent));
		this->_Messages = std::vector<Message>();
		this->_Musics = std::vector<Music>();
		this->_Player = (Protagonist*)malloc(sizeof(Protagonist));
		this->_Sfxs = std::vector<Sfx>();
	}

	int loadStory(std::fstream* file);
	int loadStoryFake(std::fstream* file);
	int play();

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

	Event* _findEventById(int id);
	Message* _findMessageById(int id);
	MakeProtagonistEvent* _getMpei();
	ChooseClothesEvent* _findCceById(int id);
	Protagonist* _getPlayer();

	std::string cutStringWhile(std::string text, int begin, char end);
	std::vector<std::string> str2vecstr(std::string text);
	int _isHeader(std::string text);
	void _loadCharacter(std::fstream* file);
	void _loadCCE(std::fstream* file);
};

