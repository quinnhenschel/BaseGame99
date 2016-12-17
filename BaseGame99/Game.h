#pragma once
class Game
{
public:
	ALLEGRO_KEYBOARD_STATE key_state; //ALLEGRO_KEYBOARD_STATE is a "user define type" in Allegro
	ALLEGRO_MOUSE_STATE mouse_state;


	Player player;
	PlayerAttack player_attack;


	ALLEGRO_BITMAP* bg;
	ALLEGRO_BITMAP* player_bitmap;
	ALLEGRO_BITMAP* player_attack_bitmap;

	float gravity;
	float air_time;

	float player_attack_gravity;
	float player_attack_air_time;

	float angle;

	int count;

	//animatedObject player;

	bool end;

	Game();
	~Game();

	void Run();
	void Update();
	void Draw();


	

};

