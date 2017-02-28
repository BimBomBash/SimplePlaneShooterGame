#pragma once
struct Position {
	float x;
	float y;
};

class GameObject
{
protected:
	float m_xPos, m_yPos;
	int iD;
	std::string m_tag;
	//Collider *collider;

public:
	GameObject();
	~GameObject();
	Position GetPosition();
	std::string GetTag();
	//virtual void OnCollision(Collider *_col) = 0;
};

