#pragma once
//

class int4
{

public:

    const int XLine = 20;
    const int YLine = 10;

    int X = 0;
    int Y = 0;
    int Z = 0;
    int W = 1;

    void operator=(const int _Other);
    

    void operator+=(const int _Other);
    

    void operator+(const int _Other);



private:

    int Pos;
};


