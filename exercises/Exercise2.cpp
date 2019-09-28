#include "pch.h"
#include "Exercise2.h"
#include "Util.h"

Exercise2::Exercise2()
{
	while (true)
	{
		string input;
		vector<int> parsedInput = vector<int>();

		getline(cin, input);

		std::istringstream iss(input);

		int n;
		while (iss >> n) parsedInput.push_back(n);

		std::cout << towerBreakers(parsedInput[0], parsedInput[1]) << endl;
	}
}


int Exercise2::towerBreakers(int n, int m)
{
	if (n != 1)
	{
		int winner = 2;
		for (int j = n - 1; j > 0; j--)
		{
			for (int i = m - 1; i > 0; i--)
			{
				if (m%i == 0)
				{
					if (towerBreakers(j, i) == 2)
						winner = 1;
				}
			}
		}
		return winner;
	}
	else
		return 1;
}

Exercise2::~Exercise2()
{
}
