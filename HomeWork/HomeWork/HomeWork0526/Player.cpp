#include <iostream>
#include <conio.h>
#include "Player.h"
#include "ConsoleScreen.h"
#include "int4.h"
//class 와 int는 차이가 없다. -> class private: 

   int int4::GetPos() const
    {
        return Pos;
    }

    void Player::AddPos(const int4& _Pos)
    {
        Pos += _Pos;
    }


    void Player::SetPos(const int4& _Pos)
    {
        
        Pos = _Pos;
    }

        

    void Player::Input(ConsoleScreen* _Sreen)
    {
        char Select = (char)_getch();

        int4 MovePos = { 0, 0 };

        switch (Select)
        {
        case 'a':

            MovePos = Left;
 
             int4 NextPos = GetPos() + Left;
            if (false == _Sreen->IsScreenOut(GetPos() + Left))
            {
                AddPos(Left);
            }

            
            break;
        case 'd':
            MovePos = Right;

            if (false == _Sreen->IsScreenOut(GetPos() + Right))
            {
                AddPos(Right);
            }

            break;
        case 'w':
            MovePos = Up;

            if (false == _Sreen->IsScreenOut(GetPos() + Up))
            {
               AddPos(Up);
            }
            break;
        case 's':
            MovePos = Down;
            break;
        default:
            break;
        
         case 'e':
             MovePos = BulletShot;

             if (false == _Sreen->IsScreenOut(GetPos() + BulletShot))
             {
                 AddPos(BulletShot);
             }
        }
        if (false == _Sreen->IsScreenOut(GetPos() + MovePos))
        {
            AddPos(MovePos);
        }

        if (true == Wall.GetPos()))
            {
                AddPos(GetPos()-1);
            }

    }
