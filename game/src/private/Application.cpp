#include "Application.h"
#include "ScreenManager.h"
#include "raylib.h"
#include "string"


static Application* s_instance = nullptr;


Application::Application(const WindowSettings windowSettings):
	m_window(windowSettings),
	m_screenManager(std::make_unique<ScreenManager>()),
	m_camera()
{
	s_instance = this;
}

Application::~Application()
{
	s_instance = nullptr;
}

Application& Application::Get()
{
	return *s_instance;
}

void Application::Run()
{
	InitWindow(m_window.Width * m_window.Scale, m_window.Height * m_window.Scale, m_window.Title);
	SetTargetFPS(m_window.TargetFPS);

	m_camera = { 0 };
	Vector2 offset;
	offset.x = m_window.Width / 2;
	offset.y = m_window.Height / 2;
	m_camera.offset = offset;
	m_camera.rotation = 0.0f;
	m_camera.zoom = 1.0f;

	m_screenManager->ChangeScreen(GameScreen::TITLE);

	while (!WindowShouldClose())
	{
		m_screenManager->Update();

		BeginDrawing();
		ClearBackground(BEIGE);

		BeginMode2D(m_camera);
			m_screenManager->Draw();
		EndMode2D();

		DrawText(std::to_string(GetFPS()).c_str(), 30, 20, 24, RED);

		m_screenManager->DrawUI();
		EndDrawing();
	}

	CloseWindow();
}