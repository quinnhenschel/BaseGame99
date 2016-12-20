#pragma once
#include "GameObject.h"
class PlayerAttack :
	public GameObject
{
public:

	int state;

	int animation_state;
	int run_cycle;
	int frame;
	int increment;

	ALLEGRO_BITMAP* animation_right[11];
	ALLEGRO_BITMAP* animation_left[11];

	PlayerAttack();
	~PlayerAttack();

	bool Throw_Boomerang(int attack_x_speed, int attack_y_speed, int attack_x_location, int attack_y_location, int player_x_location, int player_y_location);

	void Animate(PlayerAttack* p);
};

