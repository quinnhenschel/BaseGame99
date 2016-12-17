#pragma once
class Physics
{
public:
	Physics();
	~Physics();
	
	bool Collision(GameObject* p, int x, int y);
};

