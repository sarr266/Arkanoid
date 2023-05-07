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
