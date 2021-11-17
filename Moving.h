#ifndef Moving_h
#define Moving_h
#include <iostream>
#include <string>
#include <vector>
#define DOWN 0402
#define UP 0403
#define LEFT 0404
#define RIGHT 0405
#define ESC 27
using namespace std;

class Moving
{
	private:
		char CharWeSee;
		int *Pos;
		vector<string> Map;
	public:
		Moving();
		~Moving();
		void setCharWeSee(char);
		void setMap(vector<string>);
		void setPos(int*);
		int *getPos();
		char getCharWeSee();
		vector<string> getMap();
		void StartPos();
};
#endif
