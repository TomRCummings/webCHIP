#include "cMain.h"

cMain::cMain() {

	//Chip-8 setup
	theChip8.initialize();
	chip8ROMSize = 3584;

	//SDL window & renderer initialization
	bool sdlInitialized = true;
	sdlWindow = SDL_CreateWindowFrom(nullptr); // FIXME: Do the correct SDL thing here.
	if (sdlWindow == NULL) {
		sdlInitialized = false;
	}
	else {
		sdlRenderer = SDL_CreateRenderer(sdlWindow, -1, SDL_RENDERER_ACCELERATED);
		if (sdlRenderer == NULL) {
			sdlInitialized = false;
		}
		else {
			SDL_SetRenderDrawColor(sdlRenderer, 0x0, 0x0, 0x0, 0x0);
		}
	}

	//Sound initialization
	soundMaker.initializeAudio();

	//Load settings from config file
	parseConfigFile();

	//Set timer going
	lastTime = std::chrono::steady_clock::now();
}

cMain::~cMain() {
}

void cMain::setMemoryViewerOpen(bool isOpen) {
	memoryViewerOpen = isOpen;
}

void cMain::parseConfigFile() {
	std::string path = "config.txt";

	std::ifstream configFile;
	std::string line;
	std::string key;
	std::string value;
	int uniValue;

	if (FILE* file = fopen(path.c_str(), "r")) {
	}
	else {
		std::ofstream configFile("config.txt");

		configFile << "//Keybindings (unicode decimal)" << std::endl;
		configFile << "ZERO: 48" << std::endl;
		configFile << "ONE: 49" << std::endl;
		configFile << "TWO: 50" << std::endl;
		configFile << "THREE: 51" << std::endl;
		configFile << "FOUR: 52" << std::endl;
		configFile << "FIVE: 53" << std::endl;
		configFile << "SIX: 54" << std::endl;
		configFile << "SEVEN: 55" << std::endl;
		configFile << "EIGHT: 56" << std::endl;
		configFile << "NINE: 57" << std::endl;
		configFile << "A: 65" << std::endl;
		configFile << "B: 66" << std::endl;
		configFile << "C: 67" << std::endl;
		configFile << "D: 68" << std::endl;
		configFile << "E: 69" << std::endl;
		configFile << "F: 70" << std::endl;
		configFile << "SKIP_FRAME: 79" << std::endl;
	}

	configFile.open(path.c_str() , std::ios::in);

	if (configFile) {
	}
	else {
	}

	while (std::getline(configFile, line)) {
		if (line.find("//") != 0 && line.length() > 0) {
			std::size_t pos = line.find(":");
			key = line.substr(0, pos);
			value = line.substr(pos + 1);

			std::size_t found = value.find_first_of(" ");

			while (found != std::string::npos) {
				if (found != 0) {
					value = value.substr(0, found);
				}
				else {
					value = value.substr(1);
				}
				found = value.find_first_of(" ");
			}

			
			uniValue = std::stoi(value);

			if (key == "ZERO") {
				keybindings.insert(std::pair<int, int>(0, uniValue));
			}
			else if (key == "ONE") {
				keybindings.insert(std::pair<int, int>(1, uniValue));
			}
			else if (key == "TWO") {
				keybindings.insert(std::pair<int, int>(2, uniValue));
			}
			else if (key == "THREE") {
				keybindings.insert(std::pair<int, int>(3, uniValue));
			}
			else if (key == "FOUR") {
				keybindings.insert(std::pair<int, int>(4, uniValue));
			}
			else if (key == "FIVE") {
				keybindings.insert(std::pair<int, int>(5, uniValue));
			}
			else if (key == "SIX") {
				keybindings.insert(std::pair<int, int>(6, uniValue));
			}
			else if (key == "SEVEN") {
				keybindings.insert(std::pair<int, int>(7, uniValue));
			}
			else if (key == "EIGHT") {
				keybindings.insert(std::pair<int, int>(8, uniValue));
			}
			else if (key == "NINE") {
				keybindings.insert(std::pair<int, int>(9, uniValue));
			}
			else if (key == "A") {
				keybindings.insert(std::pair<int, int>(10, uniValue));
			}
			else if (key == "B") {
				keybindings.insert(std::pair<int, int>(11, uniValue));
			}
			else if (key == "C") {
				keybindings.insert(std::pair<int, int>(12, uniValue));
			}
			else if (key == "D") {
				keybindings.insert(std::pair<int, int>(13, uniValue));
			}
			else if (key == "E") {
				keybindings.insert(std::pair<int, int>(14, uniValue));
			}
			else if (key == "F") {
				keybindings.insert(std::pair<int, int>(15, uniValue));
			}
			else if (key == "SKIP_FRAME") {
				keybindings.insert(std::pair<int, int>(16, uniValue));
			}
		}
	}
}

