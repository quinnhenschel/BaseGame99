#include "Main.h"


Player::Player()
{
	bmp = al_load_bitmap("player.bmp");
	height = al_get_bitmap_height(bmp);
	width = al_get_bitmap_width(bmp);
	
}


Player::~Player()
{
	al_destroy_bitmap(bmp);
}
