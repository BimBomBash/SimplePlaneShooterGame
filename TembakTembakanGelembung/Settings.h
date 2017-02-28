#pragma once


class Settings
{
private:
public:
	Settings();
	~Settings();
	static const int xScreenSize = 480;
	static const int yScreenSize = 640;
	static float XScreenMultiplier();
	static float YScreenMultiplier();
};

