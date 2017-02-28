#pragma once
#define PI 3.1415926535897932384626433832795

class Pesawat: public GameObject
{
private:
	float m_thickness;
	float m_speed;
	int m_rotation;
	int m_shootTime;
	void Vertex(float _x, float _y);
public:
	Pesawat();
	~Pesawat();
	int counter;
	int GetShootTime();
	void Draw();
	void GoLeft();
	void GoRight();
	void GoUp();
	void GoDown();
	Peluru Shoot(float _speed);
};

