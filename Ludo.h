#pragma once
#include<vector>
#include "Dice.h"
#include "Grid.h"
#include<string.h>
#include"GreenToken.h"
#include"RedToken.h"
#include"YellowToken.h"
#include<iostream>
#include"BlueToken.h"
using namespace std;
class Ludo :public Player,public Cell
{
protected:
	Grid* box = new Grid[92];

	Player** Players;
	//Player Players[MaxPlayers];
	int NoOfPlayers, Turn, MaxNoSteps, WC;
	colors turncolor;
	int DU;
	int NOC=0;// number of cells
	Cell C[96];
	Position P;
	colors cc = WHITE;
	Dice dice;
	int HCN = 76;
	vector <int> WinPlayers;
	int SpecialBoxes[8] = { 34,42,47,3,8,16,21,29 };
	/*
	 YELLOW
									          
											  0 6  12 
											  1 7  13 S
											S 2 8  14 
											  3 9  15 
						G					  4 10 16
						R		S			  5 11 17           S			B
						E	36 37 38 39 40 41	 72	   18 19 20 21 22 23	L
						E	42 43 44 45 46 47 75	73 24 25 26 27 28 29	U
						N	48 49 50 51 52 53	 74	   30 31 32 33 34 35	E
							      S           54 60 66             S
											  55 61 67
											  56 62 68
											  57 63 69 S
											S 58 64 70
											  59 65 71
											  
											  R  E  D
	*/
	

public:
	Ludo(){}
	

	void InitSpecific()
	{
		for(int i=0;i<4;++i)
		{
			
		}
	}
	void InitBoard()
	{
			// We don't really need this?
			// yes we do not need it
	}

	//Ludo(int NOP)
	//{
	//	Players = new Player[NOP];
	//	Grid = new char*[1];
	//	Grid[0] = new char[100]; // How many total boxes are there? Please specify according to the NOP.
	//}

	//void UpdateBoard(Token T)
	//{
	//	Grid[0][T.TokenLocationOnBoard] = '-';
	//	//Grid[0][T.TokenLocationOnBoard + Players[Turn].DICE.DiceNoAtIndex(DU)];
	//}

	void ChangeTurn()
	{
		if (NoOfPlayers ==4 )
		{
			bool Continue = true;
			do
			{
				Continue = false;
				++Turn;
				if (Turn == NoOfPlayers)
					Turn = 0;
				for (int i = 0; i < WinPlayers.size(); i++)
				{
					if (Turn == WinPlayers[i])
					{
						Continue = true; break;
					}

				}

			} while (Continue);

		}
		else
		{
			Turn += 2;
			if (Turn == 4)
				Turn = 0;
		}
			
		inttocolor();
	}

	void DisplayPlayerMsg()
	{
		if (Turn == 0)
		{
			outtextxy(750, 50, "Green's turn");
		}
		else if (Turn == 1)
		{
			outtextxy(750, 50, "Gray's turn");
		}
		else if (Turn == 2)
		{
			outtextxy(750, 50, "Blue's turn");
		}
		else 
		{
			outtextxy(750, 50, "Red's turn");
		}
		// Where should we display the which player's turn is it right now?
	}

	/*void UpdatePlayerList(int Turn)
	{
		Player** NewPlayer = new Player*[NoOfPlayers - WC]; // Provided WC has already been updated. Please take note
		int z = 0;
		for (int i = 0; i < NoOfPlayers - WC; i++)
		{
			if (i == Turn)
				continue;
			NewPlayer[z] = Players[i];
			++z;
		}
		delete[]Players;
		Players = NewPlayer;
	}*/
	
