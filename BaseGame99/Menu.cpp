#include "Main.h"


Menu::Menu()
{
	menu = al_load_bitmap("menu.png");
	menu_tutorial = al_load_bitmap("menu_tutorial.png");
	menu_play = al_load_bitmap("menu_play.png");
	menu_exit = al_load_bitmap("menu_exit.png");

	level = 0;
	button = 0;
	end = false;
}


Menu::~Menu()
{
}

int Menu::Run()
{
	
	while (!end)
	{
		
		level = Update();
		if (level == 0)
			Draw();

		al_rest(0.003);
		
	}
	cout << level;
	return level;

}

int Menu::Update()
{
	al_get_keyboard_state(&key_state);
	al_get_mouse_state(&mouse_state);

	int result = 0;

	if (al_key_down(&key_state, ALLEGRO_KEY_ESCAPE))
	{
		end = true;
		result = 1;
	}
	//else 
	//	select = 0;

	bool none = true;

	if (mouse_state.x > 100 && 400 > mouse_state.x && mouse_state.y > 165 && 265 > mouse_state.y)
	{
		none = false;
		button = 1;
		if (mouse_state.buttons & 1)
		{
			result = 1;
			end = true;
		}
			

	}
	if (mouse_state.x > 100 && 400 > mouse_state.x && mouse_state.y > 290 && 390 > mouse_state.y)
	{
		none = false;
		button = 2;
		if (mouse_state.buttons & 1)
		{
			result = 2;
			end = true;
		}
	}
	if (mouse_state.x > 100 && 400 > mouse_state.x && mouse_state.y > 423 && 523 > mouse_state.y)
	{
		none = false;
		button = 3;
		if (mouse_state.buttons & 1)
			end = true;
	}
	if (none == true)
	{
		button = 0;
	}
	return result;
}

void Menu::Draw()
{

	bool none = true;

	if (button == 1)
		al_draw_bitmap(menu_tutorial, 0, 0, 0);
	if (button == 2)
		al_draw_bitmap(menu_play, 0, 0, 0);
	if (button == 3)
		al_draw_bitmap(menu_exit, 0, 0, 0);
	if (button == 0)
		al_draw_bitmap(menu, 0, 0, 0);
	

	al_flip_display();
}
