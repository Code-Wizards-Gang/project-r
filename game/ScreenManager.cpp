#include "ScreenManager.h"
#include "TitleScreen.h"

ScreenManager::ScreenManager() : currentScreen(GameScreen::UNKNOWN), activeScreen(nullptr) {
	LoadScreens();
}

ScreenManager::~ScreenManager() {
	if (activeScreen) {
		activeScreen->Unload();
	}
}

void ScreenManager::LoadScreens() {
	screens[GameScreen::TITLE] = std::make_unique<TitleScreen>();
}

void ScreenManager::ChangeScreen(GameScreen screen) {
	if (activeScreen) {
		activeScreen->Unload();
	}

	currentScreen = screen;
	activeScreen = screens[currentScreen].get();
	if (activeScreen) {
		activeScreen->Init();
	}
}

void ScreenManager::Update() {
	if (activeScreen) {
		activeScreen->Update();
		if (activeScreen->IsFinished()) {
			// Add logic to change screens
			// e.g. ChangeScreen(GameScreen::TITLE); tia capté
		}
	}
}

void ScreenManager::Draw() {
	if (activeScreen) {
		activeScreen->Draw();
	}
}