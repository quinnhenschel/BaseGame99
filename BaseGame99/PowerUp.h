#pragma once
class PowerUp
{
public:
	bool is_unlocked;
	ALLEGRO_COLOR brush_colour;

	PowerUp();
	~PowerUp();

	void DrawLine(ALLEGRO_BITMAP* bg, float x, float y, ALLEGRO_BITMAP* brush);
};

