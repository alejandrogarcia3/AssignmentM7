#pragma once
#define NUM_ENEMIES 10
class EnemyObject
{
public:

	Vector2D position;
	Vector2D speed;
	ALLEGRO_BITMAP* shape;

	int direction;
	void RandomDirection();

	EnemyObject();
	~EnemyObject();

	void Draw();
	void Move();

};