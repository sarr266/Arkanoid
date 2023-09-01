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
		gfx.DrawRect(rect.getExpanded(-padding), c);
	}
}

bool Brick::DoBallCollision(Ball& ball)
{
	if (!isDestroyed && rect.isOverlappingWith(ball.GetRect()))
	{
		const Vec2 ballPos = ball.GetPosition();
		if (ballPos.x >= rect.left && ballPos.x <= rect.right)
		{
			ball.ReboundY();
		}
		else
		{
			ball.ReboundX();
		}
		isDestroyed = true;
		return true;
	}
	return false;
}
