#pragma once
class GameObject
{
public:
	GameObject();
	~GameObject();

	int x_location;
	int y_location;
	int x_speed;
	int y_speed;
	int height;
	int width;

	ALLEGRO_BITMAP* bmp;

	void SetBitmap(ALLEGRO_BITMAP* b);

	void Draw();
	void Move();
	void GetDimensions();
};

