#include "Main.h"


Teleporter::Teleporter()
{
	is_unlocked = true;
	curr_tel = 0;
	zap_wait = 0;
}


Teleporter::~Teleporter()
{
}

void Teleporter::Initialize()
{
	for (int i = 0; i < 2; i++)
	{
		connection[i] = new Teleporter();
		connection[i]->x = connection[i]->y = -100;
		connection[i]->id = i + 1;
		connection[i]->bmp = al_load_bitmap("portal.png");
		connection[i]->bmpw = al_get_bitmap_width(connection[i]->bmp);
		connection[i]->bmph = al_get_bitmap_height(connection[i]->bmp);
	}
}

void Teleporter::Draw(int scrollx, int scrolly)
{
	for (int i = 0; i < 2; i++)
	{
		al_draw_bitmap(connection[i]->bmp, connection[i]->x - scrollx, connection[i]->y - scrolly, 0);
	}
}

void Teleporter::Next()
{
	curr_tel++;
	if (curr_tel > 1)
		curr_tel = 0;
}

void Teleporter::TelWait()
{
	zap_wait++;
	if (zap_wait == 100)
		zap_wait = 0;
}
