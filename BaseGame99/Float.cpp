#include "Main.h"


Float::Float()
{
	is_float = false;
	bmp = al_load_bitmap("umbrella.png");
	x_speed = y_speed = float_time = 0;
	x = y = -100;
	bmpw = al_get_bitmap_width(bmp);
	bmph = al_get_bitmap_height(bmp);
}


Float::~Float()
{
}

void Float::AddTime(AnimatedObject* p)
{
	float_time++;
	if (float_time > 175)
	{
		float_time = 0;
		is_float = false;
		x = y = -100;
		x_speed = y_speed = 0;
		p->y_speed = 0;
	}
}
