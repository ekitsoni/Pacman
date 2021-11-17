#include "Engine.h"
#include <ncurses.h>
#define DiamondNum 10
#define DOWN 0402
#define UP 0403
#define LEFT 0404
#define RIGHT 0405
#define ESC 27
#define SPACE 32

Engine::Engine()
{}

Engine::Engine(ifstream &fin)
{
	atePerg=0;
	score=0;
	string ch;
	while(getline(fin, ch))
	{ 
		Map.push_back(ch+"\n");
    	}
    	Menu();
}

void Engine::Menu()
{
	int ch;
	
	initscr();
	keypad(stdscr,TRUE);
	clear();
	noecho();
	cbreak();
	printw("Menu:\nPress P to Play.\nPress H to see High Score.\nPress ESC to exit.\n");
	refresh();
	
    	ch=getch();
    	while(ch!=ESC)
    	{
    		if(ch==80) //P
    		{
    			LetsPlay();
    		}
    		if(ch==72) //H
    		{
    			printHiScore();
    		}
    		refresh();
    		ch=getch();
    		
    	}
    	clear();
    	refresh();
	endwin();
	exit(0);
}

void Engine::CreateCreatures()
{
	potter.setMap(Map);
	potter.StartPos();
	Map[potter.getPos()[0]][potter.getPos()[1]]=potter.getCharWeSee();
	
	gnome.setMap(Map);
	gnome.StartPos();
	Map[gnome.getPos()[0]][gnome.getPos()[1]]=gnome.getCharWeSee();
	
	traal.setMap(Map);
	traal.StartPos();
	Map[traal.getPos()[0]][traal.getPos()[1]]=traal.getCharWeSee();
}

void Engine::CreateDiamonds()
{
	int lines=Map.size();
	int coll=Map[0].size();
	int flag=0;
	int x,y;
	
	for(int i=0; i<DiamondNum; i++)
	{
		while(!flag)
		{
			x=rand() % (lines-2) + 1;
			y=rand() % (coll-2) + 1;
			if(Map[x][y]==' ')
			{
				flag=1;
				Map[x][y]='@';
			}
		}
		flag=0;
	}
}

void Engine::CreatePerg()
{
	int lines=Map.size();
	int coll=Map[0].size();
	int flag=0;
	int x,y;
	
	for(int i=0; i<1; i++)
	{
		while(!flag)
		{
			x=rand() % (lines-2) + 1;
			y=rand() % (coll-2) + 1;
			if(Map[x][y]==' ')
			{
				flag=1;
				Map[x][y]='#';
			}
		}
		flag=0;
	}
	move(x,y);
    	addch('#');
}

void Engine::LetsPlay()
{
	int ch;
	string name;
	
	int *pottPos;
	pottPos=new int[2];
	pottPos[0]=0;
	pottPos[1]=0;
	int x=potter.getPos()[0];
	int y=potter.getPos()[1];
	
	int *gnomePos;
	gnomePos=new int[2];
	
	int *traalPos;
	traalPos=new int[2];
	
	
	clear();
	
	printw("Enter your name: ");
	while(ch!='\n')
	{
		name.push_back(ch);
		ch=getch();
		addch(ch);
	}
	
	CreateCreatures();
	CreateDiamonds();
	CreateMonsterMap();
	
	clear();
    	printMap();
    	ch=getch();
    	while(ch!=ESC)
    	{
    		refresh();
    		
    		move(potter.getPos()[0],potter.getPos()[1]);
    		addch(' ');
    		Map[potter.getPos()[0]][potter.getPos()[1]]=' ';
    		pottPos=potter.Move(Map,ch);
    		move(pottPos[0],pottPos[1]);
    		printw("%c",potter.getCharWeSee());
    		Map[pottPos[0]][pottPos[1]]=potter.getCharWeSee();
    		
    		if(potter.getPos()[0]!=x || potter.getPos()[1]!=y || ch==32)
    		{
    			CreateMonsterMap();
    			
    			Map[gnome.getPos()[0]][gnome.getPos()[1]]=' ';
    			move(gnome.getPos()[0],gnome.getPos()[1]);
    			addch(' ');
    			gnomePos=gnome.Move(monsterMap,ch);
    			move(gnomePos[0],gnomePos[1]);
    			addch(gnome.getCharWeSee());
    			Map[gnomePos[0]][gnomePos[1]]=gnome.getCharWeSee();
    		
    			Map[traal.getPos()[0]][traal.getPos()[1]]=' ';
    			move(traal.getPos()[0],traal.getPos()[1]);
    			addch(' ');
    			traalPos=traal.Move(monsterMap,ch);
    			move(traalPos[0],traalPos[1]);
    			addch(traal.getCharWeSee());
    			Map[traalPos[0]][traalPos[1]]=traal.getCharWeSee();
    			
    		}
    		monsterMap.clear();
    		
    		x=potter.getPos()[0];
		y=potter.getPos()[1];
		score=potter.geteatenDiamonds()*10+potter.geteatenPerg()*100;
		
    		if(potter.geteatenDiamonds()==DiamondNum && atePerg==0)
    		{
    			CreatePerg();
    			atePerg=1;
    		}
    		if(potter.geteatenPerg()==1)
    		{
    			clear();
	    		refresh();
	    		printw("You won! Your score was %d.\n\nPress ESC to exit.",score);
	    		if(hiScore.check(score)>-2)
	    		{
	    			hiScore << name ;
	    			hiScore << score ;
	    		}
	    		deleteOldGame();
	    		while(ch!=ESC)
	    		{
	    			ch=getch();
	    		}
	    		Menu();
    		}
    		if(gnome.getatePotter()==1 || traal.getatePotter()==1 || potter.getDead()==1)
    		{
    			clear();
	    		refresh();
	    		printw("You lost! Your score was %d.\n\nPress ESC to exit.",score);
	    		if(hiScore.check(score)>-2)
	    		{
	    			hiScore << name ;
	    			hiScore << score ;
	    		}
	    		deleteOldGame();
	    		while(ch!=ESC)
	    		{
	    			ch=getch();
	    		}
	    		Menu();
    		}
    		move(Map.size(),0);
    		refresh();
    		ch=getch();
    	}
    	deleteOldGame();
    	clear();
    	refresh();
	Menu();
}

