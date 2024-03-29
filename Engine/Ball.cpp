#include "Ball.h"
#include "SpriteCodex.h"

Ball::Ball(const Vec2& pos_in, const Vec2& dir_in)
	:
	pos(pos_in)
{
	SetDirection(dir_in);
}

void Ball::DrawBall(Graphics& gfx)
{
	SpriteCodex::DrawBall(pos, gfx);
}

void Ball::Update(float dt)
{
	pos += vel * dt;
}

Ball::WallCollisionResult Ball::doWallCollision(const RectF& wall)
{
	WallCollisionResult isCollided = WallCollisionResult::None;
	const RectF rect = GetRect();
	if (rect.left <= wall.left)
	{
		pos.x += (wall.left - rect.left);
		ReboundX();
		isCollided = WallCollisionResult::SideTop;
	}
	else if (rect.right > wall.right)
	{
		pos.x -= rect.right - wall.right;
		ReboundX();
		isCollided = WallCollisionResult::SideTop;
	}
	if (rect.top <= wall.top)
	{
		pos.y += (wall.top - rect.top);
		ReboundY();
		isCollided = WallCollisionResult::SideTop;
	}
	else if (rect.bottom > wall.bottom)
	{
		pos.y -= (rect.bottom - wall.bottom);
		ReboundY();
		isCollided = WallCollisionResult::Bottom;
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

RectF Ball::GetRect() const
{
	return RectF::FromCentre(pos, radius, radius);
}

Vec2 Ball::GetVelocity() const
{
	return vel;
}

Vec2 Ball::GetPosition() const
{
	return pos;
}

void Ball::SetDirection(const Vec2& dir)
{
	vel = dir.GetNormalized() * speed;
}
