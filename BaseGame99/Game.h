#pragma once
class Game
{
public:
	ALLEGRO_KEYBOARD_STATE key_state; //ALLEGRO_KEYBOARD_STATE is a "user define type" in Allegro
	ALLEGRO_MOUSE_STATE mouse_state;


	Player player;


	ALLEGRO_BITMAP* bg;
	ALLEGRO_BITMAP* player_bitmap;

	float gravity;
	float air_time;

	//animatedObject player;

	bool end;

	Game();
	~Game();

	void Run();
	void Update();
	void Draw();


	

};

