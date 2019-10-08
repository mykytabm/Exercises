#pragma once
#include "pch.h"
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>


/**
* Implement a program in C++ using pointers and arrays to read a number N of integers,
* then print the N numbers sorted by value (higher values first).
* The N value and the N numbers shall be read using scanf and manually inputted by the user.
*/
void ReadAndSortNumbers()
{
	int arrayLen = 0;
	scanf_s("%d\n", &arrayLen);
	int* numArray = new int[arrayLen];
	for (int i = 0; i < arrayLen; i++)
	{
		scanf_s(" %d", &numArray[i]);
	}
	std::sort(numArray, numArray + arrayLen, std::greater<int>());
	for (int i = 0; i < arrayLen; i++)
	{
		std::cout << numArray[i] << std::endl;
	}
}



/**
* Implement a program in C++ in which a indefinite sequence of strings are read using scanf
* until the value “quit” is entered. By the end, the number of strings with the same size
* must be printed out. Additionally, it is not allowed to input strings with more than 30
* characters - if the user does so, the program must simply ignore the value and wait for
* the next one.
*/
void ReadStringsAndPrintMaxSize()
{
	char input[50] = "";
	std::string s = "";
	int lengthCounter[31];

	for (int i = 0; i < 31; i++)
	{
		lengthCounter[i] = 0;
	}

	while (true)
	{
		if (scanf_s("%30s", input, 31) != EOF)
		{
			s = input;
			std::cout << s.length() << std::endl;
			if ((s.length() > 30) || (s == "quit"))
			{
				break;
			}
			lengthCounter[s.length()] += 1;
		}
	}

	for (int i = 0; i < 31; i++)
	{
		if (lengthCounter[i] > 0)
		{
			std::cout << lengthCounter[i] << " strings of size " << i << std::endl;
		}
	}
}




int main()
{
	ReadStringsAndPrintMaxSize();
	return 0;
}




