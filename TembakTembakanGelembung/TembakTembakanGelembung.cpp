// TembakTembakanGelembung.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <GL/glew.h>
#include <SDL.h>
#include <iostream>
#include <list>
#include <string>
#include "GameObject.h"
#include "Collider.h"
#include "Target.h"
#include "Peluru.h"
#include "Pesawat.h"
#include "MainGame.h"

MainGame mainGame;
const int SCREEN_WIDTH = 480;
const int SCREEN_HEIGHT = 480;

int main(int argc, char* args[])
{
	if (mainGame.Init() == 0) mainGame.GameLoop();
	return 0;
}
