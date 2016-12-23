#pragma once
class Render
{
public:
	int x_scroll;
	ALLEGRO_BITMAP* brush[4];

	Render();
	~Render();

	void Begin(ALLEGRO_BITMAP* bg);
	void ManaBar(AnimatedObject* p);
	void Draw(GameObject* p);
	void DrawBrush(AnimatedObject* p, int x, int y);
	void DrawPowerUps(Spring* s, Teleporter* t, Float* f);
	void End();
};

