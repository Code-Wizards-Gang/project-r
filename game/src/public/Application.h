#pragma once

#include "GameTypes.h"
#include <memory>
#include "ScreenManager.h"
#include "raylib.h"

class Application
{
public:
	Application(const WindowSettings windowSettings = WindowSettings());
	~Application();

	void Run();

public:
	static Application& Get();
	static Camera2D& GetCamera() { return Get().m_camera; }

private:
	WindowSettings m_window;
	Camera2D m_camera;
	std::unique_ptr<ScreenManager> m_screenManager;

	bool m_gameStarted = false;
};