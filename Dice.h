#pragma once
#include "Cell.h"
#include<time.h>
using namespace std;
class Dice
{
public:
	
	int diceno[3] = { 0 };
	void reset()
	{
		for (int i = 0; i < 3; i++)
		{
			diceno[i] = 0;
		}
	}
	bool isempty()
	{
		int sum = 0;
		for (int i = 0; i < 3; i++)
		{
			sum = diceno[i] + sum;
			
		}
		if (sum == 0)
		{
			return true;
		}
		return false;
	}
	

	int randomgen()
	{
		int dice = 1 + rand() % 6;
		return dice;
	}
	void rolladice()
	{
		int Baazi = 0;
		for (int i = 0; i < 3; i++)
		{
			Baazi = randomgen();
			diceno[i] = Baazi;
			if (Baazi < 6)
				break;
		}
	}

	int DiceNoAtIndex(int i)
	{
		return diceno[i];
	}
};




