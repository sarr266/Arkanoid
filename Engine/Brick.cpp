#include "Brick.h"

Brick::Brick(RectF& rect_in, Color c_in)
	:
	rect(rect_in),
	c(c_in)
{
}

void Brick::DrawBrick(Graphics& gfx) const
{
	gfx.DrawRect(rect, c);
}
