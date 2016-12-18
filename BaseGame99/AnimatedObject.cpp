#include "Main.h"


AnimatedObject::AnimatedObject()
{
	run_cycle = 1;
	increment = 0;
	bmp = al_load_bitmap("standing.png");
	state = frame = 0;
	for (int i = 1; i < 12; i++)
	{
		string run = "run";
		string run_left = "run_left";
		string png = ".png";
		string curr_frame;
		stringstream sstm;
		stringstream sstm2;
		sstm << run << i << png;
		curr_frame = sstm.str();
		animation_right[i - 1] = al_load_bitmap(curr_frame.c_str());
		sstm2 << run_left << i << png;
		curr_frame = sstm2.str();
		animation_left[i - 1] = al_load_bitmap(curr_frame.c_str());
	}
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
	}
	if (state == 1 || state == 2)
	{
		if (increment % 4 == 0)
		{
			if (state == 1)
				p->SetBitmap(animation_right[frame]);
			if (state == 2)
				p->SetBitmap(animation_left[frame]);
			frame++;
		}
		increment++;
		if (run_cycle % 2 == 0)
		{
			if (frame == 9)
			{
				increment = 0;
				frame = 3;
				run_cycle++;
			}
		}
		if (run_cycle % 2 != 0)
		{
			if (frame == 10)
			{
				increment = 0;
				frame = 6;
				run_cycle++;
			}
		}
	}
}

void AnimatedObject::GetDimensions()
{
	curr_height = al_get_bitmap_height(bmp);
	curr_width = al_get_bitmap_width(bmp);
}
