#include "stdafx.h"
#include <iostream>
#include <string>
#include <time.h>

#include "GameObject.h"


Collider::Collider()
{
}

Collider::~Collider()
{
}

GameObject::GameObject()
{
}

GameObject::~GameObject()
{
}

Position GameObject::GetPosition()
{
	Position pos;
	pos.x = m_xPos;
	pos.y = m_yPos;
	return pos;
}

std::string GameObject::GetTag()
{
	return m_tag;
}

void GameObject::OnCollision(Collider * _col)
{
}