	void DisplayResult()
	{
		string wincolor;
		int x;
		for (int i = 0; i < WinPlayers.size(); ++i)
		{
			x = WinPlayers[i];
			if (x == 0)
			{
				wincolor = "green";
			}
			else if (x == 1)
			{
				wincolor = "grey";
			}
			else if (x == 2)
			{
				wincolor = "blue";
			}
			else
			{
				wincolor = "red";
			}
			cout << wincolor << " has got " << i + 1 << "position\n";
		}
		//Should we display "Player Blue Won"???? And at which place?
		// we can increase the init window size and can show both dice roll and win msg there.
	}
	void mouseclick(Position& p)
	{
		int Dim = 80; while (!ismouseclick(WM_LBUTTONDOWN)) {} getmouseclick(WM_LBUTTONDOWN, p.x, p.y); 
	}
	void DisplayBoard()
	{
		initwindow(1300, 800, "LUDO");
		int a[10]= { 0,0,276,0,276,276,0,276,0,0};
		setfillstyle(SOLID_FILL, GREEN);
		fillpoly(5, a);
		int a1[10] = { 0+30,0+30,276-30,0+30,276-30,276-30,0+30,276-30,0+30,0+30 };
		int h[10] = { 37,37,83,37,83,83,37,83,37,37 };// points of home cell of green 
		C[HCN].setcellPos(Position(37, 37), Position(83, 83), LIGHTGREEN); HCN++;
		drawpoly(5, h);
		int j[10] = { 193,37,239,37,239,83,193,83,193,37 };// points of home cell of green 
		C[HCN].setcellPos(Position(193,37), Position(239,83), LIGHTGREEN); HCN++;
		drawpoly(5, j);
		int k[10] = { 37,193,83,193,83,239,37,239,37,193};// points of home cell of green 
		C[HCN].setcellPos(Position(37, 193), Position(83, 239), LIGHTGREEN); HCN++;
		drawpoly(5, k);
		int l[10] = { 193,193,239,193,239,239,193,239,193,193};// points of home cell of green 
		C[HCN].setcellPos(Position(193, 193), Position(239, 239), LIGHTGREEN); HCN++;
		drawpoly(5, l);
		setfillstyle(SOLID_FILL, LIGHTGREEN);
		fillpoly(5, a1);
		//setfillstyle(SOLID_FILL, GREEN);
		//fillellipse(60, 60, 20, 20);
		//fillellipse(216, 60, 20, 20);
		//fillellipse(60, 216, 20, 20);
		//fillellipse(216, 216, 20, 20);
/// GREEN IS ENDED.

		int b[10] = { 414,0,690,0,690,276,414,276,414,0 };
		setfillstyle(SOLID_FILL, DARKGRAY);
		fillpoly(5, b);



		int m[10] = { 451,37,497,37,497,83,451,83,451,37 };// points of home cell of green 
		C[HCN].setcellPos(Position(451, 37), Position(497, 83), LIGHTGRAY); HCN++;
		drawpoly(5, m);
		int n[10] = { 607,37,653,37,653,83,607,83,607,37 };// points of home cell of green 
		C[HCN].setcellPos(Position(607, 37), Position(653, 83), LIGHTGRAY); HCN++;
		drawpoly(5, n);
		int o[10] = { 451,193,497,193,497,239,451,239,451,193 };// points of home cell of green 
		C[HCN].setcellPos(Position(451, 193), Position(497, 239), LIGHTGRAY); HCN++;
		drawpoly(5, o);
		int p[10] = { 607,193,653,193,653,239,607,239,607,193 };// points of home cell of green 
		C[HCN].setcellPos(Position(607, 193), Position(653, 239), LIGHTGRAY); HCN++;
		drawpoly(5, p);
		
		int b1[10] = { 414 + 30,0 + 30,690 - 30,0 + 30,690 - 30,276 - 30,414 + 30,276 - 30,414 + 30,0 + 30 };
		setfillstyle(SOLID_FILL, LIGHTGRAY);
		fillpoly(5, b1);


		/*setfillstyle(SOLID_FILL, DARKGRAY);

		fillellipse(474, 60, 20, 20);
		fillellipse(630, 60, 20, 20);
		fillellipse(474, 216, 20, 20);
		fillellipse(630, 216, 20, 20);*/
/// DARKGRAY HAS ENDED




		int d[10] = { 414,414,690,414,690,690,414,690,414,414 };
		setfillstyle(SOLID_FILL, BLUE);
		fillpoly(5, d);




		
		int A[10] = { 451,451,497,451,497,497,451,497,451,451 };// points of home cell of green 
		C[HCN].setcellPos(Position(451, 451), Position(497, 497), LIGHTBLUE); HCN++;
		drawpoly(5, A);
		int B[10] = { 607,451,653,451,653,497,607,497,607,451 };// points of home cell of green 
		C[HCN].setcellPos(Position(607, 451), Position(653, 497), LIGHTBLUE); HCN++;
		drawpoly(5, B);
		int y[10] = { 451,607,497,607,497,653,451,653,451,607 };// points of home cell of green 
		C[HCN].setcellPos(Position(451, 607), Position(497, 653), LIGHTBLUE); HCN++;
		drawpoly(5, y);
		int z[10] = { 607,607,653,607,653,653,607,653,607,607 };// points of home cell of green 
		C[HCN].setcellPos(Position(607, 607), Position(653, 653), LIGHTBLUE); HCN++;
		drawpoly(5, z);
		
		int d1[10] = { 414 + 30,414 + 30,690 - 30,414 + 30,690 - 30,690 - 30,414 + 30,690 - 30,414 + 30,414 + 30 };
		setfillstyle(SOLID_FILL, LIGHTBLUE);
		fillpoly(5, d1);
		//setfillstyle(SOLID_FILL, BLUE);
		//fillellipse(474, 474, 20, 20);
		//fillellipse(474, 630, 20, 20);
		//fillellipse(630, 474, 20, 20);
		//fillellipse(630, 630, 20, 20);

//BLUE HAS ENDED


		int c[10] = { 0,414,276,414,276,690,0,690,0,414};
		setfillstyle(SOLID_FILL, RED);
		fillpoly(5, c);

		int r[10] = { 37,451,83,451,83,497,37,497,37,451 };// points of home cell of green 
		C[HCN].setcellPos(Position(37, 450), Position(83, 496), LIGHTRED); HCN++;
		drawpoly(5, r);
		int X[10] = { 193,451,239,451,239,497,193,497,193,451 };// points of home cell of green 
		C[HCN].setcellPos(Position(193, 450), Position(239, 496),LIGHTRED); HCN++;
		drawpoly(5, X);
		int Y[10] = { 37,606,83,606,83,652,37,652,37,606 };// points of home cell of green 
		drawpoly(5, Y);
		C[HCN].setcellPos(Position(37, 606), Position(83, 652), LIGHTRED); HCN++;
		int Z[10] = { 193,606,239,606,239,652,193,652,193,606 };// points of home cell of green 
		drawpoly(5, Z);
		C[HCN].setcellPos(Position(193, 606), Position(239, 652), LIGHTRED); HCN++;

		
		int c1[10] = { 0+30,414+30,276-30,414+30,276-30,690-30,0+30,690-30,0+30,414+30 };
		setfillstyle(SOLID_FILL, LIGHTRED);
		fillpoly(5, c1);
		/*setfillstyle(SOLID_FILL, RED);
		fillellipse(216, 474, 20, 20);
		fillellipse(216, 630, 20, 20);
		fillellipse(60, 474, 20, 20);
		fillellipse(60, 630, 20, 20);*/



// RED HAS ENDED
		

		// triangles in the middle
		int T1[8] = {276,276,414,276,345,345,276,276 };
		C[73].setcellPos(Position(345*2, 295*2), Position(0, 0), DARKGRAY);
		
		setfillstyle(SOLID_FILL, DARKGRAY);
		fillpoly(4, T1);
		int T2[8] = { 414,276,414,414,345,345,414,276 };
		C[74].setcellPos(Position(395*2, 345*2), Position(0, 0), BLUE);
		setfillstyle(SOLID_FILL, BLUE);
		fillpoly(4, T2);
		int T3[8] = { 345,345,414,414,276,414,345,345 };
		C[75].setcellPos(Position(345*2, 395*2), Position(0, 0), RED);

		setfillstyle(SOLID_FILL, RED);
		fillpoly(4, T3);
		int T4[8] = { 276,276,345,345,276,414,276,276 };
		C[72].setcellPos(Position(295*2, 345*2), Position(0, 0), GREEN);
	
		setfillstyle(SOLID_FILL, GREEN);

		fillpoly(4, T4);




/*


									BOX INDEX IN THE ARRAY. BETTER SEQUENCE CAN'T BE MAKE
									==> Position of every box is saved ( TopLeft and ButtonRight + color)
									==> box with color are declared as safe spot and their position are saved
									S===> SAFE SPOT, TOTAL BOXES===> 76

											  5 6 7
											  4 8 52
											  3 9  53
											  2 10 54
											  1 11 55
											  0 12 56
							46 47 48 49	50 51 	73  13 14 15 16 17 18
							45 67 68 69 70 71 72 74 61 60 59 58 57 19                    
							44 43 42 41 40 39  75   25 24 23 22 21 20
											38 62 26
											37 63 27	
											36 64 28
											35 65 29
											34 66 30
                                            33 32 31
													
													*/
		cc = BLACK ;


		// GRAY
		NOC = 0;
		int SBN = 52;
		for (int y = 0, k = 0; y < 276; y += 46, k++)
		{
			int a[10] = { 276,230-y,322,230 - y,322,276 - y,276,276 - y,276,230 - y };
			if (k==3)
			{
				cc = DARKGRAY; C[NOC].Issave = true;
			}
			setfillstyle(SOLID_FILL, cc);
			C[NOC].setcellPos(Position(276 , 230 - y), Position(322, 276 - y), cc);
			fillpoly(5, a);
			setfillstyle(SOLID_FILL, BLACK);
			cc = BLACK;
			NOC++;
		}
		
		for (int x = 46,i=1; x < 138; x += 46,i++)
		{
			for (int y = 0,k=0; y < 276; y += 46,k++)
			{
				int a[10] = { 276+x,0 + y,322 + x,0 + y,322 + x,46 + y,276 + x,46+y,276 + x,0+y };
				if ((i == 1 && k > 0))
				{
					cc = DARKGRAY; 
					C[SBN].setcellPos(Position(276 + x, 0 + y), Position(322 + x, 46 + y), cc);
					setfillstyle(SOLID_FILL, cc);

					fillpoly(5, a);

					SBN++;
					cc = BLACK;
					continue;
				}
				if ((i == 2 && k == 1))
				{
					cc = DARKGRAY;
				}
				setfillstyle(SOLID_FILL, cc);
				C[NOC].setcellPos(Position(276 + x, 0 + y), Position(322 + x, 46 + y), cc);
				fillpoly(5, a);
				setfillstyle(SOLID_FILL, BLACK);
				cc = BLACK;
				NOC++;
			}
		}
		
		//blue
		
		for (int x = 0, k = 0; x < 276; x += 46, k++)
		{
			int g[10] = { 414 + x,276,460 + x,276,460 + x,322,414 + x,322,414 + x,276 };

			if ( k == 3 )
			{
				cc = BLUE; C[NOC].Issave = true;
			}
			setfillstyle(SOLID_FILL, cc);
			C[NOC].setcellPos(Position(414 + x, 276), Position(460 + x, 322), cc);
			fillpoly(5, g);
			setfillstyle(SOLID_FILL, BLACK);
			cc = BLACK;
			NOC++;
		}
		cc = BLACK;
		for (int y = 46, i = 1; y < 138; y += 46, i++)
		{
			for (int x = 230, k = 0; x >= 0; x -= 46, k++)
			{
				int g[10] = { 414 + x,276 + y,460 + x,276 + y,460 + x,322 + y,414 + x,322 + y,414 + x,276 + y };

				if ((i == 1 && k != 0))
				{
					cc = BLUE; C[SBN].Issave = true;
					C[SBN].setcellPos(Position(414 + x, 276 + y), Position(460 + x, 322 + y), cc);
					setfillstyle(SOLID_FILL, cc);

					fillpoly(5, g);
					cc = BLACK;
					SBN++;
					continue;
				}
				if ((i == 2 && k == 1))
				{
					cc = BLUE; C[NOC].Issave = true;
				}
				setfillstyle(SOLID_FILL, cc);
				C[NOC].setcellPos(Position(414 + x, 276 + y), Position(460 + x, 322 + y), cc);
				fillpoly(5, g);
				setfillstyle(SOLID_FILL, BLACK);
				cc = BLACK;
				NOC++;
			}
		}
		////RED
		SBN = 66;
		for (int x = 92, i = 0; x > 0; x -= 46, i++)
		{
			for (int y = 0, k = 0; y < 276; y += 46, k++)
			{
				int a[10] = { 276 + x,414 + y,322 + x,414 + y,322 + x,460 + y,276 + x,460 + y,276 + x,414 + y };
				if ((i == 0 && k == 3))
				{
					cc = RED; C[NOC].Issave = true;
				}
				if ((i == 1 && k < 5))
				{
					cc = RED; C[SBN].Issave = true;
					C[SBN].setcellPos(Position(276 + x, 414 + y), Position(322 + x, 460 + y), cc);
					setfillstyle(SOLID_FILL, cc);
					fillpoly(5, a);
					cc = BLACK;
					SBN--;
					continue;
				}
				setfillstyle(SOLID_FILL, cc);
				C[NOC].setcellPos(Position(276 + x, 414 + y), Position(322 + x, 460 + y), cc);
				fillpoly(5, a);
				setfillstyle(SOLID_FILL, BLACK);
				cc = BLACK;
				NOC++;
			}
		}
		NOC = 38;
		for (int y = 0, k = 0; y < 276; y += 46, k++)
		{
			int t[10] = { 276 ,414 + y,322 ,414 + y,322 ,460 + y,276 ,460 + y,276 ,414 + y };
			if (k == 4)
			{
				C[NOC].Issave = true; cc = RED;
			}
			setfillstyle(SOLID_FILL, cc);
			C[NOC].setcellPos(Position(276 , 414+y), Position(322 , 460+y), cc);
			fillpoly(5, t);
			setfillstyle(SOLID_FILL, BLACK);
			cc = BLACK;
			NOC--;
		}


		////
		////// GREEN
		////
		NOC = 39;
		SBN = 71;
		for (int y = 92, i = 0; y >=46; y -= 46, i++)
		{
			for (int x = 230, k = 0; x >= 0; x -= 46, k++)
			{
				int g[10] = { 0 + x,276 + y,46 + x,276 + y,46 + x,322 + y,0 + x,322 + y,0 + x,276 + y };
				if ((i == 0 && k == 3))
				{
					cc = GREEN; C[NOC].Issave = true;
				}
				if ((i == 1 && k < 5))
				{
					cc = GREEN; C[SBN].Issave = true;

					C[SBN].setcellPos(Position(0 + x, 276 + y), Position(46 + x, 322 + y), cc);
					setfillstyle(SOLID_FILL, cc);

					fillpoly(5, g);
					SBN--;
					cc = BLACK;
					continue;
				}
				setfillstyle(SOLID_FILL, cc);
				C[NOC].setcellPos(Position(0 + x, 276 + y), Position(46 + x, 322 + y), cc);
				fillpoly(5, g);


				setfillstyle(SOLID_FILL, BLACK);
				cc = BLACK;
				NOC++;
			}
		}

		for (int x = 0, k = 0; x <= 230; x+=46,k++)
		{
			if (k == 1)
			{
				cc = GREEN; C[NOC].Issave = true;
			}
			int g[10] = { 0 + x,276 ,46 + x,276 ,46 + x,322 ,0 + x,322 ,0 + x,276 };
			C[NOC].setcellPos(Position(0 + x, 276), Position(46 + x, 322),cc);
			setfillstyle(SOLID_FILL, cc);
			fillpoly(5, g);
			cc = BLACK;
			NOC++;
		}

		// arraay ka index for dice cell is 92,93,94;
		//// dice roll waly dabby
		int K = 92;
		for (int j = 0; j <= 138; j+=46)
		{
			int db1[10] = { 800+j,150,846+j,150,846+j,196,800+j,196,800+j,150 };
			drawpoly(5, db1);
			C[K].setcellPos(Position(800+j, 150), Position(846+j, 196), BLACK);
			K++;
		}


		
	}
	void cheat()
	{

			cout << "Which three numbers do u want";
			for (int i = 0; i < 3; i++)
				cin >> dice.diceno[i];
			//return true;
		//return false;
	}
	
