#include "Main.h"
//Title: Assignment M3
//Author : Alejandro Garcia
//Objective : Game that involves moving a player with the arrow keys and detects if it has collided with one of the 10 enemies.
/*Object Description
PlayerObject class with x,y,shape, draw and move functions and collision detection
EnemyObject class with x,y, shape, speex, speedy, type an dmove function
Game class with background image, enemies, run, update, and draw functions.
*/




//global variable for display
ALLEGRO_DISPLAY* g_display = NULL;
								   //initialize Allegro components
void InitAllegro(int screenWidth, int screenHeight)
{

	//initialize allegro
	if (!al_init())
	{
		printf("failed to initialize allegro!\n");
	}

	//initialize display screen
	g_display = al_create_display(screenWidth, screenHeight);
	if (!g_display)
	{
		printf("failed to create display!\n");
		exit(0);
	}
	else
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

	//initialize primitives
	if (!al_init_primitives_addon())
	{
		printf("failed to initialize primitives!\n");
		exit(0);
	}

	if (!al_init_image_addon())
	{
		printf("failed to initialize image addon\n");
		exit(0);
	}
	//initialize mouse
	if (!al_install_mouse())
	{
		printf("failed to install mouse!\n");
		exit(0);
	}

}

//End and clean up Allegro components
void EndAllegro()
{
	al_destroy_display(g_display);
}


	

void main()
{
	// INITIALIZE
	int sw = 640;
	int sh = 480;
	InitAllegro(sw, sh);

	Game game;


	game.Run();
	EndAllegro();
}