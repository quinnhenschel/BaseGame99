#pragma once
#include "GameObject.h"
class Player :
	public GameObject
{
public:

	int height;
	int width;

	Player();
	~Player();
};

