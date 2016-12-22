#pragma once
class Game
{
public:
	ALLEGRO_KEYBOARD_STATE key_state; //ALLEGRO_KEYBOARD_STATE is a "user define type" in Allegro
	ALLEGRO_MOUSE_STATE mouse_state;

	Physics physics;

	PowerUp basic;
	Spring spring;

	AnimatedObject player;
	PlayerAttack player_attack;


	ALLEGRO_BITMAP* bg;
	ALLEGRO_BITMAP* tutorial;
	ALLEGRO_BITMAP* level1;
	ALLEGRO_BITMAP* brush;
	ALLEGRO_BITMAP* player_bitmap;
	ALLEGRO_BITMAP* player_attack_bitmap;

	int x_scroll;
	int y_scroll;

	int bgw;
	int bgh;

	float gravity;
	float air_time;

	float player_attack_gravity;
	float player_attack_air_time;

	float angle;

	int count;
	
	int clicked;
	
	//animatedObject player;

	bool end;

	Game();
	~Game();

	void Run(int level);
	bool Check_Collision(int direction);
	bool Attack_LeftorRight();
	void Wait();
	void Update(int level);
	void Draw();


	

};

