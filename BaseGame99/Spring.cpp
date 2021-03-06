#include "Main.h"


Spring::Spring()
{
	is_unlocked = true;
	brush_colour = al_map_rgb(0, 255, 0);
	bmp = al_load_bitmap("spring.png");
	num_springs = x = y = type = 0;
	bmpw = al_get_bitmap_width(bmp);
	bmph = al_get_bitmap_height(bmp);
}


Spring::~Spring()
{
}

//void Spring::AddSpring(int x1, int y1)
//{
//	cout << "executed!\n";
//	Spring* temp = (Spring*)malloc(num_springs * sizeof(int));
//	for (int i = 0; i < num_springs; i++)
//		temp[i] = springs[i];
//	//free(springs);
//	cout << "executed2!\n";
//	num_springs++;
//	
//	springs = (Spring*)malloc(num_springs * sizeof(int));
//	for (int i = 0; i < num_springs; i++)
//		springs[i] = temp[i];
//	//free(temp);
//	springs[num_springs - 1].x = x1;
//	springs[num_springs - 1].y = y1;
//}

void Spring::AddSpring(int x1, int y1)
{
	springs[num_springs] = new Spring();
	springs[num_springs]->x = x1;
	springs[num_springs]->y = y1;
	num_springs++;
}
