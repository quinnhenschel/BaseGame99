#pragma once
class AnimatedObject : public GameObject
{
public:
	int state;
	int run_cycle;
	int frame;
	int increment;
	int height;
	int width;

	int powers[4];
	int num_powers;
	int curr_power;

	ALLEGRO_BITMAP* animation_right[11];
	ALLEGRO_BITMAP* animation_left[11];

	AnimatedObject();
	~AnimatedObject();

	void Animate(AnimatedObject* p);
	void GetDimensions();
	void GivePower(int power);
	void SetPower();
	int GetPower();
};

