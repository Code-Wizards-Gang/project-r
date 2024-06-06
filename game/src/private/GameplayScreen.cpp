#include "GameplayScreen.h"
#include "raylib.h"

GameplayScreen::GameplayScreen():
	m_finished(false)
{

}

void GameplayScreen::Init() {
	m_finished = false;
}

void GameplayScreen::Update() {
	if (IsFinished()) {
		m_finished = true;
		return;
	}
}

void GameplayScreen::Draw() {
	DrawText("Gameplay Screen", 10, 10, 20, LIGHTGRAY);
}

void GameplayScreen::Unload() {
}

bool GameplayScreen::IsFinished() const {
	return m_finished;
}

