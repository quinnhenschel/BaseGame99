#include "Main.h"


Game::Game()
{
	bg = al_load_bitmap("testing_map.bmp");
	end = false;

	//player_bitmap = al_load_bitmap("player.bmp");
	//player.SetBitmap(player_bitmap);

	air_time = 0;
	/*player_attack_air_time = 0;*/

	/*player_attack_bitmap = al_load_bitmap("player_attack.bmp");
	player_attack.bmp = player_attack_bitmap;*/


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


bool Game::Attack_LeftorRight()
{
	if (mouse_state.x > player.x_location)
		return true;
	else
		return false;
}

void Game::Update()
{
	player.x_speed = player.y_speed = player.state = 0;
	//player.is_shooting = false;

	/*gravity = air_time * air_time;*/
	/*player_attack_gravity = player_attack_air_time * player_attack_air_time;*/
	
	al_get_keyboard_state(&key_state);
	al_get_mouse_state(&mouse_state);

	player.GetDimensions();

	if (al_key_down(&key_state, ALLEGRO_KEY_ESCAPE))
		end = true;

	if (al_key_down(&key_state, ALLEGRO_KEY_D))
	{
		player.state = 1;
		if (!physics.Collision(bg, player.x_location + player.curr_width + 3, player.y_location) && !physics.Collision(bg, player.x_location + player.curr_width + 3, player.y_location + player.curr_height - 5))
			player.x_speed = 3;
	}	

	if (al_key_down(&key_state, ALLEGRO_KEY_A))
	{
		player.state = 2;
		if (!physics.Collision(bg, player.x_location - 3, player.y_location) && !physics.Collision(bg, player.x_location - 3, player.y_location + player.curr_height - 5))
			player.x_speed = -3;
	}

	if (physics.Collision(bg, player.x_location + player.curr_width, player.y_location + player.curr_height) || physics.Collision(bg, player.x_location, player.y_location + player.curr_height))
	{
		player.y_speed = 0;
	}

	if (!physics.Collision(bg, player.x_location + player.curr_width, player.y_location + player.curr_height) && !physics.Collision(bg, player.x_location, player.y_location + player.curr_height))
	{
		player.y_speed = 3;
	}

	
	/*if (!physics.Collision(bg, player.x_location, player.y_location + player.curr_height))
	{
		player.y_speed = gravity;
		air_time += .1;
	}*/

	if (al_key_down(&key_state, ALLEGRO_KEY_SPACE))
	{
		// the 10 controls jump height will make variable later
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
		//player.is_shooting = true;
		if (Attack_LeftorRight() == true)
			player_attack.x_speed = 10;
		else
			player_attack.x_speed = -10;

		//needs to be replaced with timer stuff
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
	/*else
	{
		player.is_shooting = false;
		player_attack.x_location = player.x_location;
		player_attack.y_location = player.y_location;
		player_attack_air_time = 0;
	}*/


	player.Move();
	player.Animate(&player);
	/*player_attack.Move();*/
}

void Game::Draw()
{
	al_draw_bitmap(bg, 0, 0, 0);
	
	al_draw_bitmap(player.bmp, player.x_location, player.y_location, 0);
	

	/*if (player.is_shooting == true)
	{
		al_draw_bitmap(player_attack_bitmap, player_attack.x_location, player_attack.y_location, 0);
	}*/

	al_flip_display();
}
