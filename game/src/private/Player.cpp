#include "Player.h"

Player::Player():
	m_speed(30)
{
}

Player::Player(const char* name) :
	m_speed(30)
{
	m_name = name;
}

void Player::Init()
{
}

void Player::Update()
{

}

void Player::Draw()
{
	DrawRectangle(m_position.x, m_position.y, 40, 40, RED);
}

void Player::DrawUI()
{
	DrawText(m_name.c_str(), m_position.x, m_position.y - 5, 12, BLUE);
}

void Player::Move(const Vector2& velocity, const float& deltaTime)
{
	m_position.x += velocity.x * deltaTime * m_speed;
	m_position.y += velocity.y * deltaTime * m_speed;
}
