#pragma once
class Spring : public PowerUp
{
public:
	int x;
	int y;
	ALLEGRO_BITMAP* spring;
	int num_springs;
	Spring* springs;
	int clicked;

	Spring();
	~Spring();

	void AddSpring(int x1, int y1);
	void Draw();
	void Wait();
};

