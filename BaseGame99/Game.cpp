#include "Main.h"


Game::Game()
{
	bg = al_load_bitmap("testing_map.bmp");
	end = false;

	player_bitmap = al_load_bitmap("player.bmp");
	player.SetBitmap(player_bitmap);

	air_time = 0;

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
		al_rest(0.003);
	}
}

void Game::Update()
{
	player.x_speed = 0;
	player.y_speed = 0;

	gravity = air_time * air_time;

	//if ((player.y_location + player.height) <= 600)
	//{
	//	player.y_speed = 1;
	//}
	
	al_get_keyboard_state(&key_state);

	if (al_key_down(&key_state, ALLEGRO_KEY_ESCAPE))
		end = true;

	if (al_key_down(&key_state, ALLEGRO_KEY_RIGHT))
	{
		/*ALLEGRO_COLOR read_background = al_get_pixel(bg, player.x_location + player.x_speed, player.y_location);
		unsigned char r, g, b;
		al_unmap_rgb(read_background, &r, &g, &b);

		if (r == 255 && b == 255 && g == 255)*/
			player.x_speed = 3;

	}
		

	if (al_key_down(&key_state, ALLEGRO_KEY_LEFT))
	{
		/*ALLEGRO_COLOR read_background = al_get_pixel(bg, player.x_location - player.x_speed, player.y_location);
		unsigned char r, g, b;
		al_unmap_rgb(read_background, &r, &g, &b);

		if (r == 255 && b == 255 && g == 255)*/
			player.x_speed = -3;
	}

	ALLEGRO_COLOR read_background = al_get_pixel(bg, player.x_location, player.y_location + player.y_speed + player.height);
	unsigned char r1, g1, b1;
	al_unmap_rgb(read_background, &r1, &g1, &b1);

	if (r1 == 0 && b1 == 0 && g1 == 0)
	{
		player.y_speed = 0;
		air_time = 0;
	}
	else
	{
		player.y_speed = gravity;
		air_time = air_time + .1;
	}

	if (al_key_down(&key_state, ALLEGRO_KEY_UP))
	{
		player.y_speed = -1;
		air_time = 0;
	}

	if (al_key_down(&key_state, ALLEGRO_KEY_SPACE))
	{
		player.y_location = player.y_location - 10;
	}


	


	

		
		

	cout << gravity;
	cout << "\n";
	cout << air_time;
	cout << "\n";
	cout << "\n";



	player.Move();
}

void Game::Draw()
{
	al_draw_bitmap(bg, 0, 0, 0);
	al_draw_bitmap(player_bitmap, player.x_location, player.y_location, 0);
	al_flip_display();
}
