#include "Moving.h"
#include <time.h>

Moving::Moving()
{
	srand(time(0));
	Pos=new int[2];
}

Moving::~Moving()
{
	delete Pos;
}

void Moving::setCharWeSee(char ch)
{
	CharWeSee=ch;
}

void Moving::setPos(int *pos)
{
	Pos=pos;
}

int *Moving::getPos()
{
	return Pos;
}

char Moving::getCharWeSee()
{
	return CharWeSee;
}

void Moving::StartPos()
{
	int lines=Map.size();
	int coll=Map[0].size();
	int flag=0;
	
	while(!flag)
	{
		Pos[0]=rand() % (lines-2) + 1;
		Pos[1]=rand() % (coll-2) + 1;
		if (Map[Pos[0]][Pos[1]]==' ')
			flag=1;
	}
	Map[Pos[0]][Pos[1]]=CharWeSee;
}

void Moving::setMap(vector<string> map)
{
	Map=map;
}

vector<string> Moving::getMap()
{
	return Map;
}
