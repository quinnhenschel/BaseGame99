#pragma once
class Spring : public PowerUp
{
public:
	int x;
	int y;
	ALLEGRO_BITMAP* bmp;
	int num_springs;
	Spring* springs[100];

	Spring();
	~Spring();

	void AddSpring(int x1, int y1);
	void Draw(int scrollx, int scrolly);
};

