#pragma once

#include "RectF.h"
#include "Colors.h"
#include "Graphics.h"
#include "Ball.h"

class Brick
{
public:
	Brick(const RectF& rect_in, Color c_in);
	void DrawBrick(Graphics& gfx) const;
	bool DoBallCollision(Ball& ball);
public:
	RectF rect;
	Color c;
	bool isDestroyed = false;
};
