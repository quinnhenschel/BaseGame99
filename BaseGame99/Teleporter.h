#pragma once
class Teleporter : public PowerUp
{
public:
	Teleporter* connection[2];
	int curr_tel;
	int id;
	int zap_wait;

	Teleporter();
	~Teleporter();

	void Initialize();
	void Draw(int scrollx, int scrolly);
	void Next();
	void TelWait();
};

