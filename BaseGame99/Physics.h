#pragma once
class Physics
{
public:
	Physics();
	~Physics();
	
	bool Collision(ALLEGRO_BITMAP* bg, int x, int y);
	float Distance(int x1, int y1, int x2, int y2);
};

