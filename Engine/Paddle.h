#pragma once

#include "Ball.h"
#include "Vec2.h"
#include "RectF.h"
#include "Colors.h"
#include "Graphics.h"
#include "Keyboard.h"

class Paddle
{
public:
	Paddle(const Vec2& pos_in, float halfWidth_in, float halfHeight_in);
	void Draw(Graphics& gfx) const;
	void DoWallCollision(const RectF& walls);
	bool DoBallCollision(Ball& ball);
	void Update(const Keyboard& kbd, float dt);
	RectF GetRect() const;
	void ResetCoolDown();
private:
	static constexpr float wingwidth = 15.0f;
	Color wingcolor = Colors::Gray;
	Color color = Colors::White;
	float exitFactor = 0.045f;
	float speed = 300.0f;
	float fixedZoneHalfWidth = 15.0f;
	float halfHeight;
	float halfWidth;
	Vec2 pos;
	bool isCoolDown = false;
};
