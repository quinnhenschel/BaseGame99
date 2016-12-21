#include "Main.h"


AnimatedObject::AnimatedObject()
{
	bmp = al_load_bitmap("standing.png");
	state = frame = increment = num_powers = curr_power = 0;
	run_cycle = 1;

	for (int i = 0; i < 4; i++)
	{
		powers[i] = 0;
	}

	/*for (int i = 1; i < 13; i++)
	{
		string run = "run";
		string png = ".png";
		string curr_frame;
		stringstream sstm;
		sstm << run << i << png;
		curr_frame = sstm.str();
		animation_right[i - 1] = al_load_bitmap(curr_frame.c_str());
	}*/

	animation_right[0] = al_load_bitmap("run1.png");
	animation_left[0] = al_load_bitmap("run_left1.png");
	animation_right[1] = al_load_bitmap("run2.png");
	animation_left[1] = al_load_bitmap("run_left2.png");
	animation_right[2] = al_load_bitmap("run3.png");
	animation_left[2] = al_load_bitmap("run_left3.png");
	animation_right[3] = al_load_bitmap("run4.png");
	animation_left[3] = al_load_bitmap("run_left4.png");
	animation_right[4] = al_load_bitmap("run5.png");
	animation_left[4] = al_load_bitmap("run_left5.png");
	animation_right[5] = al_load_bitmap("run6.png");
	animation_left[5] = al_load_bitmap("run_left6.png");
	animation_right[6] = al_load_bitmap("run7.png");
	animation_left[6] = al_load_bitmap("run_left7.png");
	animation_right[7] = al_load_bitmap("run8.png");
	animation_left[7] = al_load_bitmap("run_left8.png");
	animation_right[8] = al_load_bitmap("run9.png");
	animation_left[8] = al_load_bitmap("run_left9.png");
	animation_right[9] = al_load_bitmap("run10.png");
	animation_left[9] = al_load_bitmap("run_left10.png");
	animation_right[10] = al_load_bitmap("run11.png");
	animation_left[10] = al_load_bitmap("run_left11.png");
	animation_right[11] = al_load_bitmap("run12.png");
	animation_left[11] = al_load_bitmap("run_left12.png");
}


AnimatedObject::~AnimatedObject()
{
}

void AnimatedObject::Animate(AnimatedObject* p)
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

void AnimatedObject::GetDimensions()
{
	height = al_get_bitmap_height(bmp);
	width = al_get_bitmap_width(bmp);
}

void AnimatedObject::GivePower(int power)
{
	powers[num_powers] = power;
	num_powers++;
}

void AnimatedObject::SetPower()
{
	if (num_powers > 0)
	{
		curr_power++;
		if (curr_power == 4)
			curr_power = 0;
		for (int i = 0; i < num_powers; i++)
		{
			if (powers[curr_power] == 0)
				curr_power++;
		}
	}
	
}

int AnimatedObject::GetPower()
{
	if (num_powers > 0)
	{
		return powers[curr_power];
	}
}