void Engine::CreateMonsterMap()
{
	int moves=1;
	
	for(int i=0; i<Map.size(); i++)
    	{
    		vector<int> x;
    		for(int j=0; j<Map[i].size(); j++)
    		{
			
			if(Map[i][j]=='T')
				x.push_back(-1);
			else if(Map[i][j]=='G')
				x.push_back(-1);
			else if(Map[i][j]==' ')
				x.push_back(-1);
			else if(Map[i][j]=='P')
				x.push_back(-2);
			else
				x.push_back(0);
		}
		monsterMap.push_back(x);
    	}
	
	if(monsterMap[ potter.getPos()[0]-1 ][ potter.getPos()[1] ]!=0)
		monsterMap[ potter.getPos()[0]-1 ][ potter.getPos()[1] ]=moves;
	if(monsterMap[ potter.getPos()[0]+1 ][ potter.getPos()[1] ]!=0)
		monsterMap[ potter.getPos()[0]+1 ][ potter.getPos()[1] ]=moves;
	if(monsterMap[ potter.getPos()[0] ][ potter.getPos()[1]-1 ]!=0)
		monsterMap[ potter.getPos()[0] ][ potter.getPos()[1]-1 ]=moves;
	if(monsterMap[ potter.getPos()[0] ][ potter.getPos()[1]+1 ]!=0)
		monsterMap[ potter.getPos()[0] ][ potter.getPos()[1]+1 ]=moves;
	for(int x=0; x<(monsterMap.size()*monsterMap[0].size()) ; x++)
	{
		moves++;
		for(int i=1; i<monsterMap.size()-1; i++)
    		{
    			for(int j=1; j<monsterMap[i].size()-1; j++)
    			{
    				if(monsterMap[i][j]==-1)
    				{
	    				if(monsterMap[ i-1 ][ j ]==moves-1)
			    			monsterMap[ i ][ j ]=moves;
			    		if(monsterMap[ i+1 ][ j ]==moves-1)
						monsterMap[ i ][ j ]=moves;
					if(monsterMap[ i ][ j-1 ]==moves-1)
						monsterMap[ i ][ j ]=moves;
					if(monsterMap[ i ][ j+1 ]==moves-1)
						monsterMap[ i ][ j ]=moves;
					
				}
			}
		}
    	}
}


void Engine::deleteOldGame()
{
	for(int i=0; i<Map.size(); i++)
    	{
    		for(int j=0; j<Map[i].size()-2; j++)
    		{
			if(Map[i][j]!='*')
				Map[i][j]=' ';
		}
    	}
    	atePerg=0;
    	score=0;
    	potter.seteatenPerg(0);
    	potter.seteatenDiamonds(0);
    	potter.setDead(0);
    	gnome.setatePotter(0);
    	traal.setatePotter(0);
    	
}

void Engine::printMap()
{
	for(int i=0; i<Map.size(); i++)
    		for(int j=0; j<Map[i].size(); j++)
			if(Map[i][j]=='*')
				addch('\xDB');
			else if(Map[i][j]=='P')
				addch('P');
			else if(Map[i][j]=='T')
				addch('T');
			else if(Map[i][j]=='G')
				addch('G');
			else if(Map[i][j]=='@')
				addch('@');
			else if(Map[i][j]=='#')
				addch('#');
			else if(Map[i][j]=='\n')
				addch('\n');
			else if(Map[i][j]==' ')
				addch(' ');
    	
}

void Engine::printHiScore()
{
	int ch;
	clear();
	refresh();
	
	for(int i=0; i<hiScore.getScores().size(); i++)
    	{
    		printw("Name: %s",hiScore.getNames()[i]);
		printw(" Score: %d\n",hiScore.getScores()[i]);
    	}
    	printw("\n\nPress ESC to exit.");
    	refresh();
    	ch=getch();
    	while(ch!=ESC)
    		ch=getch();
    	Menu();
}
