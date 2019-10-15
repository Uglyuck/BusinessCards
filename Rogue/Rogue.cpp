#include<windows.h>//  -- Rogue Like --
#include<iostream> //           v0.1
#include<iomanip>  //  By: Michael Pelz
//#include <string>

#define KeyPressed(o) !(!(GetKeyState((o)) & 0x0100))
#define printCharacter(o,p)SetConsoleCursorPosition(GetStdHandle(-11),(o));std::wcout<<(p)

//Coordinates that are used for objects.
struct Vector :COORD
{
	Vector() {}Vector(short x, short y)
	{
		X = x; Y = y;
	}
	bool operator==(COORD& o)
	{
		return o.X == X && o.Y == Y;
	}
};

std::wstring charPlayer, charE1, charE2, charEUV, charPortal, charKey, charGoal, charKeyUV, charGoalUV, charWall, charBlank, map, charTemp;
short SBoardWidth, SBoardHeight, SLevel, Stemp1, STime;
Vector VGoal, VPlayer, VKey, VPortal1, VPortal2, VEnemies[99], VTemp;

//Checks and tries to find a valid random location, and puts it in the passed Vector.
void SetRandomLocation(Vector* v)
{
	short x = 1, y = 1, loc;
	while (x > -1)
	{
		x = rand() % ((SBoardWidth - 3) / 2) * 2 + 1;
		y = rand() % ((SBoardHeight - 3) / 2) * 2 + 1;
		loc = y * SBoardWidth + SBoardWidth + x;
		if (map.substr(loc - 1, 3).find(charWall[0]) && (x > 6 || y > 6)) //L'\xB2'))
		{
			map[loc] = charBlank[0];
			*v = { x, y + 1 };
			x = -2;
		}
	}
}
// Spawns all the characters... used for reading the new level function.
void SpawnEverything()
{
	SetRandomLocation(&VGoal);
	SetRandomLocation(&VKey);

	Stemp1 = SLevel;
	while (--Stemp1)
	{
		SetRandomLocation(&VEnemies[Stemp1]);
	}
}

//creates a random map. Top and bottom rows are clear for moving around.
//avoids blocking a full row.
void SetupMap()
{
	short FullRowCounter, CountCopyRows, Sections = 3, CountDynamicRows = SBoardHeight - 4, x = SBoardWidth;
	std::wstring RowBorder, RowBuilt, SectionWall, SectionBlank, RowClean;

	short sx = (SBoardWidth - 2) / Sections;

	while (x--)
		RowBorder += charWall;
	x = sx;

	while (x--)
		SectionWall += charWall;
	x = sx;
	while (x--)
		SectionBlank += charBlank;
	RowClean = charWall;
	x = SBoardWidth - 2;
	while (x--)
		RowClean += charBlank;
	RowClean += charWall;

	map = L"";
	map += RowBorder;
	map += RowClean;

	while (CountDynamicRows--)
	{

		sx = Sections;
		FullRowCounter = Sections - 2;
		CountCopyRows = rand() % 3 + 2;

		RowBuilt = charWall;
		while (sx--)
		{
			if (sx == Sections - 1 && CountDynamicRows > SBoardHeight - 6)
			{
				RowBuilt += SectionBlank;
			}
			else
			{
				if (rand() % 5 == 0)
				{
					RowBuilt += SectionWall;
					--FullRowCounter;
				}
				else
				{
					RowBuilt += SectionBlank;
					FullRowCounter = Sections - 2;
				}
			}
			if (FullRowCounter < 0 && sx > 0)
			{
				RowBuilt += SectionBlank;
				sx--;
			}
		}
		RowBuilt += charWall;
		while (--CountCopyRows && CountDynamicRows)
		{
			map += RowBuilt;
			CountDynamicRows--;
		}
		map += RowBuilt;
	}
	map += RowClean;
	map += RowBorder;
}

void printBoard()
{
	//initialize these in here to hopefully create it on the CPU Cache.
	short u = SBoardHeight;
	Vector t;
	while (u--)
	{
		t = { 0, u };
		printCharacter(t, map.substr(SBoardWidth * u, SBoardWidth));
	}
}

void NextStage()
{
	SLevel++;
	VPlayer = { 3,3 };
	//Key active = true
	charKeyUV = charKey;
	//Goal active = false
	charGoalUV = charBlank;
	SetupMap();
	SpawnEverything();
	printBoard();
}


void Move(Vector* v, short x, short y)
{
	// Remove print of character.
	printCharacter(*v, charBlank); //Ensures no trail left by the object.
	Vector n = { v->X + x, v->Y + y };
	wchar_t land = map[n.X + n.Y * SBoardWidth];

	if (land != charWall[0])
	{
		*v = n;
	}
}

