#pragma once

enum class GameScreen { UNKNOWN = -1, LOGO = 0, TITLE, OPTIONS, GAMEPLAY };

struct WindowSettings
{
	const char* Title = "project-r";
	int Width = 800;
	int Height = 480;
	int TargetFPS = 60;
};