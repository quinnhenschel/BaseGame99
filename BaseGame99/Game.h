#pragma once
class Game
{
public:
	ALLEGRO_KEYBOARD_STATE key_state; //ALLEGRO_KEYBOARD_STATE is a "user define type" in Allegro
	ALLEGRO_MOUSE_STATE mouse_state;

	Physics physics;

	ALLEGRO_BITMAP* bg;
	GameObject player;

	bool end;

	Game();
	~Game();

	void Run();
	void Update();
	void Draw();
};

