#ifndef LOGOSCREEN_H
#define LOGOSCREEN_H

#include "Screen.h"
#include "UI\Label.h"
#include <memory>


class TitleScreen : public Screen {
public:
	TitleScreen();

	virtual void Init() override;
	virtual void Update() override;
	virtual void Draw() override;
	virtual void DrawUI() override;
	virtual void Unload() override;
	virtual bool IsFinished() const override;

private:
	void AddLetter();

private:
	bool m_finished;
	const char* m_title = "Project-R";
	const char* m_prompt = "Click or press enter to continue";
	std::unique_ptr<Label> m_titleLabel;
	std::unique_ptr<Label> m_promptLabel;

	int m_framesCounter = 0;
	float m_letterSpeed = 0.1f; // Letter apparition in seconds
	float m_totalTime = 0.f;
};

#endif // LOGOSCREEN_H