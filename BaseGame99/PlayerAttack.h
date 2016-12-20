#pragma once
#include "GameObject.h"
class PlayerAttack :
	public GameObject
{
public:

	int state;


	PlayerAttack();
	~PlayerAttack();

	bool PlayerAttack::Throw_Boomerang(int attack_x_speed, int attack_y_speed, int attack_x_location, int attack_y_location, int player_x_location, int player_y_location);
};

