#include "ScreenManager.h"
#include "TitleScreen.h"

ScreenManager::ScreenManager() : m_currentScreen(GameScreen::UNKNOWN), m_activeScreen(nullptr) {
	LoadScreens();
}

ScreenManager::~ScreenManager() {
	if (m_activeScreen) {
		m_activeScreen->Unload();
	}
}

void ScreenManager::LoadScreens() {
	m_screens[GameScreen::TITLE] = std::make_unique<TitleScreen>();
}

void ScreenManager::ChangeScreen(GameScreen screen) {
	if (m_activeScreen) {
		m_activeScreen->Unload();
	}

	m_currentScreen = screen;
	m_activeScreen = m_screens[m_currentScreen].get();
	if (m_activeScreen) {
		m_activeScreen->Init();
	}
}

void ScreenManager::Update() {
	if (m_activeScreen) {
		m_activeScreen->Update();
		if (m_activeScreen->IsFinished()) {
			ChangeScreen(m_currentScreen);
		}
	}
}

void ScreenManager::Draw() {
	if (m_activeScreen) {
		m_activeScreen->Draw();
	}
}