#pragma once

#include "GameTypes.h"
#include <vector>
#include <memory>

class ObjectBase;

class Game
{
public:
	Game();

	void Init();
	void Run();

private:
	WindowSettings m_Window;

};