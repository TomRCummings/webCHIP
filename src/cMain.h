/*
cMain: The main window of the emulator; inherits from wxFrame. Keeps track of UI, UI events, input events, actually drawing the screen buffer from the Chip8, updating the sound machine, and any file IO.
*/

#pragma once

#include <iostream>
#include <fstream>
#include <time.h>
#include <chrono>
#include <map>
#include <string>
#include <SDL.h>
#include "chip8.h"
#include "Sound/beeper.h"

class cMain {
public:
	explicit cMain();
	~cMain();

private:
	//Render timers
	float renderRate = 16.66f;
	std::chrono::time_point<std::chrono::steady_clock> lastTime;
	std::chrono::duration<float, std::milli> accumulator{};

	//SDL window, handles graphics
	SDL_Window* sdlWindow = NULL;
	//SDL renderer, handles graphics
	SDL_Renderer* sdlRenderer = NULL;
	//Pixel color - white default
	int pColor[3] = { 255, 255, 255 };
	//Background color - black default
	int bColor[3] = { 0, 0, 0 };

	//SDL sound class
	Beeper soundMaker;

	//Chip-8
	Chip8 theChip8;
	//Keeps track of Chip-8 state for temporary pauses
	bool runChip8 = false;
	//Keeps track of if a ROM has been loaded
	bool loadedROM = false;
	//Chip-8 rom size in bytes
	size_t chip8ROMSize;
	//Chip-8 rom array
	unsigned char chip8ROM[3584];

	//Default ROM directory
	std::string defaultROMDir;
	//Default save state directory
	std::string defaultStateDir;
	//Keybinding map (index of Chip-8 input as key, unicode value of key as value)
	std::map<int, int> keybindings;

	//Memory viewer open flag
	bool memoryViewerOpen = false;
	//Setter for memory viewer flag
	void setMemoryViewerOpen(bool isOpen);

	//Setting file helpers
	void parseConfigFile();
	//Update config file helper
	void updateConfigFile();
	//Load ROM helper
	void loadROM(std::string filename);
	//Save state helper
	void saveChip8State(std::string filename);
	//Load state helper
	void loadChip8State(std::string filemane);
	//Render helper
	void drawScreen();
};