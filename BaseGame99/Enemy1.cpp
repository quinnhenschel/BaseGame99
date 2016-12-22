#include "Main.h"


Enemy1::Enemy1()
{
	x_speed = 0;
	y_speed = 0;
	bmp = al_load_bitmap("enemy1.png");
}


Enemy1::~Enemy1()
{
}
