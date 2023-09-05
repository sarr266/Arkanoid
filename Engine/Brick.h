#pragma once

#include "RectF.h"
#include "Colors.h"
#include "Graphics.h"
#include "Ball.h"

class Brick
{
public:
	Brick() = default;
	Brick(const RectF& rect_in, Color c_in);
	void DrawBrick(Graphics& gfx) const;
	bool CheckBallCollision(const Ball& ball) const;
	void ExecuteBallCollision(Ball& ball);
	Vec2 GetCentre() const;
public:
	static constexpr float padding = 1.0f;
	RectF rect;
	Color c;
	bool isDestroyed = false;
};
