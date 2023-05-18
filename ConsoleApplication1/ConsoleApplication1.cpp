// ConsoleApplication1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

using namespace std; 

//int ChCount = 0;
//while (Arr[ChCount])
//{
//    char PrintCh = Arr[ChCount];
//    putchar(PrintCh);
//    ++ChCount;
//

int StringCount(char* _Arr) //글자수가 나와야 함. -> 문자열의 길이값 
{
    // 위쪽 예제코드를 참고하세요
    
    int ChCount = 0;
         
        while (_Arr[ChCount])
        {
            ++ChCount;
        }
     
    return ChCount;
}

void ChangeCh(char* _Arr, char _PrevCh, char _NextCh)  // "aaa bbb ccc"; => "aaa bbb ddd";
{
       
    //1번 답 
    _PrevCh = _NextCh;
    _Arr[8] = _NextCh;
    _Arr[9] = _NextCh;
    _Arr[10] = _NextCh;

    /*2번 답
    char* Ptr = &_PrevCh;
    *Ptr = _NextCh;*/

    
    return;
}

int main()
{
    // 한글 들어가지 않습니다.
    {

        
        char Arr[100] = "aaa";
        // 5이 나와야 합니다.
        // 글자수를 세는 함수입니다.
        int Result = StringCount(Arr);
                
    }

    {
        char Arr[100] = "aaa bbb ccc";

         // "aaa bbb ccc"; => "aaa bbb ddd";
        ChangeCh(Arr, 'c', 'd');
             
                
    }

    return 0; 

}

