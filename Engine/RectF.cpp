#include "RectF.h"

RectF::RectF(int left_in, int right_in, int top_in, int bottom_in)
	:
	left(left_in),
	right(right_in),
	top(top_in),
	bottom(bottom_in)

{
}

RectF::RectF(const Vec2& topLeft, const Vec2& bottomRight)
{
	RectF(topLeft.x, bottomRight.x, topLeft.y, bottomRight.y);
}

RectF::RectF(const Vec2& topLeft, float width, float height)
{
	RectF(topLeft, Vec2(width, height));
}

RectF RectF::FromCentre(const Vec2& centre, float halfWidth, float halfHeight)
{
	const Vec2 half(halfWidth, halfHeight);
	return RectF(centre - half, centre + half);
}
