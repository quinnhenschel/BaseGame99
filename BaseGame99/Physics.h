#pragma once
class Physics
{
public:
	Physics();
	~Physics();
	
	bool Collision(ALLEGRO_BITMAP* bg, int x, int y);
};

