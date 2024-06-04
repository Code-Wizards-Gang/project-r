#include "raylib.h"
#include "string"

int main()
{
	InitWindow(800, 480, "project-r");

	SetTargetFPS(60);

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(BEIGE);

		DrawText(std::to_string(GetFPS()).c_str(), 30, 20, 24, RED);

		EndDrawing();
	}

	CloseWindow();
}