	int DiceIndex()
	{
		Position P;
		while(1)
		{
			mouseclick(P);
			for (int i = 0; i < 3; i++)
			{
				if (C[92 + i].BoxConfirmation(P.x, P.y))
				{
					if (dice.diceno[i] != 0)
					{
						return i;
					}
					else
						break;
				}
			}
			if (C[95].BoxConfirmation(P.x, P.y))
				return 95;
		} 
	}

	

	void DisplayDiceNo()
	{
		int diceindex = 92;
		
		for (int d = 0; d < 3; d++)
		{
			Position t1 = C[diceindex+d].getTL(), t2 = C[diceindex+d].getBR();
			Position P = C[diceindex+d].getcellcenter(t1, t2);
			int k = dice.diceno[d];
			stringstream strs;
			strs << k;
			string temp_str = strs.str();
			char* char_type = (char*)temp_str.c_str();
			outtextxy(P.x, P.y, char_type);
			
		}

		


	}

	bool isWin()
	{
		if (Players[Turn]->TokenReachDest==4)
			return true;
		else
			return false;
	}
	void inttocolor()
	{
		if (Turn == 0)
		{
			turncolor = GREEN;
		}
		else if (Turn == 1)
		{
			turncolor = DARKGRAY;
		}
		else if (Turn == 2)
		{
			turncolor = BLUE;
		}
		else
		{
			turncolor = RED;
		}

	}

