#include "HiScore.h"

HiScore::HiScore()
{}

vector<string> HiScore::getNames()
{
	return Names;
}

vector<int> HiScore::getScores()
{
	return Scores;
}

int HiScore::check(int score)
{
	int flag=-2;

	if(Scores.size()==5)
	{
		for(int i=0; i<Scores.size(); i++)
		{
			if(score>Scores[i])
			{
				flag=i;
			}
		}
		Scores.erase(Scores.begin()+flag); 
	}
	else
		flag=-1;
	
	return flag;
}

void HiScore::operator<<(string name)
{
	Names.push_back(name);
}

void HiScore::operator<<(int score)
{
	Scores.push_back(score);
}
