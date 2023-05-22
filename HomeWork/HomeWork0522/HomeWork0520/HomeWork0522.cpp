// HomeWork0520.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>


int StringCount(const char* _Arr)
{
    int ChCount = 0;

    while (_Arr[ChCount])
    {
        char Ch = _Arr[ChCount];

        ++ChCount;
        Ch = _Arr[ChCount];
    }

    return ChCount;
}

//void ChangeCh(char* _Arr, char _PrevCh, char _NextCh)
//{
//    if (nullptr == _Arr)
//    {
//        return;
//    }
//    int ChCount = 0;
//
//    while (_Arr[ChCount])
//    {
//        char Ch = _Arr[ChCount];
//        if (Ch == _PrevCh)
//        {
//
//            _Arr[ChCount] = _NextCh;
//        }
//        ++ChCount;
//}


void StatusRender(const char* const _Name, int _Att, int _Hp)
{
    // 40개로 맞춰오세요.
    // 줄바꿈이 안되고 있습니다.
     

    printf_s("%s--------------------------\n", _Name);
    printf_s("공격력 : %d\n", _Att);
    printf_s("체  력 : %d\n", _Hp);
    printf_s("--------------------------\n");

    

    //40 - 
}

void DamagePrint(const char* const _AttName, const char* const _DefName, int _Att)
{
    printf_s("%s가 %s를 공격했습니다.\n", _AttName, _DefName);
    printf_s("%s는 %d의 데미지를 입었습니다.\n", _DefName, _Att);
}

void Damage(int& _Hp, int _Att)
{
        
    _Hp -= _Att; //데미지를 입어서 체력이 깎임.  
           
}

// 숙제 1 
//어떤 글자가 들어와도 문자의 오른쪽 끝을 맞춰오세요. 
//단, 이름은 알파벳만 가능하고 이름은 최대 40글자. 
// 숙제 1 -- 문자의 오른쪽끝을 맞춰오세요. 이름은 알파뱃만
// fasdhjkfasdhjfkasd--------
// Monster-------------------
// 위와같이 UI의 끝부분이 맞게 만들어라.

//숙제 2 
//실시간으로 만들어봐라. 
//데미지 메시지 나오는 순간 체력이 곧바로 감소되게 만들어라. 
//엔터를 누르면 데미지를 입어서 체력이 깎여야 한다. 
//화면 지우는 함수, 화면에 출력하는 함수를 잘 생각해보세요. 

// 숙제 2 -- 실시간으로 만들어오세요.
// 데미지 메세지가 나오는순간 체력이 곧바로 감소되게 만들어라.
// 화면 지우는 함수 화면에 출력하는 함수를 잘 생각해보세요.
// 그냥 무식하게 생각해라.

//숙제 3 
//누군가의 HP가 0이 된 순간 종료. 




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
        // 콘솔창을 모조리 지우는 함수, 이전 내용이 삭제. 
        system("cls");

        // 한번에 함수로 만든것이고
        StatusRender(PlayerName, PlayerAtt, PlayerHp);
        StatusRender(MonsterName, MonsterAtt, MonsterHp);

        // 아무키나 입력할때까지 기다리는 함수, 하나의 키를 입력 받는 함수               
       _getch();
        
       system("cls");
        Damage(MonsterHp, PlayerAtt);

        StatusRender(PlayerName, PlayerAtt, PlayerHp);
        StatusRender(MonsterName, MonsterAtt, MonsterHp);

        DamagePrint(PlayerName, MonsterName, PlayerAtt);
       
        // MonsterHp -= PlayerAtt;

        _getch();

        if (MonsterHp == 0)
        {
            printf_s("%s가 %s를 공격했습니다.\n")


        }

        else (PlayerHp == 0)
        {


        }
        

    }

    return 0;
}
