#include "Main.h"


GameObject::GameObject()
{
	bmp = NULL; //NULL is default for non-initialized pointers (means false or 0)
	x_location = 0;
	y_location = 0;
	x_speed = 0;
	y_speed = 0;
}



GameObject::~GameObject()
{
	al_destroy_bitmap(bmp);
}

void GameObject::SetBitmap(ALLEGRO_BITMAP* b)
{
	//make sure the bitmap is valid
	if (b != NULL)
		bmp = b;
}

void GameObject::Draw()
{
	if (bmp != NULL) //make sure we have a bitmap to draw
		al_draw_bitmap(bmp, x_location, y_location, 0);
}

void GameObject::Move()
{
	x_location += x_speed;
	y_location += y_speed;
}