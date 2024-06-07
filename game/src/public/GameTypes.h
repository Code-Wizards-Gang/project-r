#pragma once

enum class GameScreen { UNKNOWN = -1, LOGO = 0, TITLE, OPTIONS, GAMEPLAY };

struct WindowSettings
{
	const char* Title = "project-r";
	float Width = 300.f;
	float Height = Width / 16 * 10; // Format 16:10
	int Scale = 3;
	int TargetFPS = 120;
};