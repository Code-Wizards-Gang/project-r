#pragma once
#include "ObjectBase.h"
#include "UITypes.h"
#include <string>

class Label :
    public ObjectBase
{
public:
    Label();

    void Init() override;
    void Update() override;
    void Draw() override;

public:
    FontSettings GetFont();
    void SetFont(const FontSettings& newFont);

    const char* GetText();
    void SetText(const char* newText);

    void Append(char character);
    void Append(const char* text);
    void Append(std::string text);

    int Length() const;

protected:
    FontSettings m_font;
    std::string m_text;
};

