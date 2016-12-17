#include "Main.h"

ALLEGRO_DISPLAY* display = NULL;
ALLEGRO_FONT* font;

//initialzie Allegro components
void InitAllegro(int W, int H)
{
	//initialize allegro
	if (!al_init())
	{
		printf("failed to initialize allegro!\n");
	}


	ALLEGRO_DISPLAY       *display = NULL;
	ALLEGRO_DISPLAY_MODE   disp_data;

	al_init(); // I'm not checking the return value for simplicity.
	al_init_image_addon();
	al_init_primitives_addon();

	al_get_display_mode(0, &disp_data);

	al_set_new_display_flags(ALLEGRO_FULLSCREEN);
	display = al_create_display(disp_data.width, disp_data.height);

	al_rest(3);
	al_destroy_display(display);




	//initialize display screen
	display = al_create_display(W, H);
	if (!display)
	{
		printf("failed to create display!\n");
		exit(0);
	}
	else
	{
		al_resize_display(display, disp_data.width, disp_data.height);
		printf("ok");
		al_clear_to_color(al_map_rgb(0, 0, 0));

	}

	{
		printf("ok");
		al_clear_to_color(al_map_rgb(0, 0, 0));
	}

	//initialize keyboard
	if (!al_install_keyboard())
	{
		printf("failed to install keyboard!\n");
		exit(0);
	}

	//initialize image addon
	if (!al_init_image_addon())
	{
		printf("failed to initialize image addon!\n");
		exit(0);
	}

	//initialize mouse
	if (!al_install_mouse())
	{
		printf("failed to install mouse!\n");
		exit(0);
	}
	//initialize primitive shapes
	if (!al_init_primitives_addon())
	{
		printf("failed to initialize primitives!\n");
		exit(0);
	}
	//initialize font
	al_init_font_addon(); // initialize the font addon
	al_init_ttf_addon();// initialize the ttf (True Type Font) addon	 (get fonts here: http://www.1001freefonts.com/)
	//font = al_load_ttf_font("uchiyama.ttf", 12, 0); //secodn variable is size
	//font = al_load_font("a4_font.tga", 0, 0); //size variable doesn't matter becasue the font is fixed-size 
	/*if (!font)
	{
		printf("failed to create font!\n");
		exit(0);
	}*/
}

//End and clean up Allegro components
void EndAllegro()
{
	al_destroy_display(display);
}

void main()
{
	int sw = 1280;
	int sh = 720;
	InitAllegro(sw, sh);

	Game game;

	game.Run();

	EndAllegro();
}

