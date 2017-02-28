#include "stdafx.h"
#include <GL/glew.h>
#include <SDL.h>
#include <iostream>
#include <string>
#include "GameObject.h"
#include "Peluru.h"
#include "Pesawat.h"
#include "Settings.h"

Pesawat::Pesawat()
{
	m_rotation = 0;
	m_xPos = 0.0f;
	m_yPos = -0.8f;
	m_speed = 0.01f;
	m_shootTime = 30;
	counter = 0;
}

void Pesawat::Vertex(float _x, float _y)
{
	glVertex2f(m_xPos+((_x * cos((float)m_rotation*PI/180.0f) - _y * sin((float)m_rotation*PI / 180.0f)))*Settings::XScreenMultiplier(),
		m_yPos + (_x * sin((float)m_rotation*PI / 180.0f) + _y*cos((float)m_rotation*PI / 180.0f)) * Settings::YScreenMultiplier());
}


Pesawat::~Pesawat()
{
}

int Pesawat::GetShootTime()
{
	return m_shootTime;
}

void Pesawat::Draw()
{
	//glColor3i(255, 0, 0);
	glLineWidth(m_thickness);
	glBegin(GL_TRIANGLES);
	Vertex(0.0f, 0.0f); 
	Vertex(0.02f, -0.1f);
	Vertex(-0.02f,-0.1f);

	Vertex(0.12f, -0.14f);
	Vertex(0.02f, -0.10f);
	Vertex(0.02f, -0.14f);
	
	Vertex(-0.12f, -0.14f);
	Vertex(-0.02f, -0.10f);
	Vertex(-0.02f, -0.14f);
	
	Vertex(-0.02f, -0.16f);
	Vertex(0.02f, -0.16f);
	Vertex(-0.02f, -0.10f);
	
	Vertex(0.02f, -0.16f);
	Vertex(-0.02f, -0.10f);
	Vertex(0.02f, -0.10f);

	Vertex(0.12f, -0.14f);
	Vertex(0.1f, -0.14f);
	Vertex(0.11f, -0.10f);

	Vertex(-0.12f, -0.14f);
	Vertex(-0.1f, -0.14f);
	Vertex(-0.11f, -0.10f);
	glEnd();
}

void Pesawat::GoLeft()
{
	if (m_xPos>-1.0f)m_xPos = m_xPos - m_speed*Settings::XScreenMultiplier();
}

void Pesawat::GoRight()
{
	if (m_xPos<1.0f)m_xPos = m_xPos + m_speed*Settings::XScreenMultiplier();
}

void Pesawat::GoUp()
{
	if (m_yPos<1.0f)m_yPos = m_yPos + m_speed*Settings::YScreenMultiplier();
}

void Pesawat::GoDown()
{
	if (m_xPos>-1.0f)m_yPos = m_yPos - m_speed*Settings::YScreenMultiplier();
}

Peluru Pesawat::Shoot(float _speed)
{
	Peluru pel (m_xPos, m_yPos, _speed);
	return pel;
}