	void init()
	{
		cout << "how many no. of players, do you want? \n";
		cin >> NoOfPlayers;
		Turn = 0;
		turncolor = GREEN;
		MaxNoSteps = 55;
		Players = new Player*[4];
		Players[3] = new Player(RED);
		Players[0]= new Player(GREEN);
		Players[1]= new Player(DARKGRAY);
		Players[2]= new Player(BLUE);
		
		/*
		
											  5 6 7
											  4   8  52
											  3   9  53
											  2   10 54
											  1   11 55
											  0   12 56
							46 47 48 49	50 51 	    13 14 15 16 17 18
							45 67 68 69 70 71       61 60 59 58 57 19                    
							44 43 42 41 40 39       25 24 23 22 21 20
											38 62 26
											37 63 27	
											36 64 28
											35 65 29
											34 66 30
                                            33 32 31
		
		*/
			for (int i = 0; i < 4; i++)
			{
				Players[2]->PlayerTokens[i] = new BlueToken(BLUE, 84 + i, 21,57);
				Players[3]->PlayerTokens[i] = new RedToken(RED, 88+i, 34,62);
				Players[0]->PlayerTokens[i] = new GreenToken(GREEN, 76 + i, 47,67);
				Players[1]->PlayerTokens[i] = new YellowToken(DARKGRAY, 80 + i, 8,52);
			}
			int m = 0;
			for (int  i = 0; i < 4; i++)
			{
				for (int k = 0; k < 4; k++)
				{
				//	box.dabba[76 + m].push_back();
					//box->dabba[76 + m].push_back();
					box[76 + m].dabba.push_back(Players[i]->PlayerTokens[k]);
					m++;
				}
			}


	}
	
