#include <iostream>
#include <conio.h>
#include "ConsoleScreen.h"
#include "Wall.h"
#include "int4.h"



void WallPrint() const
{
Wall ArrWall[10];
Wall* PtrWall = ArrWall;

printf_s(ArrWall[5]);
printf_s("0");

}


int4 GetPos() const
{
    return Pos;
}

void SetPos(const int4& _Pos)
{
    
    Pos = _Pos;
}


   