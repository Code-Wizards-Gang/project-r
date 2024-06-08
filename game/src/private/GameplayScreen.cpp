#include "GameplayScreen.h"
#include "raylib.h"
#include "Application.h"

GameplayScreen::GameplayScreen():
	m_finished(false),
	m_player("Pantoine")
{

}

void GameplayScreen::Init() {
	m_finished = false;

	m_player.SetPosition(GetScreenWidth()/2, GetScreenHeight()/2);
	m_player.SetSpeed(300);

	Vector2 cameraTarget;
	cameraTarget.x = m_player.GetPosition().x;
	cameraTarget.y = m_player.GetPosition().y;
	Application::GetCamera().target = cameraTarget;
}

void GameplayScreen::Update() {
	if (IsFinished()) {
		m_finished = true;
		return;
	}

	float deltaTime = GetFrameTime();
	m_totalTime += deltaTime;

	Vector2 velocity;

	velocity.x = IsKeyDown(KEY_D) ? 1 : IsKeyDown(KEY_A) ? -1 : 0;
	velocity.y = IsKeyDown(KEY_S) ? 1 : IsKeyDown(KEY_W) ? -1 : 0;

	m_player.Move(velocity, deltaTime);
}

void GameplayScreen::Draw() {
	m_player.Draw();
}

void GameplayScreen::DrawUI()
{
	m_player.DrawUI();
}

void GameplayScreen::Unload() {
}

bool GameplayScreen::IsFinished() const {
	return m_finished;
}

