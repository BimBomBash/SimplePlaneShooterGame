#pragma once
struct Position {
	float x;
	float y;
};

class GameObject;

class Collider
{
protected:
	float m_xPos, m_yPos;
	float m_radius;
public:
	GameObject *gameObject;

	Collider();
	virtual ~Collider();

	virtual void CheckCollision() = 0;
};

class GameObject
{
protected:
	float m_xPos, m_yPos;
	int iD;
	std::string m_tag;
	Collider *collider;

public:
	GameObject();
	virtual ~GameObject();
	Position GetPosition();
	std::string GetTag();
	virtual void OnCollision(Collider *_col);
};

