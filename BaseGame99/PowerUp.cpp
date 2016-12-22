#include "Main.h"


PowerUp::PowerUp()
{
	is_unlocked = true;
	brush_colour = al_map_rgb(0, 0, 0);
}


PowerUp::~PowerUp()
{
}

void PowerUp::DrawLine(ALLEGRO_BITMAP* bg, float x, float y, ALLEGRO_BITMAP* brush)
{
	if (is_unlocked)
	{
		al_lock_bitmap(bg, al_get_bitmap_format(bg), ALLEGRO_LOCK_READWRITE);
		ALLEGRO_BITMAP* target = al_get_target_bitmap();
		al_set_target_bitmap(bg);

		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				ALLEGRO_COLOR c_curr = al_get_pixel(brush, i, j);
				unsigned char r_curr, g_curr, b_curr;
				al_unmap_rgb(c_curr, &r_curr, &g_curr, &b_curr);
				if (r_curr == 255 && g_curr == 0 && b_curr == 0)
					al_put_pixel(x + i, y + j, brush_colour);
			}
		}

		al_set_target_bitmap(target);
		al_unlock_bitmap(bg);
	}
}
