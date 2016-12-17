#include "Main.h"


Game::Game()
{
	bg = al_load_bitmap("testing_map.bmp");
	end = false;

	player_bitmap = al_load_bitmap("player.bmp");
	player.SetBitmap(player_bitmap);

	air_time = 0;
	player_attack_air_time = 0;

	player_attack_bitmap = al_load_bitmap("player_attack.bmp");
	player_attack.bmp = player_attack_bitmap;


	count = 0;

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
	player.is_shooting = false;

	gravity = air_time * air_time;
	player_attack_gravity = player_attack_air_time * player_attack_air_time;

	//if ((player.y_location + player.height) <= 600)
	//{
	//	player.y_speed = 1;
	//}
	
	al_get_keyboard_state(&key_state);
	al_get_mouse_state(&mouse_state);

	if (al_key_down(&key_state, ALLEGRO_KEY_ESCAPE))
		end = true;


	if (al_key_down(&key_state, ALLEGRO_KEY_D))
	{
		/*ALLEGRO_COLOR read_background = al_get_pixel(bg, player.x_location + player.x_speed, player.y_location);
		unsigned char r, g, b;
		al_unmap_rgb(read_background, &r, &g, &b);

		if (r == 255 && b == 255 && g == 255)*/
			player.x_speed = 3;

	}
		

	if (al_key_down(&key_state, ALLEGRO_KEY_A))
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


	if (al_key_down(&key_state, ALLEGRO_KEY_W))
	{
		
	}


	if (al_key_down(&key_state, ALLEGRO_KEY_SPACE))
	{
		player.y_location = player.y_location - 10;
	}

	al_get_mouse_state(&mouse_state);


	/////////////////// ROTATION STUFF
	//float d = (player.x_location - mouse_state.x)*(player.x_location - mouse_state.x) + (player.y_location - mouse_state.y)*(player.y_location - mouse_state.y);
	//d = sqrt(d);

	//float adj_over_hyp = (mouse_state.y - player.y_location) / d;

	//float angle = acos(adj_over_hyp);

	//cout << angle;
	//cout << "\n";
	////////////

	
	
	if (mouse_state.buttons & 1) {
		/* Primary (e.g. left) mouse button is held. */
		player.is_shooting = true;
		if (mouse_state.x > player.x_location)
			player_attack.x_speed = 10;
		else
			player_attack.x_speed = -10;

		if (count > 50)
		{
			player_attack.x_speed = -10;
		}
		if (player_attack.x_location < player.x_location)
		{
			count = 0;
		}
		//player_attack.y_speed = player_attack_gravity;
		player_attack_air_time = player_attack_air_time + .05;

		count++;

		cout << mouse_state.x;
		cout << "\n";
	}
	else
	{
		player.is_shooting = false;
		player_attack.x_location = player.x_location;
		player_attack.y_location = player.y_location;
		player_attack_air_time = 0;
	}





	player.Move();
	player_attack.Move();
}

void Game::Draw()
{
	al_draw_bitmap(bg, 0, 0, 0);
	al_draw_bitmap(player_bitmap, player.x_location, player.y_location, 0);

	if (player.is_shooting == true)
	{
		al_draw_bitmap(player_attack_bitmap, player_attack.x_location, player_attack.y_location, 0);
	}

	al_flip_display();
}
