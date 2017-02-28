#pragma once
class Collider
{
private:
public:
	GameObject *gameObject;

	Collider();
	~Collider();

	virtual void CheckCollision() = 0;
};

