#include "raylib.h"
#include "string"

struct WindowSettings
{
	const char* Title = "project-r";
	int Width = 800;
	int Height = 480;
	int TargetFPS = 60;
};

int main()
{
	WindowSettings MainWindow;
	InitWindow(MainWindow.Width, MainWindow.Height, MainWindow.Title);

	SetTargetFPS(MainWindow.TargetFPS);

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(BEIGE);

		DrawText(std::to_string(GetFPS()).c_str(), 30, 20, 24, RED);

		EndDrawing();
	}

	CloseWindow();
}