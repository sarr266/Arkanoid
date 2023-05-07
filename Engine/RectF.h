#pragma once
#include "Vec2.h"

class RectF
{
public:
	RectF() = default;
	RectF(int left_in, int right_in, int top_in, int bottom_in);
	RectF(const Vec2& topLeft, const Vec2& bottomRight);
	RectF(const Vec2& topLeft, float width, float height);
	//RectF(const Vec2& centre, float halfWidth, float halfHeight);
public:
	int left;
	int right;
	int top;
	int bottom;
};

