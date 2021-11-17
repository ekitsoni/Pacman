#include <iostream>
#include <string>
#include "Moving.h"
using namespace std;

class Gnome : public Moving
{
	private:
		int atePotter;
	public:
		Gnome();
		int getatePotter();
		void setatePotter(int);
		int *Move(vector<vector<int>>,int);
};

