#include "Brick.h"
#include <assert.h>
#include <cmath>

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

bool Brick::CheckBallCollision(const Ball& ball) const
{
	return !isDestroyed && rect.isOverlappingWith(ball.GetRect());
}

void Brick::ExecuteBallCollision(Ball& ball)
{
	assert(CheckBallCollision(ball));
	const Vec2 ballPos = ball.GetPosition();

	if (std::signbit(ball.GetVelocity().x) == std::signbit( (ballPos - GetCentre()).x ))
	{
		ball.ReboundY();
	}
	else if (ballPos.x >= rect.left && ballPos.x <= rect.right)
	{
		ball.ReboundY();
	}
	else
	{
		ball.ReboundX();
	}
	isDestroyed = true;
}

Vec2 Brick::GetCentre() const
{
	return rect.getCenter();
}
