﻿// HomeWork0523.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

class C
{
    __int64 A;
    __int64 B;
};

class Test
{
    // 12바이트
    // 가장큰 바이트 4바이트
    // 12
    int A; // 4바이트
    __int64 B;
    char C;
    int D; // 4바이트
    // C B; // 4바이트

    //  int     
    // [][][][][][][][] [][][][][][][][] [][][][][][][][]

    // 1. 기본적으로 8바이트 이하의 기본자료형을 찾아요.
    // 2. 그중 가장 바이트 크기가 큰 녀석을 찾습니다.
    // 3. 어떤 변수가 존재한다면 가장 큰 바이트 크기의 바이트로 할당한다.

    //class 내에 메모리 할당 후 모든 멤버 변수의 위치가 어떻게 되는지? 
    // 주소값 확인하여서  알아내는 것이 과제.* 와& 를 이용.
};

int main()
{
    size_t A = sizeof(Test);

    // A B C D
    Test New;
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
