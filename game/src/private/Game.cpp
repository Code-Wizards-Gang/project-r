#include "Game.h"
#include "ScreenManager.h"
#include "raylib.h"
#include "string"
#include "ObjectBase.h"

Game::Game():
	m_screenManager(std::make_unique<ScreenManager>())
{
	
}

void Game::Init()
{
	InitWindow(m_Window.Width, m_Window.Height, m_Window.Title);
	SetTargetFPS(m_Window.TargetFPS);
}

void Game::Run()
{
	m_screenManager->ChangeScreen(GameScreen::TITLE);

	while (!WindowShouldClose())
	{
		m_screenManager->Update();

		BeginDrawing();
		ClearBackground(BEIGE);

		DrawText(std::to_string(GetFPS()).c_str(), 30, 20, 24, RED);

		m_screenManager->Draw();
		EndDrawing();
	}

	CloseWindow();
}