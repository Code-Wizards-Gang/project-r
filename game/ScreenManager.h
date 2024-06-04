#ifndef SCREENMANAGER_H
#define SCREENMANAGER_H

#include <unordered_map>
#include <memory>
#include "Screen.h"

enum class GameScreen {UNKNOWN = -1, LOGO = 0, TITLE, OPTIONS, GAMEPLAY};


class ScreenManager {
public:
	ScreenManager();
	~ScreenManager();

	void ChangeScreen(GameScreen screen);
	void Update();
	void Draw();

private:
	std::unordered_map<GameScreen, std::unique_ptr<Screen>> screens;
	GameScreen currentScreen;
	Screen* activeScreen;

	void LoadScreens();
};

#endif // SCREENMANAGER_H