#include "Main.h"


Spring::Spring()
{
	is_unlocked = true;
	brush_colour = al_map_rgb(0, 255, 0);
	spring = al_load_bitmap("spring.png");
	num_springs = x = y = clicked = 0;
	springs = (Spring*)malloc(num_springs * sizeof(int));
}


Spring::~Spring()
{
}

void Spring::AddSpring(int x1, int y1)
{
	Spring* temp = (Spring*)malloc(num_springs * sizeof(int));
	for (int i = 0; i < num_springs; i++)
		temp[i] = springs[i];
	//free(springs);
	cout << "2\n";
	num_springs++;
	
	springs = (Spring*)malloc(num_springs * sizeof(int));
	for (int i = 0; i < num_springs; i++)
		springs[i] = temp[i];
	//free(temp);
	springs[num_springs - 1].x = x1;
	springs[num_springs - 1].y = y1;
}

void Spring::Draw()
{
	for (int i = 0; i < num_springs; i++)
	{
		al_draw_bitmap(al_load_bitmap("portal.png"), springs[i].x, springs[i].y, 0);
	}
}

void Spring::Wait()
{
	clicked++;
	if (clicked > 20)
		clicked = 0;
	cout << clicked << "\n";
}
