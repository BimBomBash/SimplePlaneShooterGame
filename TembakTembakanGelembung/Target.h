#pragma once
#define PI 3.1415926535897932384626433832795

class Target:public GameObject
{
private:
	int m_segment;
	float m_radius;
	float m_thickness;
	float sdAlpha;
public:
	Target(float xStartPos, float yStartPos);
	~Target();
	float getRadius();
	void Move();
	void DrawCircle();
	void Bounce();
	bool operator == (const Target& s) const { return iD == s.iD; }
	bool operator != (const Target& s) const { return !operator==(s); }
};

