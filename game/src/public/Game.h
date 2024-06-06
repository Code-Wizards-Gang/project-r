#pragma once

#include "GameTypes.h"
#include <memory>
#include "ScreenManager.h"

class ScreenManager;

class Game
{
public:
	Game();

	void Init();
	void Run();

private:
	WindowSettings m_Window;
	std::unique_ptr<ScreenManager> m_screenManager;
};