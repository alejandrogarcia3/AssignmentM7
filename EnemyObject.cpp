
#include "Main.h"


EnemyObject::EnemyObject()
{
	position.x = position.y = speed.x = speed.y = 0;
	shape = NULL;
	direction = 0;

}

EnemyObject::~EnemyObject()
{

}

void EnemyObject::Draw()
{
	if (shape != NULL)
		al_draw_bitmap(shape, position.x, position.y, 0);

}

void EnemyObject::RandomDirection()
{
	direction = rand() % 4;
		if (direction == 0)
		{
			speed.x = 1;
			speed.y = 0;
		}

	if (direction == 1)
	{
		speed.x = -1;
		speed.y = 0;
	}

	if (direction == 2) //up
	{
		speed.x = 0;
		speed.y = -1;
	}
	if (direction == 3) //down
	{
		speed.x = 0;
		speed.y = 1;
	}

}

void EnemyObject::Move()
{
	position.x += speed.x;
	position.y += speed.y;
}