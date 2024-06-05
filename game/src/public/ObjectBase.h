#pragma once
#include "raylib.h"

class ObjectBase
{
public:
	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;

public:
	inline void SetPosition(Vector2 newPosition) { m_position = newPosition; }
	inline void SetPosition(int x, int y) 
	{ 
		m_position.x = x;
		m_position.y = y;
	}
	inline void SetPosition(float x, float y) 
	{ 
		m_position.x = x;
		m_position.y = y;
	}
	inline Vector2 GetPosition() const { return m_position; }

protected:
	Vector2 m_position;
};

