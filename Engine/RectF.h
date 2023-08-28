#pragma once
#include "Vec2.h"

class RectF
{
public:
	RectF() = default;
	RectF(float left_in, float right_in, float top_in, float bottom_in);
	RectF(const Vec2& topLeft, const Vec2& bottomRight);
	RectF(const Vec2& topLeft, float width, float height);
	static RectF FromCentre(const Vec2& centre, float halfWidth, float halfHeight); //gets the rectangular outline of the ball
	bool isOverlappingWith(const RectF& other) const;
public:
	int left;
	int right;
	int top;
	int bottom;
};

