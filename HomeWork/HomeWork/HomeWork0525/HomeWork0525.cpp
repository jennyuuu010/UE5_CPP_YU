// HomeWork0525.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <conio.h>
#include "HomeWork0525.h"


class Player;
class Monster;
class FightZone;

Player NewPlayer;
Monster NewMonster;

FightZone FZone;

const int LineCount = 40;

int StringCount(const char* _Arr)
{
	// 위쪽 예제코드를 참고하세요
	int ChCount = 0;
	while (_Arr[ChCount])
	{
		++ChCount;
	}

	return ChCount;
}

	
	void Player::StatusRender()
	{
		int Count = 0;

		Count = StringCount((const char*) Name);

		// 40개로 맞춰오세요.

		// 줄바꿈이 안되고 있습니다.
		printf_s("%s", Name);

		for (size_t i = 0; i < LineCount - Count; i++)
		{
			printf_s("-");
		}
		printf_s("\n");

		printf_s("공격력 : %d\n", Att);
		printf_s("체  력 : %d\n", Hp);
		for (size_t i = 0; i < LineCount; i++)
		{
			printf_s("-");
		}
		printf_s("\n");

	}

	void Player::DamagePrint(const char* const _AttName, int _Att)
	{
		printf_s("%s가 %s를 공격했습니다.\n", _AttName, Name);
		printf_s("%s는 %d의 데미지를 입었습니다.\n", Name, _Att);
	}

	void Player::Damage(int _Att)
	{
		Hp -= _Att;
	}

	// 
    char Player::GetName()
	{
		return Name;
	}

	int Player::GetAtt()
	{
		return Att;
	}

	bool Player::IsDeath()
	{
		return Hp <= 0;
	}



	void Monster::StatusRender()
	{
		int Count = 0;

		Count = StringCount((const char*)Name);

		// 40개로 맞춰오세요.

		// 줄바꿈이 안되고 있습니다.
		printf_s("%s", Name);

		for (size_t i = 0; i < LineCount - Count; i++)
		{
			printf_s("-");
		}
		printf_s("\n");

		printf_s("공격력 : %d\n", Att);
		printf_s("체  력 : %d\n", Hp);
		for (size_t i = 0; i < LineCount; i++)
		{
			printf_s("-");
		}

		printf_s("\n");

	}

	void Monster::DamagePrint(const char* const _AttName, int _Att)
	{
		printf_s("%s가 %s를 공격했습니다.\n", _AttName, Name);
		printf_s("%s는 %d의 데미지를 입었습니다.\n", Name, _Att);
	}

	void Monster::Damage(int _Att)
	{
		Hp -= _Att;
	}

	char Monster::GetName()
	{
		return Name;
	}

	int Monster::GetAtt()
	{
		return Att;
	}

	bool Monster::IsDeath()
	{
		return Hp <= 0;
	}


 void FightZone::Fight(Player& NewPlayer, Monster& NewMonster)
	{
		while (true)
		{
			system("cls");

			// 한번에 함수로 만든것이고
			NewPlayer.StatusRender();
			NewMonster.StatusRender();
			_getch();

			system("cls");
			NewMonster.Damage(NewPlayer.GetAtt());
			NewPlayer.StatusRender();
			NewMonster.StatusRender();
			NewMonster.DamagePrint((const char*)NewPlayer.GetName(), NewPlayer.GetAtt());
			_getch();

			if (true == NewMonster.IsDeath())
			{
				printf_s("%s가 죽었습니다.\n", NewMonster.GetName());
				printf_s("%s의 승리입니다.\n", NewPlayer.GetName());
				_getch();
				return;
			}

			system("cls");
			NewPlayer.Damage(NewMonster.GetAtt());
			NewPlayer.StatusRender();
			NewMonster.StatusRender();
			NewMonster.DamagePrint((const char*)NewPlayer.GetName(), NewPlayer.GetAtt());
			NewPlayer.DamagePrint((const char*)NewMonster.GetName(), NewMonster.GetAtt());
			_getch();

			if (true == NewPlayer.IsDeath())
			{
				printf_s("%s가 죽었습니다.\n", NewPlayer.GetName());
				printf_s("%s의 승리입니다.\n", NewMonster.GetName());
				_getch();
				return;
			}
		}
	}


// 문법은 왜 발전했다? 인간이 코드를 덜치기 위해서 발전했습니다.
int main()
{
	// 객체지향이라고 한다.
	FZone.Fight(NewPlayer, NewMonster);

}

