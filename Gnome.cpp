#include "Gnome.h"

Gnome::Gnome()
{
	setCharWeSee('G');
	atePotter=0;
}

int Gnome::getatePotter()
{
	return atePotter;
}

void Gnome::setatePotter(int ate)
{
	atePotter=ate;
}

int *Gnome::Move(vector<vector<int>> map,int ch) 
{
	int *now;
	now=new int[2];
	now=getPos();
	
	int *up;
	up=new int[2];
	up[0]=getPos()[0]-1;
	up[1]=getPos()[1];
	
	int *down;
	down=new int[2];
	down[0]=getPos()[0]+1;
	down[1]=getPos()[1];
	
	int *left;
	left=new int[2];
	left[0]=getPos()[0];
	left[1]=getPos()[1]-1;
	
	int *right;
	right=new int[2];
	right[0]=getPos()[0];
	right[1]=getPos()[1]+1;
	
	int flag=0;
	
	if(ch==32 && map[up[0]][up[1]]==-2)
		atePotter=1;
	else if(ch==32 && map[down[0]][down[1]]==-2)
		atePotter=1;
	else if(ch==32 && map[left[0]][left[1]]==-2)
		atePotter=1;
	else if(ch==32 && map[right[0]][right[1]]==-2)
		atePotter=1;	
	else if(map[now[0]][now[1]]-1>0 && map[up[0]][up[1]]==map[now[0]][now[1]]-1 && map[up[0]][up[1]]!=0)
		setPos(up);
	else if (map[now[0]][now[1]]-1>0 && map[down[0]][down[1]]==map[now[0]][now[1]]-1 && map[down[0]][down[1]]!=0)
		setPos(down);
	else if (map[now[0]][now[1]]-1>0 && map[left[0]][left[1]]==map[now[0]][now[1]]-1 && map[left[0]][left[1]]!=0)
		setPos(left);
	else if (map[now[0]][now[1]]-1>0 && map[right[0]][right[1]]==map[now[0]][now[1]]-1 && map[right[0]][right[1]]!=0)
		setPos(right);
	
	return getPos();
}
