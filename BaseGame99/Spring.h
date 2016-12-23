#pragma once
class Spring : public PowerUp
{
public:
	int num_springs;
	Spring* springs[100];

	Spring();
	~Spring();

	void AddSpring(int x1, int y1);
};

