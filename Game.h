#pragma once

class Game
{
public:
	//variables
	ALLEGRO_KEYBOARD_STATE key_state;
	ALLEGRO_MOUSE_STATE mouse_state;
	Physics physics;

	PlayerObject player;
	ALLEGRO_BITMAP* pbmp;

	EnemyObject enemy[NUM_ENEMIES];
	ALLEGRO_BITMAP* ebmp;

	ALLEGRO_BITMAP* bg;

	bool end;

	Game();
	~Game();
	void Run();
	void Update();
	void Draw();

};