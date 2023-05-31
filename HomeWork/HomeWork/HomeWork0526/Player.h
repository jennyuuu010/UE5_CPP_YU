#pragma once


class Player : public int4
{
public:
	int GetPos() const;

	void Pos(const int4& _Pos);

	void SetPos(const int4& _Pos);

	Player(const Player&) = delete;

	void Input(ConsoleScreen* _Sreen);

	void AddPos(const int4& _Pos); 

private:

	
};
