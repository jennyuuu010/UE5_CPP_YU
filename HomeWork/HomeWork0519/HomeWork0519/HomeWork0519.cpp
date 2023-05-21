// HomeWork0519.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

using namespace std; 

int ChCount(const char* const _string, char Ch)  // Ch와 같은 문자가 몇개들어있는지 세어서 리턴해주는 함수
{
   
  
    int ChCount = 0; //Ch의 개수
          
    for (int Count = 0; _string[Count] != NULL; Count++) //문자열이 NULL이 아닐 때까지 반복, Count는 문자열 순서(번째 수) 
        {
        if (_string[Count] == Ch) // 만약 [Count]번째 글자가 Ch라면 
            ChCount++; //Ch의 개수를 늘려라 
        else
            continue; // 아닌 경우는 건너 뛰어라. 
              
        }
    
        return ChCount; //최종 Ch 글자수 
   
}

void TrimDelete(char* _string) // 문자 사이 공란을 삭제해주는 함수 
{
    //전체 문자열 사이즈-공란 개수 및 공란 순서 = 공란 없는 문자열 
    char Arr[256];
    int Index = 0;
    
    for (int Count = 0; _string[Count] != NULL; Count++)
    {
        if (_string[Count] != ' ')
        {
            Arr[Index] = _string[Count];
            Index++;
        }
        else 
            Index++;
         

    }
   
}


int DigitsCount(int _Number) //자릿수 출력 
{
    if (_Number == 0) {
        return 0;
    }
    while (_Number != 0)
    {
        return 1 + DigitsCount(_Number / 10);
    }
    return 0;
    
}

void StrCopy(const char* const _Left, char* _Right) //문자열 복사 

{
    
    &_Right = _Left; 

}

// 가장 어려운 숙제
void NumberToString(int _Number, char* _Right) //숫자를 글자로 
{

    _Number = static_cast<char>(_Number);

    return;
}


int main()
{
    // 4가 리턴되어야 합니다.
    // 문자열의 마지막에 들어가는 0은 글자로 치지 않습니다.
    {
        int Result = ChCount("ab aaa ccc ddd eee", 'a');
    }

    {
        char Arr[256] = "aa  b  c dd ee";

        TrimDelete(Arr);

        // Arr "aabcddee"
        int a = 0;
    }

    {
        // 8이 리턴되게 만들어라.
        int Result = DigitsCount(100);

        int a = 0;
    }

    {
        char ArrCopyText[256] = {};

        StrCopy("aaaa bbb ccc", ArrCopyText);

        int a = 0;
    }

    {
        char Result[256] = {};

        // Result = "312312";

        NumberToString(312312, Result);

        char Ch = '0';

        int Value = 7;

        char ChConvert = Value + 48;

        int a = 0;
    }

    std::cout << "Hello World!\n";
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


