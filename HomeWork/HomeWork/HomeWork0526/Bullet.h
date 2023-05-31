#pragma once
class Bullet : public int4
{
public: 
	int4::GetPos() const

		void int4::ddPos(const int4& _Pos);

	void int4::SetPos(const int4& _Pos);

	void Input(ConsoleScreen* _Sreen);

	void BulletPrint() const;

	bool IsScreenOut(const int4& _Pos) const;
};

