#pragma once

#include"Token.h"
#include"Position.h"
class GreenToken:public Token
{

public:
	GreenToken(colors C, int HomeIndex, int IntialCell, int Jumpto):Token(C,HomeIndex,IntialCell, Jumpto){}
	virtual void DrawToken(Position p)
	{
		setfillstyle(SOLID_FILL, GREEN);
		fillellipse(p.x, p.y, 18, 18);

	}

};

