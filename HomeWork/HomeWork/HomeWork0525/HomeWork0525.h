#pragma once
#include <iostream>
#include <conio.h>



class Player
{
public:
	void StatusRender();

	int StringCount(const char* _Arr);

	void DamagePrint(const char* const _AttName, int _Att);

	void Damage(int _Att);

	char GetName();

	int GetAtt();

	bool IsDeath();

	
private:
	char Name;
	int Att;
	int Hp;
};

class Monster
{
public:
	void StatusRender();

	
	void DamagePrint(const char* const _AttName, int _Att);

	void Damage(int _Att);

	char GetName();

	int GetAtt();

	bool IsDeath();
		

private:
	char Name;
	int Att;
	int Hp;
};

class FightZone
{
public:
	void Fight(Player& NewPlayer, Monster& NewMonster);
};


