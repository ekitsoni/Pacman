#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "HiScore.h"
#include "Potter.h"
#include "Gnome.h"
#include "Traal.h"

using namespace std;

class Engine
{
	private:
		vector<string> Map;
		vector<vector<int>> monsterMap;
		int atePerg;
		int score;
		HiScore hiScore;
		Potter potter;
		Gnome gnome;
		Traal traal;
	public:
		Engine();
		Engine(ifstream&);
		void Menu();
		void CreateCreatures();
		void printMap();
		void CreateDiamonds();
		void CreatePerg();
		void LetsPlay();
		void printHiScore();
		void deleteOldGame();
		void CreateMonsterMap();
};
