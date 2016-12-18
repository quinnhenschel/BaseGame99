#include "Main.h"


Physics::Physics()
{
}


Physics::~Physics()
{
}

bool Physics::Collision(ALLEGRO_BITMAP* bg, int x, int y)
{
	bool is_collision = false;
	/*int p_width = al_get_bitmap_width(p->bmp);
	int p_height = al_get_bitmap_height(p->bmp);*/

	ALLEGRO_COLOR c = al_get_pixel(bg, x, y);
	/*ALLEGRO_COLOR c_r = al_get_pixel(p->bmp, p->x + p_width, p->y);
	ALLEGRO_COLOR c_bl = al_get_pixel(p->bmp, p->x, p->y + p_height);
	ALLEGRO_COLOR c_br = al_get_pixel(p->bmp, p->x + p_width, p->y + p_height);
	unsigned char r, g, b, r_r, g_r, b_r, r_bl, g_bl, b_bl, r_br, g_br, b_br;*/
	unsigned char r, g, b;

	al_unmap_rgb(c, &r, &g, &b);
	/*al_unmap_rgb(c_r, &r_r, &g_r, &b_r);
	al_unmap_rgb(c_bl, &r_bl, &g_bl, &b_bl);
	al_unmap_rgb(c_br, &r_br, &g_br, &b_br);*/

	/*if ((r == 0 && g == 0 && b == 0) || (r_r == 0 && g_r == 0 && b_r == 0) || (r_bl == 0 && g_bl == 0 && b_bl == 0) || (r_br == 0 && g_br == 0 && b_br == 0))
		is_collision = true;*/
	if (r == 0 && g == 0 && b == 0)
		is_collision = true;

	return is_collision;
}
