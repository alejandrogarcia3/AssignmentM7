#pragma once
enum CollisionMethod
{
	TopRight,
	Centre,
	InsideRect
};

class Physics
{
public:
	CollisionMethod collisionMethod;

	Physics();
	~Physics();

	bool Collision(EnemyObject* o1, PlayerObject* o2);
	bool Collision1(EnemyObject* o1, PlayerObject* o2);
	bool Collision2(EnemyObject* o1, PlayerObject* o2);
	bool Collision3(EnemyObject* o1, PlayerObject* o2);

	void Move(PlayerObject* obj);
	void Move(EnemyObject* obj);
};