	int choosingtoken()
	{
		Position p;
		mouseclick(p);
		for (int i = 0; i < 92; i++)
		{
			if (C[i].BoxConfirmation(p.x, p.y))
				return i;
		}
		return -1;
	}
	
	
	int tokenChoseninBox(int CellIndex)
	{
			int i;
			for (i = 0; i < box[CellIndex].dabba.size(); ++i)
			{
				if (box[CellIndex].dabba[i]->getColor() == turncolor)
					return i;
			}
			return -1;
	}
	bool isValidSelection(int CellIndex, int DiceNo, int& TokenIndex)
	{
		if (box[CellIndex].dabba.size() != 0) //&& box[CellIndex].dabba[TokenIndex]->getColor() == turncolor)
		{
			TokenIndex = tokenChoseninBox(CellIndex);
			if (TokenIndex == -1)
				return false;
			if (box[CellIndex].dabba[TokenIndex]->isAtHome())
			{
				if (DiceNo == 6)
					return true;
				else
					return false;
			}
			if (box[CellIndex].dabba[TokenIndex]->StepsTaken() + DiceNo <= 56)
				return true;
		}
		return false;
	}
	
	bool canContinue()
	{
		int Sum = 0;
		for (int i = 0; i < 3; ++i)
		{
			Sum += dice.diceno[i];
		}
		if (Sum == 18)
			return false;
		for(int i=0;i<4;++i)
		{
			if (Players[Turn]->PlayerTokens[i]->isAtHome())
			{
				if (dice.DiceNoAtIndex(0)==6)
					return true;
			}
			else if (Players[Turn]->PlayerTokens[i]->StepsTaken() + dice.DiceNoAtIndex(0) <= 56)
				return true;
		}
		return false;
	}
	void DrawToken()
	{
		for (int  i = 76; i < 92; i++)
		{
			if (box[i].dabba.size()!=0)
			{
				Position P = C[i].getcellcenter(C[i].getTL(), C[i].getBR());
				box[i].dabba[0]->DrawToken(P);
			}
		}
	}
	
