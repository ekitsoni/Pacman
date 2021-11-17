#include <iostream>
#include <string>
#include "Moving.h"
using namespace std;

class Traal : public Moving
{
	private:
		int atePotter;
	public:
		Traal();
		int getatePotter();
		void setatePotter(int);
		int *Move(vector<vector<int>>,int);
};

