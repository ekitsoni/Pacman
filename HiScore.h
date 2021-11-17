#include <iostream>
#include <string>
#include <vector>

using namespace std;

class HiScore
{
	private:
		vector<string> Names;
		vector<int> Scores;
	public:
		HiScore();
		vector<string> getNames();
		vector<int> getScores();
		int check(int);
		void operator<<(string);
		void operator<<(int);
};
