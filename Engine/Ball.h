#pragma once

#include "RectF.h"
#include "Vec2.h"
#include "Graphics.h"

class Ball
{
public:
	Ball(const Vec2& pos_in, const Vec2& dir_in);
	void DrawBall(Graphics& gfx);
	void Update(float dt);  //in the update function ( remember that v = d/t, t = dt)
	int doWallCollision(const RectF& wall);
	void ReboundX();
	void ReboundY();
	RectF GetRect() const;
	Vec2 GetVelocity() const;
	Vec2 GetPosition() const;
	void SetDirection(const Vec2& dir);
private:
	static constexpr float radius = 7.0f;
	float speed = 400.0f;
	Vec2 pos;
	Vec2 vel;
};