#pragma once
#include "Player.h"
class Cell
{
public:
	Position TopLeft, ButtomRight;
	bool Issave = false;
	colors Cl;// colors is a enum in graphics.h
	int index=0;
	Cell() { TopLeft.x = ButtomRight.x = TopLeft.y = ButtomRight.y = 0; }
	Cell(Position T,Position B,colors C) :TopLeft(T),ButtomRight(B),Cl(C){}
	Position getTL() { return TopLeft; }
	Position getBR() { return ButtomRight; }
	bool BoxConfirmation(int x, int y)
	{
		return ((x >= TopLeft.x && x <= ButtomRight.x) && (y >= TopLeft.y && y <= ButtomRight.y));
	}
	Position getcellcenter(Position TL,Position BR)
	{
		Position P((TL.x + BR.x )/ 2, (TL.y + BR.y)/2);
		return P;
	}
	void setcellPos(Position T, Position B, colors c)
	{
		TopLeft = T, ButtomRight = B, Cl = c;
	}

	void draw()
	{
		Position p=this->getTL();

		int d[10] = { p.x,p.y,p.x + 46,p.y,p.x + 46 , p.y + 46,p.x,p.y + 46,p.x,p.y };
		setfillstyle(SOLID_FILL, Cl);
		fillpoly(5, d);
	}

	~Cell() {}
};



