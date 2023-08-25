#include "Brick.h"

Brick::Brick(const RectF& rect_in, Color c_in)
	:
	rect(rect_in),
	c(c_in)
{
}

void Brick::DrawBrick(Graphics& gfx) const
{
	if (!isDestroyed)
	{
		gfx.DrawRect(rect, c);
	}
}

bool Brick::DoBallCollision(Ball& ball)
{
	if (!isDestroyed && rect.isOverlappingWith(ball.GetRect()))
	{
		ball.ReboundY();
		isDestroyed = true;
		return true;
	}
	return false;
}
