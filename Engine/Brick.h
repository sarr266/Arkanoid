#pragma once

#include "RectF.h"
#include "Colors.h"
#include "Graphics.h"

class Brick
{
	Brick(RectF& rect_in, Color c_in);
	void DrawBrick(Graphics& gfx) const;
public:
	RectF& rect;
	Color c;
	bool isDestroyed = false;
};
