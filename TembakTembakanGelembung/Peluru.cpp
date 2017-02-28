#include "stdafx.h"

#include <GL/glew.h>
#include <SDL.h>
#include <iostream>
#include <string>
#include <time.h>
#include "GameObject.h"
#include "Peluru.h"
#include "Settings.h"

void Peluru::Vertex(float _x, float _y)
{
	glVertex2f(m_xPos + ((_x * cos((float)m_rotation*PI / 180.0f) - _y * sin((float)m_rotation*PI / 180.0f)))*Settings::XScreenMultiplier(),
		m_yPos + (_x * sin((float)m_rotation*PI / 180.0f) + _y*cos((float)m_rotation*PI / 180.0f)) * Settings::YScreenMultiplier());
}

Peluru::Peluru(float _xPos, float _yPos, float _speed)
{
	iD = clock();
	m_xPos = _xPos; 
	m_yPos = _yPos;
	m_speed = _speed;
	m_rotation = 0;
}

Peluru::~Peluru()
{
}

void Peluru::Draw()
{
	m_yPos += m_speed;
	glBegin(GL_TRIANGLES);
	Vertex(0.0f, 0.02f);
	Vertex(0.005f, 0.0f);
	Vertex(-0.005f, 0.0f);

	Vertex(0.005f, 0.0f);
	Vertex(-0.0005f, 0.0f);
	Vertex(0.0f, -0.1f);
	glEnd();
}
