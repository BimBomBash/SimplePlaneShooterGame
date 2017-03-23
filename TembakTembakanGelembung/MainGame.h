#pragma once


class MainGame
{
private:
	int m_ScreenHeight, m_ScreenWidth;
	float m_xMouse, m_yMouse;
	SDL_Window *gWindow;
	SDL_GLContext glContext;
	std::list <Target> circles;
	std::list <Peluru> peluru;
	Pesawat *pesawat;

	static std::list <CircleCollider> circleColliders;
	static std::list <BoxCollider> boxColliders;

	void DrawGame();
	void AddCircle();
	void ProcessInput();
	void CollisionDetection();
	float Distance(Position a, Position b);

public:
	MainGame();
	~MainGame();
	int Init();
	void GameLoop();
	void Close();
};

