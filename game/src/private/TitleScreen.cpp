#include "TitleScreen.h"
#include "raylib.h"

TitleScreen::TitleScreen():
	m_titleLabel(std::make_unique<Label>()),
	m_finished(false)
{

}

void TitleScreen::Init() {
	m_finished = false;
	m_titleLabel = std::make_unique<Label>();

	FontSettings titleFont;
	titleFont.FontColor = BLUE;
	titleFont.FontSize = 80;

	m_titleLabel->SetFont(titleFont);
	m_titleLabel->SetPosition((GetScreenWidth() / 2 - titleFont.FontSize / 2 * strlen(m_title) / 2), GetScreenHeight() / 2 - titleFont.FontSize / 2);
}

void TitleScreen::Update() {
	if (IsFinished()) {
		m_finished = true;
		return;
	}

	float deltaTime = GetFrameTime();
	m_totalTime += deltaTime;

	if (m_totalTime >= m_letterSpeed)
	{
		AddLetter();
		m_totalTime = 0;
	}
}

void TitleScreen::Draw() {
	m_titleLabel->Draw();
}

void TitleScreen::Unload() {
	m_framesCounter = 0;
}

bool TitleScreen::IsFinished() const {
	return m_titleLabel->Length() == strlen(m_title);
}

void TitleScreen::AddLetter()
{
	m_titleLabel->Append(m_title[m_titleLabel->Length()]);
}
