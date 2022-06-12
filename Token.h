#pragma once
#include "graphics.h"
#include"Position.h"
enum Color { Red, Blue, Green, Yellow, White, Black };

// as sarfaraz said.....max players can be 6

class Token 
{
public:
	colors color;
	int initialLocation;
	int HomeCell;
	int NoOfStepsTaken;
	int TokenLocationOnBoard;
	bool Homestatus;
	int JumpStep;
	int JumpIndex;
public:
	bool hasKilled;
	Token()
	{

	}
	
	Token(colors C, int HomeIndex, int IntialCell, int Jumpto)
	{
		color = C;
		NoOfStepsTaken = 0;
		HomeCell = HomeIndex;
		initialLocation = IntialCell;
		TokenLocationOnBoard = HomeIndex;
		Homestatus = true;
		JumpStep = 50;
		JumpIndex = Jumpto;
		hasKilled=false;
	}
	
	virtual void DrawToken(Position P)
	{

	}
	virtual void SetStatus(char s)
	{
	
	}
	
	colors getColor()
	{
		return color;
	}
	
	int getJumpIndex()
	{
		return JumpIndex;
	}
	
	void ChangeSteps(int Steps)
	{
		NoOfStepsTaken = Steps;
	}
	int getJumpStep()
	{
		return JumpStep;
	}
	
	bool isAtHome()
	{
		return Homestatus;
	}

	int StepsTaken()
	{
		return NoOfStepsTaken;
	}
	
	void addSteps(int Steps)
	{
		NoOfStepsTaken+=Steps;
	}
	int getHomeIndex()
	{
		return HomeCell;
	}
	
	void Killed()
	{
		NoOfStepsTaken = 0;
		TokenLocationOnBoard = HomeCell;
		Homestatus = true;
	}
	
	int getInitialLocation()
	{
		return initialLocation;
	}
	
	void changeHomeStatus()
	{
		if (Homestatus)
			Homestatus = false;
		else
			{Homestatus = true;
                        NoOfStepsTaken = 0;
			hasKilled= false;}
	}
	
};

