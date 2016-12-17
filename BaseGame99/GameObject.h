#pragma once
class GameObject
{
public:
	GameObject();
	~GameObject();

	float x_location;
	float y_location;
	float x_speed;
	float y_speed;

	ALLEGRO_BITMAP* bmp;

	void SetBitmap(ALLEGRO_BITMAP* b);

	void Draw();
	void Move();
};

