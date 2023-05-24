// HomeWork0522.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <conio.h>

void StatusRender(const char* const _Name, int _Att, int _Hp)
{
    // 40개로 맞춰오세요.

    // 줄바꿈이 안되고 있습니다.
    printf_s("%s--------------------------\n", _Name);
    printf_s("공격력 : %d\n", _Att);
    printf_s("체  력 : %d\n", _Hp);
    printf_s("--------------------------\n");
}

void DamagePrint(const char* const _AttName, const char* const _DefName, int _Att)
{
    printf_s("%s가 %s를 공격했습니다.\n", _AttName, _DefName);
    printf_s("%s는 %d의 데미지를 입었습니다.\n", _DefName, _Att);
}

void Damage(int& _Hp, int _Att)
{
    _Hp -= _Att;
}

int main()
{

    int PlayerHp = 200;
    int PlayerAtt = 100;
    char PlayerName[40] = "fasdhjkfasdhjkfasdhjfklasdhjkfasdhjfk";

    int MonsterHp = 100;
    int MonsterAtt = 10;
    char MonsterName[40] = "Monster";

    while (true)
    {
        // 콘솔창을 모조리 지우는 함수
        system("cls");

        // 한번에 함수로 만든것이고
        StatusRender(PlayerName, PlayerAtt, PlayerHp);
        StatusRender(MonsterName, MonsterAtt, MonsterHp);

        // 아무키나 입력할때까지 기다리는 함수, 하나의 키를 입력 받는 함수 
        _getch();



        DamagePrint(PlayerName, MonsterName, PlayerAtt);
        Damage(MonsterHp, PlayerAtt);
        // MonsterHp -= PlayerAtt;

        _getch();

        DamagePrint(MonsterName, PlayerName, MonsterAtt);
        Damage(PlayerHp, MonsterAtt);

        _getch();

        //if (조건 만족시)
        //{
        //    return;
        //}

    }

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
