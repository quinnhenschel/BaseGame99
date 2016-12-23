#include "Main.h"


Game::Game()
{
	tutorial = al_load_bitmap("tutorial_map.bmp");
	tutw = al_get_bitmap_width(tutorial);
	tuth = al_get_bitmap_height(tutorial);
	level1 = al_load_bitmap("level1.bmp");
	lvlw = al_get_bitmap_width(level1);
	lvlh = al_get_bitmap_height(level1);

	heart = al_load_bitmap("heart.png");

	//bg = NULL;

	end = false;

	//player_bitmap = al_load_bitmap("player.bmp");
	//player.SetBitmap(player_bitmap);

	air_time = 0;
	/*player_attack_air_time = 0;*/

	/*player_attack_bitmap = al_load_bitmap("player_attack.bmp");
	player_attack.bmp = player_attack_bitmap;*/

	for (int i = 0; i < 3; i++)
	{
		pots[i] = new GameObject();
		abilities[i] = new GameObject();
		pots[i]->bmp = al_load_bitmap("mana.png");
	}
	pots[0]->x_location = 1850;
	pots[0]->y_location = 380;
	pots[1]->x_location = 1000;
	pots[1]->y_location = 530;
	pots[2]->x_location = 1200;
	pots[2]->y_location = 568;

	abilities[0]->bmp = al_load_bitmap("umbrella_chest.png");
	abilities[0]->x_location = 700;
	abilities[0]->y_location = 472;
	abilities[1]->bmp = al_load_bitmap("teleport_chest.png");
	abilities[1]->x_location = 1850;
	abilities[1]->y_location = 578;
	abilities[2]->bmp = al_load_bitmap("spring_chest.png");
	abilities[2]->x_location = 1500;
	abilities[2]->y_location = 380;

	count = 0;

	teleporter.Initialize();

	clicked = 0;
	player.GivePower(1);

	line_count = 0;
	string curr_line;
	read.open("save.txt");
	while (getline(read,curr_line))
	{
		if (line_count == 0)
			player.lives = stoi(curr_line);
		if (line_count == 1)
			player.x_location = stoi(curr_line);
		if (line_count == 0)
			player.y_location = stoi(curr_line);
		line_count++;
	}
	read.close();
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
		Draw(level);
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

void Game::Save()
{
	file.open("save.txt");
	file << player.lives << "\n";
	file << player.x_location << "\n";
	file << player.y_location << "\n";
	file.close();
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
	{
		end = true;
	}

	if (al_key_down(&key_state, ALLEGRO_KEY_D))
	{
		player.state = 1;
			if (!physics.Collision(bg, player.x_location + player.width + 3, player.y_location, 0, 0, 0) && !physics.Collision(bg, player.x_location + player.width + 3, player.y_location + player.height - 5, 0, 0, 0))
			{
				if (render.x_scroll < bgw - 1280 && player.x_location - render.x_scroll > 1280 / 2)
					render.x_scroll += 3;
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
				if (render.x_scroll > 0 && player.x_location - render.x_scroll < 1280 / 2)
					render.x_scroll -= 3;
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
		player.y_speed = gravity;
		air_time += .1;
	}

	if (physics.Collision(bg, player.x_location + player.width, player.y_location + player.height, 255, 0, 0) || physics.Collision(bg, player.x_location, player.y_location + player.height, 255, 0, 0))
	{
		player.Die();
		render.x_scroll = 0;
	}

	for (int i = 0; i < spring.num_springs; i++)
	{
		if (physics.OnPowerup(&player, spring.springs[i]) && player.y_speed > 5)
			player.y_speed = -300;
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

	for (int i = 0; i < 3; i++)
	{
		if (physics.OnObject(&player, pots[i]))
		{
			pots[i]->x_location = pots[i]->y_location = -100;
			player.mana += 50;
			if (player.mana > 100)
				player.mana = 100;
		}
	}

	if (physics.OnObject(&player, abilities[0]))
	{
		player.GivePower(4);
		abilities[0]->x_location = abilities[0]->y_location = -100;
	}
	if (physics.OnObject(&player, abilities[1]))
	{
		player.GivePower(3);
		abilities[1]->x_location = abilities[1]->y_location = -100;
	}
	if (physics.OnObject(&player, abilities[2]))
	{
		player.GivePower(2);
		abilities[2]->x_location = abilities[2]->y_location = -100;
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

	if (mouse_state.buttons & 2 && player.mana > 0)
	{
		if (player.GetPower() == 1)
		{
			basic.DrawLine(bg, mouse_state.x - 5 + render.x_scroll, mouse_state.y - 5, render.brush[0]);
			player.mana -= 1;
		}
		
		if (player.GetPower() == 2)
		{
			if (clicked == 0 && player.mana > 40)
			{
				player.mana -= 40;
				spring.AddSpring(mouse_state.x - 10 + render.x_scroll, mouse_state.y - 10);
				Wait();
			}
		}
		if (player.GetPower() == 3)
		{
			if (clicked == 0 && player.mana > 20)
			{
				if (!physics.Collision(bg, mouse_state.x, mouse_state.y, 0, 0, 0))
				{
					player.mana -= 20;
					teleporter.connection[teleporter.curr_tel]->x = mouse_state.x - 20 + render.x_scroll;
					teleporter.connection[teleporter.curr_tel]->y = mouse_state.y - 50;
					teleporter.Next();
					Wait();
				}
			}
		}
		if (player.GetPower() == 4)
		{
			if (clicked == 0 && player.mana > 75)
			{
				player.mana -= 75;
				floater.x = mouse_state.x - (floater.bmpw / 2) + render.x_scroll;
				floater.y = mouse_state.y - (floater.bmph / 2);
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

	if (end == true)
		Save();
}

void Game::Draw(int level)
{
	render.Begin(bg);
	render.ManaBar(bg, &player);

	render.DrawBrush(&player, mouse_state.x - 5, mouse_state.y - 5);
	render.DrawPowerUps(&spring, &teleporter, &floater);

	render.Draw(&player);
	
	if (level == 2)
	{
		for (int i = 0; i < 3; i++)
		{
			render.Draw(pots[i]);
			render.Draw(abilities[i]);
		}
	}

	for (int i = 0; i < player.lives; i++)
		al_draw_bitmap(heart, 0 + (i * 50), 0, 0);
	

	/*if (player.is_shooting == true)
	{
		al_draw_bitmap(player_attack_bitmap, player_attack.x_location, player_attack.y_location, 0);
	}*/

	render.End();
}
