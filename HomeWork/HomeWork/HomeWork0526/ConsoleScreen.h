#pragma once

class ConsoleScreen : public int4
{
public:
    ConsoleScreen()
    {

    }

    void Init(char _BaseCh);

    void SetPixel(const int4& _Pos, char _Ch);


    void Clear();


    bool IsScreenOut(const int4& _Pos) const;

    void Print() const;

   void GetPos() const
    {
        return Pos;
    }

    void AddPos(const int4& _Pos)
    {
        Pos += _Pos;
    }


    void SetPos(const int4& _Pos)
    {

        Pos = _Pos;
    }
   

private:
    char BaseCh = ' ';
    char ArrScreen[YLine][XLine + 1] = {};
};


