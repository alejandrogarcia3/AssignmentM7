
#include "Main.h"


	Game::Game()
	{
		srand(time(NULL));

		bg = al_load_bitmap("bg.bmp");
		player.shape = pbmp = al_load_bitmap("player.bmp");
		player.position.x = 100;
		player.position.y = 250;
		

		ebmp = al_load_bitmap("enemy.bmp");
		for (int i = 0; i < NUM_ENEMIES; i++)
		{
			enemy[i].shape = ebmp;
			enemy[i].position.x = 200 + rand() % 300;
			enemy[i].position.y = 300 + rand() % 100;
		}

		end = false;
		physics.collisionMethod = CollisionMethod::InsideRect;
	}

	Game::~Game()
	{
		//release/destroy anything we have allocated/created in this class
		al_destroy_bitmap(bg);
		al_destroy_bitmap(pbmp);
		al_destroy_bitmap(ebmp);
	}
	void Game::Run()
	{
		//main loop
		while (!end)
		{
			Update();
			Draw();
			al_rest(0.01);
		}

	}
	void Game::Update()
	{
		//read user input and update all variables

		al_get_keyboard_state(&key_state);

		//end program
		if (al_key_down(&key_state, ALLEGRO_KEY_ESCAPE)) //al_key_down checks the status of a key in the key_state structure
		{
			end = true;
		}
		//change player speed using arrow keys
		player.speed.x = player.speed.y = 0;
		if (al_key_down(&key_state, ALLEGRO_KEY_RIGHT))
		{
			player.speed.x = 10;
		}
		if (al_key_down(&key_state, ALLEGRO_KEY_LEFT))
		{
			player.speed.x = -10;
		}
		if (al_key_down(&key_state, ALLEGRO_KEY_UP))
		{
			player.speed.y = -10;
		}
		if (al_key_down(&key_state, ALLEGRO_KEY_DOWN))
		{
			player.speed.y = 10;
		}



		player.Move();
		for (int i = 0; i < NUM_ENEMIES; i++)
		{
			enemy[i].RandomDirection();
			physics.Move(&enemy[i]);
			//check collision
			if (physics.Collision(&enemy[i], &player))
				//end = true; //end game
			enemy[i].position.x = 1000;

		}

	}
	void Game::Draw()
	{
		//all drawing will be here

		//start by erasing frame
		//al_clear_to_color(al_map_rgb(0, 0, 0));
		al_draw_bitmap(bg, 0, 0, 0);

		//draw objects and other content (menus, etc)
		player.Draw();
	
		for (int i = 0; i < NUM_ENEMIES; i++)
			enemy[i].Draw();
		//put on primary buffer
		al_flip_display();
	}
