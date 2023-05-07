#pragma once

#include "RectF.h"
#include "Vec2.h"
#include "Graphics.h"

class Ball
{
public:
	Ball(Vec2& pos_in, Vec2& vel_in);
	void DrawBall(Graphics& gfx);
private:
	static constexpr float radius = 7.0f;
	Vec2 pos;
	Vec2 vel;
};