	bool isSpecialBox(int Des)
	{
		for(int i=0;i<8;i++)
		{
			if(Des==SpecialBoxes[i])
			return true;
		}
		return false;
	}
	void updateBoard(int TokenIndex, int DiceNo, int TokkenIndexinDabba)
	{
		if (box[TokenIndex].dabba[TokkenIndexinDabba]->isAtHome())
		{
			box[box[TokenIndex].dabba[TokkenIndexinDabba]->getInitialLocation()].dabba.push_back(box[TokenIndex].dabba[TokkenIndexinDabba]);
			Position P=C[box[TokenIndex].dabba[TokkenIndexinDabba]->getInitialLocation()].getcellcenter(C[box[TokenIndex].dabba[TokkenIndexinDabba]->getInitialLocation()].getTL(),
				C[box[TokenIndex].dabba[TokkenIndexinDabba]->getInitialLocation()].getBR());
			box[TokenIndex].dabba[TokkenIndexinDabba]->DrawToken(P);
			box[TokenIndex].dabba[TokkenIndexinDabba]->changeHomeStatus();
			box[TokenIndex].dabba.erase(box[TokenIndex].dabba.begin()+TokkenIndexinDabba);
			C[TokenIndex].draw();

		}
		else
		{
			int Des = TokenIndex+DiceNo;
			
				if (Des>51)
				{
					Des-=52;
				}
			box[TokenIndex].dabba[TokkenIndexinDabba]->addSteps(DiceNo);
			
			if (box[TokenIndex].dabba[TokkenIndexinDabba]->StepsTaken() > box[TokenIndex].dabba[TokkenIndexinDabba]->getJumpStep())
			{
				if (box[TokenIndex].dabba[TokkenIndexinDabba]->hasKilled)
					Des = box[TokenIndex].dabba[TokkenIndexinDabba]->JumpIndex+(box[TokenIndex].dabba[TokkenIndexinDabba]->StepsTaken()-box[TokenIndex].dabba[TokkenIndexinDabba]->getJumpStep()-1);
				else
				{
					int StepsUpdate = box[TokenIndex].dabba[TokkenIndexinDabba]->StepsTaken()-box[TokenIndex].dabba[TokkenIndexinDabba]->getJumpStep()-2;
					box[TokenIndex].dabba[TokkenIndexinDabba]->ChangeSteps(StepsUpdate);
				}
			}
			

			if (box[Des].dabba.size()>0)//box[Des].dabba[TokkenIndexinDabba]
			{
				if(isSpecialBox(Des) || box[Des].dabba[0]->getColor() == turncolor)
				{
					//box[des].dabba.push_back(box[TokenIndex].dabba[TokkenIndexinDabba]);
				}
				else
				{
					box[TokenIndex].dabba[TokkenIndexinDabba]->hasKilled=true;
					for(int i=0;i<box[Des].dabba.size();++i)
					{
						box[box[Des].dabba[i]->getHomeIndex()].dabba.push_back(box[Des].dabba[i]);
						Position P = C[box[Des].dabba[i]->getHomeIndex()].getcellcenter(C[box[Des].dabba[i]->getHomeIndex()].getTL(),
						C[box[Des].dabba[i]->getHomeIndex()].getBR());
						box[Des].dabba[i]->DrawToken(P);
						box[Des].dabba[i]->changeHomeStatus();
						box[Des].dabba.erase(box[Des].dabba.begin()+i);
					}
					//box[Des].dabba.push_back(box[TokenIndex].dabba[TokkenIndexinDabba]);
					// Draw Token at Grid[Des]->getHomeIndex()
					
				}
			}
			if (box[TokenIndex].dabba[TokkenIndexinDabba]->StepsTaken()==56)
			{
				Players[Turn]->TokenReachDest++;
				for(int i=0;i<4;i++)
				{
					if (i==Turn)
						Des=72+i;
				}
			}
			box[Des].dabba.push_back(box[TokenIndex].dabba[TokkenIndexinDabba]);
			// Draw Token at Des;
			Position P = C[Des].getcellcenter(C[Des].getTL(),C[Des].getBR());
			box[Des].dabba[0]->DrawToken(P);
			box[TokenIndex].dabba.erase(box[TokenIndex].dabba.begin()+TokkenIndexinDabba);
			// Draw Cell[TokenIndex]
			if(box[TokenIndex].dabba.size()==0)
				C[TokenIndex].draw();
			else
			{
				Position P = C[TokenIndex].getcellcenter(C[TokenIndex].getTL(), C[TokenIndex].getBR());
				box[TokenIndex].dabba[0]->DrawToken(P);
			}
		}
	}


