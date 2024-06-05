#ifndef SCREENMANAGER_H
#define SCREENMANAGER_H

#include <unordered_map>
#include <memory>
#include "GameTypes.h"

class Screen;

class ScreenManager {
public:
	ScreenManager();
	~ScreenManager();

	void ChangeScreen(GameScreen screen);
	void Update();
	void Draw();

private:
	std::unordered_map<GameScreen, std::unique_ptr<Screen>> m_screens;
	GameScreen m_currentScreen;
	Screen* m_activeScreen;

	void LoadScreens();
};

#endif // SCREENMANAGER_H