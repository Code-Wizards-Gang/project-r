#include "UI\Label.h"
#include "raylib.h"

Label::Label():
	m_font(12, GREEN)
{
}

void Label::Init()
{
	
}

void Label::Update()
{

}

void Label::Draw()
{
	DrawTextEx(m_font.FontFamily, m_text.c_str(), m_position, m_font.FontSize, m_font.Spacing, m_font.FontColor);
}

FontSettings Label::GetFont()
{
	return m_font;
}

void Label::SetFont(const FontSettings& newFont)
{
	m_font = newFont;

	// If new font does not have a font family, we use the default one
	if (m_font.FontFamily.texture.id == 0)
	{
		m_font.FontFamily = GetFontDefault();
	}
}

const char* Label::GetText()
{
	return m_text.c_str();
}

void Label::SetText(const char* newText)
{
	m_text = newText;
}

void Label::Append(char character)
{
	m_text.append(1, character);
}

void Label::Append(const char* text)
{
	m_text.append(text);
}

void Label::Append(std::string text)
{
	m_text.append(text);
}

int Label::Length() const
{
	return m_text.length();
}