	void PrintTokenAtS_PTurn()
	{
		//int SpecialBoxes[8] = { 34,42,47,3,8,16,21,29 };
		for (int i = 0; i < 8; i++)
		{
			if (box[SpecialBoxes[i]].dabba.size() > 1)
			{
				for (int j = 0; j < box[SpecialBoxes[i]].dabba.size(); j++)
				{
					if (box[SpecialBoxes[i]].dabba[j]->getColor() == turncolor)
					{
						Position P = C[SpecialBoxes[i]].getcellcenter(C[SpecialBoxes[i]].getTL(), C[SpecialBoxes[i]].getBR());
						box[SpecialBoxes[i]].dabba[j]->DrawToken(P);
					}
				}
			}
		}
	}

	/*void Displayindexofcell()
	{
		Position P;
		for (int i = 0; i < 92; i++)
		{
			P=C[i].getcellcenter(C[i].getTL(), C[i].getBR());
			stringstream strs;
			strs << i;
			string temp_str = strs.str();
			char* char_type = (char*)temp_str.c_str();
			outtextxy(P.x, P.y, char_type);
		}
	}*/




	void Play()
	{
		init();
		//StartGame();
		srand(time(0));
		DisplayBoard();
		DrawToken();


		//Displayindexofcell();

		int bxi;

		do
		{
			DisplayPlayerMsg();
			PrintTokenAtS_PTurn();
			dice.rolladice();
			DisplayDiceNo();
			int SelectBoxIndex;
			bool Cheating=true;
			bxi = DiceIndex();
			if (bxi == 95)
			{
				cheat();
				//bxi = DiceIndex();
				Cheating = true;
			}
			if (!canContinue())
			{
				outtextxy(750, 65, "chal hun koe nahi agli dafa sahi");
				Sleep(1000 * 7);
				outtextxy(750, 65, "                                                            ");
				ChangeTurn();
				dice.reset();
				continue;
			}
			
			int kuchb = 0;
			int toeknIndexinBox;
			do 
			{
				DisplayDiceNo();

				do
				{
					outtextxy(750, 65, "                                                      ");
					bxi = DiceIndex();
					
					do
					{

						SelectBoxIndex = choosingtoken();
					} while (SelectBoxIndex == -1);
					//toeknIndexinBox = tokenChoseninBox(SelectBoxIndex);
					if (isValidSelection(SelectBoxIndex, dice.diceno[bxi], toeknIndexinBox) == false)
						outtextxy(750, 65, "oye sahi km kr bhai");

				} while (isValidSelection(SelectBoxIndex, dice.diceno[bxi],toeknIndexinBox) == false);
				kuchb++;
				updateBoard(SelectBoxIndex, dice.diceno[bxi], toeknIndexinBox);
				dice.diceno[bxi] = 0;
			} while (!dice.isempty());
			outtextxy(750, 65, "                                                                   ");
			if (isWin())
			{
				WC++;
				WinPlayers.push_back(Turn);
				//UpdatePlayerList(Turn);
				// We have to find a way in which this player's turn does not come again.....?
			}
			ChangeTurn();
			if (WC == NoOfPlayers - 1)
			{
				DisplayResult();
				break;
			}

		}while(true);

	}



};

