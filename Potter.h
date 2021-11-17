#include "Moving.h"
#include <iostream>
#include <string>
using namespace std;

class Potter : public Moving
{
	private:
		int eatenDiamonds;
		int eatenPerg;
		int dead;
	public:
		Potter();
		void seteatenPerg(int);
		void seteatenDiamonds(int);
		void setDead(int);
		int geteatenDiamonds();
		int geteatenPerg();
		int getDead();
		int *Move(vector<string>,int);
};
