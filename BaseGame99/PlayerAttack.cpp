#include "Main.h"


PlayerAttack::PlayerAttack()
{
	state = 3;


	run_cycle = 1;
	increment = 0;
	bmp = al_load_bitmap("standing.png");
	animation_state = frame = 0;
	/*for (int i = 1; i < 13; i++)
	{
	string run = "run";
	string png = ".png";
	string curr_frame;
	stringstream sstm;
	sstm << run << i << png;
	curr_frame = sstm.str();
	animation_right[i - 1] = al_load_bitmap(curr_frame.c_str());

	}

	for (int i = 1; i < 13; i++)
	{
	string run_left = "run_left";
	string png = ".png";
	string curr_frame2;
	stringstream sstm2;
	sstm2 << run_left << i << png;
	curr_frame2 = sstm2.str();
	animation_left[i - 1] = al_load_bitmap(curr_frame2.c_str());
	cout << curr_frame2.c_str() << "\n";
	}*/

	animation_right[0] = al_load_bitmap("player_attack.png");
	animation_left[0] = al_load_bitmap("player_attack.png");
	animation_right[1] = al_load_bitmap("player_attack1.png");
	animation_left[1] = al_load_bitmap("player_attack2.png");
	animation_right[2] = al_load_bitmap("player_attack3.png");
	animation_left[2] = al_load_bitmap("player_attack4.png");
	animation_right[3] = al_load_bitmap("player_attack5.png");
	animation_left[3] = al_load_bitmap("player_attack6.png");
	animation_right[4] = al_load_bitmap("player_attack7.png");
	animation_left[4] = al_load_bitmap("player_attack8.png.png");
	animation_right[5] = al_load_bitmap("player_attack9.png");
	animation_left[5] = al_load_bitmap("player_attacK10.png");
	animation_right[6] = al_load_bitmap("player_attack11.png");
	animation_left[6] = al_load_bitmap("player_attack12.png");
	animation_right[7] = al_load_bitmap("player_attack13.png");
	animation_left[7] = al_load_bitmap("player_attack14.png");
	animation_right[8] = al_load_bitmap("player_attack15.png");
	animation_left[8] = al_load_bitmap("player_attack16.png");
	animation_right[9] = al_load_bitmap("player_attack17.png");
	animation_left[9] = al_load_bitmap("player_attack18.png");
	animation_right[10] = al_load_bitmap("player_attack19.png");
	animation_left[10] = al_load_bitmap("player_attack20.png");
	animation_right[11] = al_load_bitmap("player_attack21.png");
	animation_left[11] = al_load_bitmap("player_attack22.png");
}


PlayerAttack::~PlayerAttack()
{
}

void PlayerAttack::Animate(PlayerAttack* p)
{
	if (state == 0)
	{
		p->SetBitmap(al_load_bitmap("standing.png"));
		frame = 0;
		run_cycle = increment = 1;
	}
	if (state == 1 || state == 2)
	{
		if (increment % 5 == 0)
		{
			if (state == 1)
				p->SetBitmap(animation_right[frame]);
			if (state == 2)
				p->SetBitmap(animation_left[frame]);
			frame++;
			cout << frame << "\n";
		}
		increment++;
		if (run_cycle % 2 != 0)
		{
			if (frame == 11)
			{
				frame = 6;
				run_cycle++;
			}
		}
		if (run_cycle % 2 == 0)
		{
			if (frame == 9)
			{
				frame = 3;
				run_cycle++;
			}
		}
	}
}

