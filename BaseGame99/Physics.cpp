#include "Main.h"


Physics::Physics()
{
}


Physics::~Physics()
{
}

bool Physics::Collision(ALLEGRO_BITMAP* bg, int x, int y, int rval, int gval, int bval)
{
	bool is_collision = false;

	ALLEGRO_COLOR c = al_get_pixel(bg, x, y);
	unsigned char r, g, b;

	al_unmap_rgb(c, &r, &g, &b);

	if (r == rval && g == gval && b == bval)
		is_collision = true;

	return is_collision;
}

void Physics::GroundCheck(AnimatedObject* p, ALLEGRO_BITMAP* bg)
{
	ALLEGRO_COLOR c = al_get_pixel(bg, p->x_location, p->y_location + p->height);
	unsigned char r, g, b;
	al_unmap_rgb(c, &r, &g, &b);
	if (r == 0 && g == 0 && b == 0)
	{
		int bg_height = al_get_bitmap_height(bg);
		for (int i = p->y_location + p->height; i > 0; i--)
		{
			ALLEGRO_COLOR c_curr = al_get_pixel(bg, p->x_location, i);
			unsigned char r_curr, g_curr, b_curr;
			al_unmap_rgb(c_curr, &r_curr, &g_curr, &b_curr);
			if (r_curr == 255 && g_curr == 255 && b_curr == 255)
			{
				p->y_location = i - p->height + 1;
				break;
			}	
		}
	}
}

bool Physics::OnPowerup(AnimatedObject* p, Spring* s)
{
	bool is_on = false;
	if (p->x_location + p->width > s->x  && (p->y_location + p->height > s->y && p->y_location + p->height < s->y + 20))
		is_on = true;
	return is_on;
}
