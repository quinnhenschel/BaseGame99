#include "Main.h"


Player::Player()
{
	bmp = al_load_bitmap("testing_map.bmp");
}


Player::~Player()
{
	al_destroy_bitmap(bmp);
}
