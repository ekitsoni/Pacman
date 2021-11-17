#include <iostream>
#include <vector>
#include <fstream>
#include <stdlib.h>
#include <ncurses.h>
#include "Engine.h"
using namespace std;

int main(int argc, char** argv) 
{
	try
	{
		ifstream fin(argv[1]);
		if(fin.is_open() == false)
		{
			throw 1;
		}
		
		Engine En(fin);
		fin.close();
	}
	catch(int i)
	{
		cout<< "Could not open file. Error " << i << endl;
	}
	return 0;
}
