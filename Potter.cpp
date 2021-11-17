#include "Potter.h"

Potter::Potter()
{
	setCharWeSee('P');
	eatenDiamonds=0;
	eatenPerg=0;
	dead=0;
}

void Potter::seteatenPerg(int perg)
{
	eatenPerg=perg;
}

void Potter::seteatenDiamonds(int diamond)
{
	eatenDiamonds=diamond;
}

void Potter::setDead(int d)
{
	dead=d;
}

int Potter::geteatenDiamonds()
{
	return eatenDiamonds;
}

int Potter::geteatenPerg()
{
	return eatenPerg;
}

int Potter::getDead()
{
	return dead;
}

int *Potter::Move(vector<string> map, int ch)
{
	int *pos;
	pos=new int[2];
	pos=getPos();
	
	if (ch==UP)
	{
		if(map[pos[0]-1][pos[1]]==' ')
			pos[0]--;
		if(map[pos[0]-1][pos[1]]=='@')
		{
			eatenDiamonds++;
			pos[0]--;
		}
		if(map[pos[0]-1][pos[1]]=='#')
		{
			eatenPerg=1;
			pos[0]--;
		}
		if(map[pos[0]-1][pos[1]]=='T' || map[pos[0]-1][pos[1]]=='G')
		{
			dead=1;
			pos[0]--;
		}
	}	
	if (ch==DOWN)
	{
		if(map[pos[0]+1][pos[1]]==' ')
			pos[0]++;
		if(map[pos[0]+1][pos[1]]=='@')
		{
			eatenDiamonds++;
			pos[0]++;
		}
		if(map[pos[0]+1][pos[1]]=='#')
		{
			eatenPerg=1;
			pos[0]++;
		}
		if(map[pos[0]+1][pos[1]]=='T' || map[pos[0]+1][pos[1]]=='G')
		{
			dead=1;
			pos[0]++;
		}
	}
	if (ch==LEFT)
	{
		if(map[pos[0]][pos[1]-1]==' ')
			pos[1]--;
		if(map[pos[0]][pos[1]-1]=='@')
		{
			eatenDiamonds++;
			pos[1]--;
		}
		if(map[pos[0]][pos[1]-1]=='#')
		{
			eatenPerg=1;
			pos[1]--;
		}
		if(map[pos[0]][pos[1]-1]=='T' || map[pos[0]][pos[1]-1]=='G')
		{
			dead=1;
			pos[1]--;
		}
	}
	if (ch==RIGHT)
	{
		if(map[pos[0]][pos[1]+1]==' ')
			pos[1]++;
		if(map[pos[0]][pos[1]+1]=='@')
		{
			eatenDiamonds++;
			pos[1]++;
		}
		if(map[pos[0]][pos[1]+1]=='#')
		{
			eatenPerg=1;
			pos[1]++;
		}
		if(map[pos[0]][pos[1]+1]=='T' || map[pos[0]][pos[1]+1]=='G')
		{
			dead=1;
			pos[1]++;
		}
	}
	setPos(pos);
				
	return pos;
}
