#pragma once
#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

struct Vector2D //a 2D value corresponding to X and Y dimensions (position, size, direction, etc)
{
	int x;
	int y;
};


//class for game object
class PlayerObject
{
public:
	//position (x and y)
	Vector2D position;
	//speed (x and y)
	Vector2D speed;
	//Image (object image)
	ALLEGRO_BITMAP* shape; //a pointer to a bitmap

	PlayerObject();
	~PlayerObject();
	void Draw();
	void Move();
	
};

#endif 