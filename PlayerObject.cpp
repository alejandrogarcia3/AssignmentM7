#include "Main.h"

//Constructor

PlayerObject::PlayerObject()
{
	position.x = position.y = speed.x = speed.y = 0;
	shape = NULL;
}
PlayerObject::~PlayerObject()
{
	//release anything dynamically created by this object
}
void PlayerObject::Draw()
{
	if (shape != NULL) 
		al_draw_bitmap(shape, position.x, position.y, 0);
}

void PlayerObject::Move()
{
	position.x += speed.x;
	position.y += speed.y;
}