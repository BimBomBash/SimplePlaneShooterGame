#include "stdafx.h"
#include <GL/glew.h>
#include <SDL.h>
#include <iostream>
#include <string>
#include <time.h>

#include "GameObject.h"
#include "Target.h"
#include "Settings.h"

Target::Target(float xStartPos, float yStartPos)
{
	iD = clock();
	m_radius = (float)(rand() % 15) / 100.0f;
	m_segment = 100;
	m_xPos = xStartPos;
	m_yPos = yStartPos;
	m_thickness = 0.01f;
	sdAlpha = 0;
}

Target::~Target()
{
}

float Target::getRadius()
{
	return m_radius;
}

void Target::Move()
{
	float DsdAlpha = (float)(((double)(rand() % 30 - 15))) / 180.0f * PI;
	sdAlpha = sdAlpha + DsdAlpha;

	m_xPos = m_xPos + 0.002f * cos(sdAlpha);
	m_yPos = m_yPos + 0.002f * sin(sdAlpha);

	if ((m_xPos>1) || (m_yPos>1) || (m_xPos<-1) || (m_yPos<-1))
	{
		Bounce();
	}
	DrawCircle();
}

void Target::DrawCircle()
{
	glBegin(GL_LINE_LOOP);
	glLineWidth(m_thickness);
	for (int ii = 0; ii < m_segment; ii++)
	{
		float theta = 2.0f * PI * float(ii) / float(m_segment);//get the current angle 

		float x = m_radius * cosf(theta) * Settings::XScreenMultiplier();//calculate the x component 
		float y = m_radius * sinf(theta) * Settings::YScreenMultiplier();//calculate the y component 

		glVertex2f(x + m_xPos, y + m_yPos);//output vertex 
	}
	glEnd();
}

void Target::Bounce()
{
	sdAlpha = sdAlpha + PI;
}
