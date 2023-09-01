#pragma once

#include "RectF.h"
#include "Vec2.h"
#include "Graphics.h"

class Ball
{
public:
	Ball(Vec2& pos_in, Vec2& vel_in);
	void DrawBall(Graphics& gfx);
	void Update(float dt);  //in the update function ( remember that v = d/t, t = dt)
	bool doWallCollision(const RectF& wall);
	void ReboundX();
	void ReboundY();
	RectF GetRect();
	Vec2 GetVelocity() const;
	Vec2 GetPosition() const;
private:
	static constexpr float radius = 7.0f;
	Vec2 pos;
	Vec2 vel;
};