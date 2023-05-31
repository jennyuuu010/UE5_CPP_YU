#include <iostream>
#include <conio.h>
#include "Int4.h"



void Int4::operator=(const int _Other)
{
    X = _Other.X;
    Y = _Other.Y;
    Z = _Other.Z;
    W = _Other.W;
}

void Int4::operator+=(const int _Other)
{
    X += _Other.X;
    Y += _Other.Y;
    Z += _Other.Z;
    W += _Other.W;
}

void Int4::operator+(const int _Other);