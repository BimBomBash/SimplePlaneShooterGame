#include "stdafx.h"
#include <string>
#include "Settings.h"


Settings::Settings()
{
}


Settings::~Settings()
{
}

float Settings::XScreenMultiplier()
{
	if (xScreenSize > yScreenSize) {
		return (float)yScreenSize / (float)xScreenSize;
	}
	else {
		return 1.0f;
	}
}

float Settings::YScreenMultiplier()
{
	if (xScreenSize < yScreenSize) {
		return (float)xScreenSize / (float)yScreenSize;
	}
	else {
		return 1.0f;
	}
}

