#include "Ball.h"
#include "SpriteCodex.h"

Ball::Ball(Vec2& pos_in, Vec2& vel_in)
	:
	pos(pos_in),
	vel(vel_in)
{
}

void Ball::DrawBall(Graphics& gfx)
{
	SpriteCodex::DrawBall(pos, gfx);
}

void Ball::Update(float dt)
{
	pos += vel * dt;
}

bool Ball::isWallCollision(RectF& wall)
{
	bool isCollided = false;
	const RectF rect = GetRect();
	if (rect.left < wall.left)
	{
		pos.x += (wall.left - rect.left);
		ReboundX();
		isCollided = true;
	}
	else if (rect.right > wall.right)
	{
		pos.x -= (rect.right - wall.right);
		ReboundX();
		isCollided = true;
	}
	if (rect.top < wall.top)
	{
		pos.y += (wall.top - rect.top);
		ReboundY();
		isCollided = true;
	}
	else if (rect.bottom > wall.bottom)
	{
		pos.y -= (rect.bottom - wall.bottom);
		ReboundY();
		isCollided = true;
	}
	return isCollided;
}

void Ball::ReboundX()
{
	vel.x = -vel.x;
}

void Ball::ReboundY()
{
	vel.y = -vel.y;
}

RectF Ball::GetRect()
{
	return RectF::FromCentre(pos, radius, radius);
}
