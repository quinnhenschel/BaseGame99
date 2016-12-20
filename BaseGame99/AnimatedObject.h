#pragma once
class AnimatedObject : public GameObject
{
public:
	int state;
	int run_cycle;
	int frame;
	int increment;
	int curr_height;
	int curr_width;
	ALLEGRO_BITMAP* animation_right[11];
	ALLEGRO_BITMAP* animation_left[11];

	AnimatedObject();
	~AnimatedObject();

	void Animate(AnimatedObject* p);
	void GetDimensions();
};

