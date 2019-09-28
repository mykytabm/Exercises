#include "pch.h"
#include "Exercise1.h"

using namespace std;


int movecoords[2][4] =
{
{-2,-2,+1,-1},
{+1,-1,-2,-2}
};



bool Exercise1::MakeMove(int x, int y)
{
	bool win = false;
	if ((x >= 1 && x <= 15) && (y >= 1 && y <= 15)) {

		for (int i = 0; i < 4; i++)
		{
			auto newX = x + movecoords[0][i];
			auto newY = y + movecoords[1][i];
			if (!MakeMove(newX, newY)) win = true;
		}
		return win;
	}
	else return true;
}

Exercise1::Exercise1()
{
	while (true)
	{
		string input;
		vector<int> parsedInput = vector<int>();

		getline(cin, input);

		std::istringstream iss(input);

		int n;
		while (iss >> n) parsedInput.push_back(n);
		if (parsedInput.size() > 1)
			cout << (MakeMove(parsedInput[0], parsedInput[1]) ? "First" : "Second") << endl;
	}
}


Exercise1::~Exercise1()
{
}
