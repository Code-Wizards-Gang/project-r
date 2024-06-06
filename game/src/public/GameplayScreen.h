#ifndef GAMEPLAYSCREEN_H
#define GAMEPLAYSCREEN_H

#include "Screen.h"
#include <memory>

class GameplayScreen : public Screen {
public:
	GameplayScreen();

	virtual void Init() override;
	virtual void Update() override;
	virtual void Draw() override;
	virtual void Unload() override;
	virtual bool IsFinished() const override;


private:
	bool m_finished;
	const char* m_title = "Project-R";

	int m_framesCounter = 0;
	float m_letterSpeed = 0.5f; // Letter apparition in seconds
	float m_totalTime = 0.f;
};

#endif // GAMEPLAYSCREEN_H