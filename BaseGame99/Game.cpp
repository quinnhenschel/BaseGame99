#include "Main.h"


Game::Game()
{
	tutorial = al_load_bitmap("tutorial_map.bmp");
	tutw = al_get_bitmap_width(tutorial);
	tuth = al_get_bitmap_height(tutorial);
	level1 = al_load_bitmap("level1.bmp");
	lvlw= al_get_bitmap_width(level1);
	lvlh = al_get_bitmap_height(level1);
		
	//bg = NULL;

	end = false;

	x_scroll = y_scroll = 0;

	brush[0] = al_load_bitmap("black.png");
	al_convert_mask_to_alpha(brush[0], al_map_rgb(255, 255, 255));
	brush[1] = al_load_bitmap("green.png");
	brush[2] = al_load_bitmap("purple.png");
	brush[3] = al_load_bitmap("red.png");

	//player_bitmap = al_load_bitmap("player.bmp");
	//player.SetBitmap(player_bitmap);

	air_time = 0;
	/*player_attack_air_time = 0;*/

	/*player_attack_bitmap = al_load_bitmap("player_attack.bmp");
	player_attack.bmp = player_attack_bitmap;*/


	count = 0;

	teleporter.Initialize();

	clicked = 0;
	player.GivePower(1);
	player.GivePower(2);
	player.GivePower(3);
	player.GivePower(4);
}


Game::~Game()
{
	al_destroy_bitmap(bg);
}

void Game::Run(int level)
{
	while (!end)
	{
		Update(level);
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
	if (clicked > 50)
		clicked = 0;
}

void Game::DrawBrush(AnimatedObject* p, int x, int y)
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

void Game::Update(int level)
{

	if (level == 1)
	{
		bg = tutorial;
		bgw = tutw;
		bgh = tuth;
	}
		
	if (level == 2)
	{
		bg = level1;
		bgw = lvlw;
		bgh = lvlh;
	}
		

	player.x_speed = player.y_speed = player.state = 0;
	//player.is_shooting = false;

	gravity = air_time * air_time;
	/*player_attack_gravity = player_attack_air_time * player_attack_air_time;*/
	
	al_get_keyboard_state(&key_state);
	al_get_mouse_state(&mouse_state);

	player.GetDimensions();

	if (floater.is_float)
	{
		floater.x_speed = 0;
		floater.y_speed = -3;
	}

	if (al_key_down(&key_state, ALLEGRO_KEY_ESCAPE))
		end = true;

	if (al_key_down(&key_state, ALLEGRO_KEY_D))
	{
		player.state = 1;
			if (!physics.Collision(bg, player.x_location + player.width + 3, player.y_location, 0, 0, 0) && !physics.Collision(bg, player.x_location + player.width + 3, player.y_location + player.height - 5, 0, 0, 0))
			{
				if (x_scroll < bgw - 1280 && player.x_location - x_scroll > 1280 / 2)
					x_scroll += 3;
				player.x_speed = 3;
				if (floater.is_float)
					floater.x_speed = 3;
			}
	}	

	if (al_key_down(&key_state, ALLEGRO_KEY_A))
	{
		player.state = 2;
			if (!physics.Collision(bg, player.x_location - 3, player.y_location, 0, 0, 0) && !physics.Collision(bg, player.x_location - 3, player.y_location + player.height - 5, 0, 0, 0))
			{
				if (x_scroll > 0 && player.x_location - x_scroll < 1280 / 2)
					x_scroll -= 3;
				player.x_speed = -3;
				if (floater.is_float)
					floater.x_speed = -3;
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
		cout << "falling!\n";
		player.y_speed = gravity;
		air_time += .1;
	}

	for (int i = 0; i < spring.num_springs; i++)
	{
		if (physics.OnPowerup(&player, spring.springs[i]) && player.y_speed > 5)
			player.y_speed = -200;
	}

	for (int i = 0; i < 2; i++)
	{
		if (physics.OnPowerup(&player, teleporter.connection[i]))
		{
			if (teleporter.zap_wait == 0)
			{
				if (teleporter.connection[i]->id % 2 == 0)
				{
					player.x_location = teleporter.connection[0]->x;
					player.y_location = teleporter.connection[0]->y;
				}
				else{
					player.x_location = teleporter.connection[1]->x;
					player.y_location = teleporter.connection[1]->y;
				}
				teleporter.TelWait();
			}
		}
	}

	if (teleporter.zap_wait > 0)
		teleporter.TelWait();

	if (physics.OnPowerup(&player, &floater))
	{
		if (floater.float_time == 0)
		{
			floater.x_speed = 0;
			floater.y_speed = -3;
			floater.is_float = true;
		}
	}

	if (floater.is_float)
	{
		player.state = 3;
		player.y_speed = floater.y_speed;
		player.x_speed = floater.x_speed;
		floater.x = player.x_location - 40;
		floater.y = player.y_location - 20;
		floater.AddTime(&player);
	}

	floater.x += floater.x_speed;
	floater.y += floater.y_speed;

	if (al_key_down(&key_state, ALLEGRO_KEY_SPACE))
	{
		if (floater.is_float == false)
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
			basic.DrawLine(bg, mouse_state.x - 5 + x_scroll, mouse_state.y - 5 + y_scroll, brush[0]);
		if (player.GetPower() == 2)
		{
			if (clicked == 0)
			{
				spring.AddSpring(mouse_state.x - 10 + x_scroll, mouse_state.y - 10 + y_scroll);
				Wait();
			}
		}
		if (player.GetPower() == 3)
		{
			if (clicked == 0)
			{
				if (!physics.Collision(bg, mouse_state.x, mouse_state.y, 0, 0, 0))
				{
					teleporter.connection[teleporter.curr_tel]->x = mouse_state.x - 20 + x_scroll;
					teleporter.connection[teleporter.curr_tel]->y = mouse_state.y - 50 + y_scroll;
					teleporter.Next();
					Wait();
				}
			}
		}
		if (player.GetPower() == 4)
		{
			if (clicked == 0)
			{
				floater.x = mouse_state.x - (floater.bmpw / 2) + x_scroll;
				floater.y = mouse_state.y - (floater.bmph / 2) + y_scroll;
				Wait();
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

	if (player.y_location < 0)
		player.y_location = 0;
	/*player_attack.Move();*/
}

void Game::Draw()
{
	al_draw_bitmap(bg, 0 - x_scroll, 0 - y_scroll, 0);
	DrawBrush(&player, mouse_state.x - 5, mouse_state.y - 5);
	al_draw_bitmap(floater.bmp, floater.x - x_scroll, floater.y - y_scroll, 0);
	spring.Draw(x_scroll, y_scroll);
	teleporter.Draw(x_scroll, y_scroll);
	al_draw_bitmap(player.bmp, player.x_location - x_scroll, player.y_location - y_scroll, 0);
	

	/*if (player.is_shooting == true)
	{
		al_draw_bitmap(player_attack_bitmap, player_attack.x_location, player_attack.y_location, 0);
	}*/

	al_flip_display();
}
