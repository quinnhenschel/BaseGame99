#include "Main.h"


AnimatedObject::AnimatedObject()
{
	run_cycle = 1;
	increment = 0;
	bmp = al_load_bitmap("standing.png");
	state = frame = 0;
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

		is_shooting = false;
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

void AnimatedObject::GetDimensions()
{
	curr_height = al_get_bitmap_height(bmp);
	curr_width = al_get_bitmap_width(bmp);
}
