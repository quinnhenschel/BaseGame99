#pragma once
class Menu
{
public:

	ALLEGRO_KEYBOARD_STATE key_state;
	ALLEGRO_MOUSE_STATE mouse_state;

	ALLEGRO_BITMAP* menu;
	ALLEGRO_BITMAP* menu_tutorial;
	ALLEGRO_BITMAP* menu_play;
	ALLEGRO_BITMAP* menu_exit;

	int button;
	bool end;
	int level;

	Menu();
	~Menu();

	int Run();
	int Update();
	void Draw();
};

