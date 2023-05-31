#include <iostream>
#include <conio.h>
#include "ConsoleScreen.h"
#include "Int4.h"



    void ConsoleScreen::Init(char _BaseCh)
    {
        BaseCh = _BaseCh;
        Clear();
    }

    void ConsoleScreen::SetPixel(const int4& _Pos, char _Ch)
    {
        ArrScreen[_Pos.Y][_Pos.X] = _Ch;
    }

    void ConsoleScreen::Print() const
    {
        for (size_t y = 0; y < YLine; y++)
        {
            printf_s(ArrScreen[y]);
            printf_s("\n");
        }
    }

    bool ConsoleScreen::IsScreenOut(const int4& _Pos) const
    {
        if (0 > _Pos.X)
        {
            return true;
        }

        if (0 > _Pos.Y)
        {
            return true;
        }

        if (XLine <= _Pos.X)
        {
            return true;
        }

        if (YLine <= _Pos.Y)
        {
            return true;
        }

        return false;
    }

    const int4 Left = { -1, 0 };
    const int4 Right = { 1, 0 };
    const int4 Up = { 0, -1 };
    const int4 Down = { 0, 1 };
   



    void ConsoleScreen::Clear()
    {
        system("cls");
        for (size_t y = 0; y < YLine; y++)
        {
            for (size_t x = 0; x < XLine; x++)
            {
                ArrScreen[y][x] = BaseCh;
            }
            ArrScreen[y][XLine] = 0;
        }
    }