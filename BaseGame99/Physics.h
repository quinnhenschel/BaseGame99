#pragma once
class Physics
{
public:
	Physics();
	~Physics();
	
	bool Collision(ALLEGRO_BITMAP* bg, int x, int y, int rval, int gval, int bval);
	void GroundCheck(AnimatedObject* p, ALLEGRO_BITMAP* bg);
	bool OnPowerup(AnimatedObject* p, PowerUp* s);
};

