#include <conio.h>
#include "Bullet.h"
#include "ConsoleScreen.h"
#include "int4.h"

class Wall;
Bullet NewBullet; 

//���ӽ����̽� Ȱ�� 
const int XLine = 20;
const int YLine = 10;
//�÷��̾ �Է����� ���� �Ѿ��� �߻�ǰԲ�. 
void BulletInput(ConsoleScreen* _Sreen)
{
  
    int4::MovePos = { 0, 0 };
    char BulletShot = (char)_getch();
    if (BulletShot == 'e')
    {
        int4 NextPos = GetPos() + Right;
    }
    if (false == _Sreen->IsScreenOut(GetPos() + Right))
    {
        AddPos(Right);
    }
}



bool IsScreenOut(const int4& _Pos) const
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

    void Bullet::BulletPrint() const
    {
        for (size_t y = 0; y < YLine; y++)
        {
            for (size_t x = 0; x < XLine; x++)
            {
                ConsoleScreen.ArrScreen[y][x] = "*";
            }
            
           
        }
    }
}