void cMain::updateConfigFile() {

	std::ofstream configFile("config.txt");

	configFile << "//Keybindings (unicode decimal)" << std::endl;

	for (auto& controlPair : keybindings) {
		if (controlPair.first == 0) {
			configFile << "ZERO: " << std::to_string(controlPair.second) << std::endl;
		}
		else if (controlPair.first == 1) {
			configFile << "ONE: " << std::to_string(controlPair.second) << std::endl;
		}
		else if (controlPair.first == 2) {
			configFile << "TWO: " << std::to_string(controlPair.second) << std::endl;
		}
		else if (controlPair.first == 3) {
			configFile << "THREE: " << std::to_string(controlPair.second) << std::endl;
		}
		else if (controlPair.first == 4) {
			configFile << "FOUR: " << std::to_string(controlPair.second) << std::endl;
		}
		else if (controlPair.first == 5) {
			configFile << "FIVE: " << std::to_string(controlPair.second) << std::endl;
		}
		else if (controlPair.first == 6) {
			configFile << "SIX: " << std::to_string(controlPair.second) << std::endl;
		}
		else if (controlPair.first == 7) {
			configFile << "SEVEN: " << std::to_string(controlPair.second) << std::endl;
		}
		else if (controlPair.first == 8) {
			configFile << "EIGHT: " << std::to_string(controlPair.second) << std::endl;
		}
		else if (controlPair.first == 9) {
			configFile << "NINE: " << std::to_string(controlPair.second) << std::endl;
		}
		else if (controlPair.first == 10) {
			configFile << "A: " << std::to_string(controlPair.second) << std::endl;
		}
		else if (controlPair.first == 11) {
			configFile << "B: " << std::to_string(controlPair.second) << std::endl;
		}
		else if (controlPair.first == 12) {
			configFile << "C: " << std::to_string(controlPair.second) << std::endl;
		}
		else if (controlPair.first == 13) {
			configFile << "D: " << std::to_string(controlPair.second) << std::endl;
		}
		else if (controlPair.first == 14) {
			configFile << "E: " << std::to_string(controlPair.second) << std::endl;
		}
		else if (controlPair.first == 15) {
			configFile << "F: " << std::to_string(controlPair.second) << std::endl;
		}
		else if (controlPair.first == 16) {
			configFile << "SKIP_FRAME: " << std::to_string(controlPair.second) << std::endl;
		}
	}
}

void cMain::loadROM(std::string filename) {
	//Zero ROM array
	for (int i = 0; i < chip8ROMSize; i++) {
		chip8ROM[i] = 0;
	}


	//Open file stream to specified file
	std::ifstream inf(filename.c_str(), std::ios::binary);

	if (inf) {
		//Read in bytes from file to buffer
		inf.read((char*)&chip8ROM[0], chip8ROMSize);
		inf.close();

		theChip8.initialize();
		theChip8.loadROM(chip8ROM);

		theChip8.runCycle();
	}
	else {
	}
}

void cMain::saveChip8State(std::string filename) {
	std::ofstream file;
	file.open(filename.c_str(), std::ios::binary);
	unsigned char* machineMemory = theChip8.getMemory();
	unsigned char* machineRegisters = theChip8.getRegisters();
	unsigned short machineI = theChip8.getI();
	std::cout << machineI << std::endl;
	unsigned short machinePC = theChip8.getPC();
	std::cout << machinePC << std::endl;
	unsigned short* machineStack = theChip8.getStack();
	unsigned short machineSP = theChip8.getStackPointer();
	unsigned short machineDT = theChip8.getDelayTimer();
	unsigned short machineST = theChip8.getSoundTimer();
	unsigned char* machineScreen = theChip8.getScreen();
	file.write((char*)&machineMemory[0], 4096);
	file.write((char*)&machineRegisters[0], 16);
	file.write((char*)machineI, sizeof(machineI));
	file.write((char*)machinePC, sizeof(machinePC));
	file.write((char*)&machineStack[0], 16*sizeof(machineI));
	file.write((char*)machineSP, sizeof(machineSP));
	file.write((char*)machineDT, sizeof(machineDT));
	file.write((char*)machineST, sizeof(machineST));
	file.write((char*)&machineScreen[0], 2048);
	file.close();
}

void cMain::loadChip8State(std::string filename) {
	std::ifstream file(filename.c_str(), std::ios::binary);

	unsigned char machineState[6208];
	for (int i = 0; i < 6208; i++) {
		machineState[i] = 0;
	}

	file.read((char*)&machineState[0], 6208);
	file.close();

	theChip8.stopCycle();
	theChip8.initialize();
	theChip8.loadState(machineState);
}

void cMain::drawScreen() {
	unsigned char* screenData = theChip8.getScreen();

	SDL_RenderClear(sdlRenderer);
	int windowWidth = 0;
	int windowHeight = 0;
	SDL_GetWindowSize(sdlWindow, &windowWidth, &windowHeight);
	const int pixelWidth = windowWidth / 64;
	const int pixelHeight = windowHeight / 32;

	SDL_SetRenderDrawColor(sdlRenderer, pColor[0], pColor[1], pColor[2], 0x0);

	for (int i = 0; i < 2048; i++) {
		if (screenData[i] != 0) {
			SDL_Rect rect;
			rect.y = (i / 64) * pixelHeight;
			rect.x = (i - ((i / 64) * 64)) * pixelWidth;
			rect.w = pixelWidth;
			rect.h = pixelHeight;

			SDL_RenderFillRect(sdlRenderer, &rect);
		}
	}
	SDL_RenderPresent(sdlRenderer);
	SDL_SetRenderDrawColor(sdlRenderer, bColor[0], bColor[1], bColor[2], 0x0);
	theChip8.setDrawFlag(false);
}