#include "stdafx.h"
#include <GL/glew.h>
#include <SDL.h>
#include <iostream>
#include <list>
#include <cmath>
#include <string>
#include "GameObject.h"
#include "Target.h"
#include "Peluru.h"
#include "Pesawat.h"
#include "Settings.h"
#include "MainGame.h"

MainGame::MainGame()
{
}


MainGame::~MainGame()
{
}

int MainGame::Init()
{
	pesawat = new Pesawat();
	m_ScreenHeight = Settings::yScreenSize;
	m_ScreenWidth = Settings::xScreenSize;

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		return -1;
	}

	gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, m_ScreenWidth, m_ScreenHeight, SDL_WINDOW_OPENGL);

	if (gWindow == NULL)
	{
		printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		return -1;
	}
	glContext = SDL_GL_CreateContext(gWindow);

	if (glContext == nullptr) {
		std::cout << "Context failed" << std::endl;
		return -1;
	}

	if (glewInit() != GLEW_OK) {
		std::cout << "GLEW init error" << std::endl;
		return -1;
	}

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	return 0;
}

void MainGame::ProcessInput()
{
	SDL_Event event;

	const Uint8 *state = SDL_GetKeyboardState(NULL);

	//continuous-response keys
	if (state[SDL_SCANCODE_UP]) {
		pesawat -> GoUp();
	}
	if (state[SDL_SCANCODE_DOWN]) {
		pesawat->GoDown();
	}
	if (state[SDL_SCANCODE_LEFT]) {
		pesawat->GoLeft();
	}
	if (state[SDL_SCANCODE_RIGHT]) {
		pesawat->GoRight();
	}
	if (state[SDL_SCANCODE_SPACE]) {
		if (pesawat->counter >= pesawat->GetShootTime()) {
			pesawat->counter = 0;
			peluru.push_back(pesawat->Shoot(0.01f));
		
		}
	}

	while (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT:
			Close();
			break;
		case SDL_MOUSEMOTION:
			m_xMouse = (float)(event.motion.x - m_ScreenWidth / 2) / (float)(m_ScreenWidth / 2);
			m_yMouse = -(float)(event.motion.y - m_ScreenHeight / 2) / (float)(m_ScreenHeight / 2);
			break;
		case SDL_MOUSEBUTTONDOWN:
			AddCircle();
			break;
		case SDL_KEYDOWN:
			break;
		}
	}
}

void MainGame::CollisionDetection()
{
	for (auto iter = circles.begin(); iter != circles.end(); iter++) {
		for (auto iiter = circles.begin(); iiter != circles.end(); iiter++) {
			if (Distance(iter->GetPosition(), iiter->GetPosition()) <= (iter->getRadius() + iiter->getRadius()) && iter != iiter) {
				iter->Bounce();
			}
		}
	}
	for (auto iter = peluru.begin(); iter != peluru.end(); iter++) {
		bool okay = true;
		for (auto iiter = circles.begin(); iiter != circles.end(); iiter++) {
			if (Distance(iter->GetPosition(), iiter->GetPosition()) <=  iiter->getRadius()) {
				peluru.remove(*iter);
				circles.remove(*iiter);
				okay = false;
				break;
			}
		}
		if (!okay) break;
	}
}

float MainGame::Distance(Position a, Position b)
{
	float xDist = (a.x - b.x);
	float yDist = (a.y - b.y);
	float dist = sqrt(powf(xDist, 2) + powf(yDist, 2));
	return dist;
}

void MainGame::GameLoop()
{
	while (true) {
		DrawGame();
		CollisionDetection();
		ProcessInput();
		pesawat->counter++;
		SDL_Delay(10);
	}
}

void MainGame::Close()
{
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	SDL_Quit();
}

void MainGame::DrawGame()
{
	glClearDepth(1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	for (auto iter = circles.begin(); iter != circles.end(); iter++) {
		iter->Move();
	}
	pesawat->Draw();
	for (auto iter = peluru.begin(); iter != peluru.end(); iter++) {
		iter->Draw();
	}
	SDL_GL_SwapWindow(gWindow);
}

void MainGame::AddCircle()
{
	Target cir(m_xMouse, m_yMouse);
	circles.push_back(cir);
}


