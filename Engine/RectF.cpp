#include "RectF.h"

RectF::RectF(float left_in, float right_in, float top_in, float bottom_in)
	:
	left(left_in),
	right(right_in),
	top(top_in),
	bottom(bottom_in)

{
}

RectF::RectF(const Vec2& topLeft, const Vec2& bottomRight)
	:
	RectF(topLeft.x, bottomRight.x, topLeft.y, bottomRight.y)
{
}

RectF::RectF(const Vec2& topLeft, float width, float height)
	:
	RectF(topLeft, topLeft + Vec2(width, height))
{
}

RectF RectF::FromCentre(const Vec2& centre, float halfWidth, float halfHeight)
{
	const Vec2 half(halfWidth, halfHeight);
	return RectF(centre - half, centre + half);
}

bool RectF::isOverlappingWith(const RectF& other) const
{
	return right > other.left && left < other.right && top < other.bottom && bottom > other.top;
}

RectF RectF::getExpanded(float offset) const
{
	return RectF(left - offset, right + offset, top - offset, bottom + offset);
}

Vec2 RectF::getCenter() const
{
	return Vec2( (left + right)/2.0f, (top + bottom)/2.0f );
}
