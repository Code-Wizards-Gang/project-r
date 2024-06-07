#include "TitleScreen.h"
#include "raylib.h"

TitleScreen::TitleScreen():
	m_titleLabel(std::make_unique<Label>()),
	m_promptLabel(std::make_unique<Label>()),
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

	Vector2 titleSize = MeasureTextEx(titleFont.FontFamily, m_title, titleFont.FontSize, titleFont.Spacing);
	m_titleLabel->SetPosition((GetScreenWidth() - titleSize.x) / 2, (GetScreenHeight() - titleSize.y) / 2);

	FontSettings promptFont;
	promptFont.FontColor = DARKGRAY;
	promptFont.FontSize = 20;

	m_promptLabel->SetFont(promptFont);

	Vector2 promptSize = MeasureTextEx(promptFont.FontFamily, m_prompt, promptFont.FontSize, promptFont.Spacing);
	m_promptLabel->SetText(m_prompt);
	m_promptLabel->SetPosition((int)(GetScreenWidth() - promptSize.x) / 2, GetScreenHeight() / 2 + 100);
}

void TitleScreen::Update() {
	m_finished = (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP)) && m_titleLabel->Length() == strlen(m_title);
	float deltaTime = GetFrameTime();
	m_totalTime += deltaTime;


	if (m_totalTime >= m_letterSpeed)
	{
		AddLetter();
		m_totalTime = 0;
	}
}

void TitleScreen::Draw() {
}

void TitleScreen::DrawUI()
{
	m_titleLabel->DrawUI();
	if (m_titleLabel->Length() == strlen(m_title)) {
		m_promptLabel->DrawUI();
	}
}

void TitleScreen::Unload() {
	m_framesCounter = 0;
}

bool TitleScreen::IsFinished() const {
	return m_finished;
}

void TitleScreen::AddLetter()
{
	if (m_titleLabel->Length() < strlen(m_title)) {
		m_titleLabel->Append(m_title[m_titleLabel->Length()]);
	}
}
