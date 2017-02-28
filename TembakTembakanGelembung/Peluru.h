#pragma once
#define PI 3.1415926535897932384626433832795

class Peluru:public GameObject
{
private:
	float m_speed;
	int m_rotation;
	void Vertex(float _x, float _y);
public:
	Peluru(float _xPos, float _yPos, float _speed);
	~Peluru();
	void Draw();
	bool operator == (const Peluru& s) const { return iD == s.iD; }
	bool operator != (const Peluru& s) const { return !operator==(s); }
};

