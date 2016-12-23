#include "Main.h"


Render::Render()
{
	x_scroll = 0;
	brush[0] = al_load_bitmap("black.png");
	brush[1] = al_load_bitmap("green.png");
	brush[2] = al_load_bitmap("purple.png");
	brush[3] = al_load_bitmap("red.png");
}


Render::~Render()
{
}

void Render::Begin(ALLEGRO_BITMAP* bg)
{
	al_draw_bitmap(bg, 0 - x_scroll, 0, 0);
}

void Render::ManaBar(ALLEGRO_BITMAP* bg, AnimatedObject* p)
{
	al_draw_filled_rectangle(1170, 20, 1270, 25, al_map_rgb(50, 50, 50));
	al_draw_filled_rectangle(1170, 20, 1170 + p->mana, 25, al_map_rgb(0, 0, 255));
}

void Render::Draw(GameObject* p)
{
	al_draw_bitmap(p->bmp, p->x_location - x_scroll, p->y_location, 0);
}

void Render::DrawBrush(AnimatedObject* p, int x, int y)
{
	ALLEGRO_BITMAP* curr_brush = NULL;
	if (p->powers[p->curr_power] == 1)
		curr_brush = brush[0];
	if (p->powers[p->curr_power] == 2)
		curr_brush = brush[1];
	if (p->powers[p->curr_power] == 3)
		curr_brush = brush[2];
	if (p->powers[p->curr_power] == 4)
		curr_brush = brush[3];
	al_draw_bitmap(curr_brush, x, y, 0);
}

void Render::DrawPowerUps(Spring* s, Teleporter* t, Float* f)
{
	for (int i = 0; i < s->num_springs; i++)
		al_draw_bitmap(s->springs[i]->bmp, s->springs[i]->x - x_scroll, s->springs[i]->y, 0);
	for (int i = 0; i < 2; i++)
		al_draw_bitmap(t->connection[i]->bmp, t->connection[i]->x - x_scroll, t->connection[i]->y, 0);
	al_draw_bitmap(f->bmp, f->x - x_scroll, f->y, 0);
}

void Render::End()
{
	al_flip_display();
}
