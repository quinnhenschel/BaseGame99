#include "Main.h"


Game::Game()
{
	bg = al_load_bitmap("level1.bmp");
	bgw = al_get_bitmap_width(bg);
	bgh = al_get_bitmap_height(bg);
	end = false;

	x_scroll = y_scroll = 0;

	brush = al_load_bitmap("brush.png");

	//player_bitmap = al_load_bitmap("player.bmp");
	//player.SetBitmap(player_bitmap);

	air_time = 0;
	/*player_attack_air_time = 0;*/

	/*player_attack_bitmap = al_load_bitmap("player_attack.bmp");
	player_attack.bmp = player_attack_bitmap;*/


	count = 0;

	clicked = 0;
	player.GivePower(1);
	player.GivePower(2);
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

void Game::Wait()
{
	clicked++;
	if (clicked > 20)
		clicked = 0;
}

void Game::Update()
{
	player.x_speed = player.y_speed = player.state = 0;
	//player.is_shooting = false;

	gravity = air_time * air_time;
	/*player_attack_gravity = player_attack_air_time * player_attack_air_time;*/
	
	al_get_keyboard_state(&key_state);
	al_get_mouse_state(&mouse_state);

	player.GetDimensions();

	if (al_key_down(&key_state, ALLEGRO_KEY_ESCAPE))
		end = true;

	if (al_key_down(&key_state, ALLEGRO_KEY_D))
	{
		player.state = 1;
			if (!physics.Collision(bg, player.x_location + player.width + 3, player.y_location, 0, 0, 0) && !physics.Collision(bg, player.x_location + player.width + 3, player.y_location + player.height - 5, 0, 0, 0))
			{
				if (x_scroll < bgw - 1280 && player.x_location > 1280 / 2)
					x_scroll += 3;
				player.x_speed = 3;
			}
	}	

	if (al_key_down(&key_state, ALLEGRO_KEY_A))
	{
		player.state = 2;
			if (!physics.Collision(bg, player.x_location - 3, player.y_location, 0, 0, 0) && !physics.Collision(bg, player.x_location - 3, player.y_location + player.height - 5, 0, 0, 0))
			{
				if (x_scroll > 0 && player.x_location < 1280 / 2)
					x_scroll -= 3;
				player.x_speed = -3;
			}
	}

	if (physics.Collision(bg, player.x_location + player.width, player.y_location + player.height, 0, 0, 0) || physics.Collision(bg, player.x_location, player.y_location + player.height, 0, 0, 0))
	{
		gravity = 0;
		air_time = 0;
		physics.GroundCheck(&player, bg);
	}	

	if (!physics.Collision(bg, player.x_location + player.width, player.y_location + player.height, 0, 0, 0) && !physics.Collision(bg, player.x_location, player.y_location + player.height, 0, 0, 0))
	{
		player.y_speed = gravity;
		air_time += .1;
	}

	for (int i = 0; i < spring.num_springs; i++)
	{
		if (physics.OnPowerup(&player, spring.springs[i]))
			cout << "yes!\n";
	}

	if (al_key_down(&key_state, ALLEGRO_KEY_SPACE))
	{
		player.y_location = player.y_location - JUMP_HEIGHT;
	}

	if (al_key_down(&key_state, ALLEGRO_KEY_ENTER))
	{
		if (clicked == 0)
		{
			player.SetPower();
			Wait();
			cout << player.curr_power << "\n";
		}
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

		cout << mouse_state.x << ", " << mouse_state.y << "\n";
	}

	if (mouse_state.buttons & 2)
	{
		if (player.GetPower() == 1)
			basic.DrawLine(bg, mouse_state.x - 5 + x_scroll, mouse_state.y - 5 + y_scroll, brush);
		if (player.GetPower() == 2)
		{
			if (clicked == 0)
			{
				if (physics.Collision(bg, mouse_state.x, mouse_state.y + 20, 0, 0, 0) && !physics.Collision(bg, mouse_state.x, mouse_state.y, 0, 0, 0))
				{
					spring.AddSpring(mouse_state.x - 10, mouse_state.y - 10);
					Wait();
				}
			}
		}
	}

	if (clicked > 0)
		Wait();
	
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
	al_draw_bitmap(bg, 0 - x_scroll, 0 - y_scroll, 0);
	al_draw_bitmap(brush, mouse_state.x - 5, mouse_state.y - 5, 0);
	spring.Draw(x_scroll, y_scroll);
	al_draw_bitmap(player.bmp, player.x_location - x_scroll, player.y_location - y_scroll, 0);
	

	/*if (player.is_shooting == true)
	{
		al_draw_bitmap(player_attack_bitmap, player_attack.x_location, player_attack.y_location, 0);
	}*/

	al_flip_display();
}