void PlayerKeyCollisions()
{
	//Little overhead, no need to really create objects and check if they are active or not. SReady is the only condition I care about.
	if (VPlayer == VGoal && charGoalUV == charGoal)
		NextStage();
	if (VPlayer == VKey)
	{
		charKeyUV = charBlank;
		charGoalUV = charGoal;
	}
	if (VPlayer == VPortal1)
	{
		VPlayer = VPortal2;
		VPlayer.X--;
	}
	if (VPlayer == VPortal2)
	{
		VPlayer = VPortal1;
		VPlayer.X++;
	}
}

void printInfo()
{
	VTemp = { SBoardWidth + 5, 5 };
	printCharacter(VTemp, "Level:");
	VTemp = { SBoardWidth + 13, 5 };
	printCharacter(VTemp, SLevel);
	VTemp = { SBoardWidth + 5, 15 };
	printCharacter(VTemp, "DUCK");
}
bool isPlayerHitEnemy()
{
	short r = SLevel;
	while (--r)
	{
		if (VPlayer == VEnemies[r])
			return 1;
	}
	return 0;
}

//Done for animation
void printEnemies()
{
	charEUV = charE1;
	if (STime % 10 > 5)
	{
		charEUV = charE2;
	}
	Stemp1 = SLevel;
	while (--Stemp1)
	{
		printCharacter(VEnemies[Stemp1], charEUV);
	}
}
/*
wchar_t renderEnemyUV(short *time)
{
	if (*time % 10 > 5)
		return charE2[0];
	return charE1[0];
}

void printAll(short *time)
{
	//Screen refresh takes too long... And streaming it requires a fixed window. and I don't want to lose everyone.
	std::wstring NewMap = map;

	//initialize these in here to hopefully create it on the CPU Cache.
	NewMap[SBoardWidth * VKey.Y + VKey.X ] = charKeyUV[0];
	NewMap[SBoardWidth * VGoal.Y + VGoal.X] = charGoalUV[0];
	NewMap[SBoardWidth * VPlayer.Y + VPlayer.X] = charPlayer[0];
	NewMap[SBoardWidth * VPortal1.Y + VPortal1.X] = charPortal[0];
	NewMap[SBoardWidth * VPortal2.Y + VPortal2.X] = charPortal[0];

	wchar_t e = renderEnemyUV(time);
	short r = SLevel;
	while (--r)
	{
		NewMap[SBoardWidth * VEnemies[r].Y + VEnemies[r].X] = e;
	}

	short u = SBoardHeight;
	Vector t;
	while (u--)
	{
		t = { 0, u };
		printCharacter(t, NewMap.substr(SBoardWidth * u, SBoardWidth));
	}
}
*/

int main()
{
	charPlayer = L'\x81';
	charE1 = '\x4F';
	charE2 = '\x6F';
	charKey = '$';
	charGoal = L'\xDB';
	charWall = L'\xB2';
	charBlank = L"\xB0";
	charPortal = L'\xEA';
	VPortal1 = { 1,1 };

	SBoardWidth = 32;
	SBoardHeight = 30;
	VPortal2 = { SBoardWidth - 2, SBoardHeight - 2 };

	srand(int(time(0)));
	short dirX;
	short dirY;
	STime = 0;
	Vector t;

	while (!KeyPressed(VK_ESCAPE))
	{
		VTemp = { SBoardWidth + 3, 2 };
		printCharacter(VTemp, "GAUNTLET ");
		SLevel = 0;
		NextStage();
		while (!KeyPressed(VK_ESCAPE) && !isPlayerHitEnemy())
		{

			STime++;
			if (STime > 21)
			{
				Stemp1 = SLevel;
				while (--Stemp1)
				{
					Move(&VEnemies[Stemp1], (rand() % 3 - 1), (rand() % 3 - 1));
				}
				STime = 0;
			}
			dirX = KeyPressed(39) - KeyPressed(37); // - (!KeyPressed(38))); //38 right
			dirY = KeyPressed(40) - KeyPressed(38);


			printInfo();
			Move(&VPlayer, dirX, dirY);
			PlayerKeyCollisions();
			printCharacter(VKey, charKeyUV);
			printCharacter(VGoal, charGoalUV);
			printCharacter(VPortal1, charPortal);
			printCharacter(VPortal2, charPortal);

			printCharacter(VPlayer, charPlayer);

			printEnemies();

			printInfo();
			Sleep(32);
		}

		VTemp = { SBoardWidth + 3, 2 };
		printCharacter(VTemp, "Game Over");

		while (!KeyPressed(VK_RETURN) && !KeyPressed(VK_ESCAPE))
		{
			Sleep(32);
		}

	}
}