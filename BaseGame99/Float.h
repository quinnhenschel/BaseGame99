#pragma once
class Float : public PowerUp
{
public:
	bool is_float;
	int float_time;
	int x_speed;
	int y_speed;

	Float();
	~Float();
	void AddTime(AnimatedObject* p);
};

