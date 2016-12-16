#include "Main.h"


Game::Game()
{
	bg = al_load_bitmap("testing_map.bmp");
	end = false;

}


Game::~Game()
{
	al_destroy_bitmap(bg);
}

void Game::Run()
{
	while (!end)
	{
		Update();
		Draw();
		al_rest(0.1);
	}
}

void Game::Update()
{
	al_get_keyboard_state(&key_state);

	if (al_key_down(&key_state, ALLEGRO_KEY_ESCAPE))
		end = true;
}

void Game::Draw()
{
	al_draw_bitmap(bg, 0, 0, 0);

	al_flip_display();
}
