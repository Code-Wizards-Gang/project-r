#ifndef GAMEPLAYSCREEN_H
#define GAMEPLAYSCREEN_H

#include "Screen.h"
#include "Player.h"

class GameplayScreen : public Screen {
public:
	GameplayScreen();

	virtual void Init() override;
	virtual void Update() override;
	virtual void Draw() override;
	virtual void DrawUI() override;
	virtual void Unload() override;
	virtual bool IsFinished() const override;


private:
	Player m_player;

private:
	bool m_finished;
	const char* m_title = "Project-R";

	int m_framesCounter = 0;
	float m_totalTime = 0.f;
};

#endif // GAMEPLAYSCREEN_H