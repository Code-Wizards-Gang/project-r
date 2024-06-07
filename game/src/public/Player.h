#pragma once
#include "ObjectBase.h"

#include <string>

class Player :
    public ObjectBase
{
public:
    Player();
    Player(const char* name);

    void Init() override;
    void Update() override;
    void Draw() override;
    void DrawUI() override;

public:
    void SetSpeed(const float& newSpeed) { m_speed = newSpeed; }
    float GetSpeed() const { return m_speed; }

public:
    void Move(const Vector2& velocity, const float& deltaTime);

protected:
    std::string m_name;

    float m_speed;

};

