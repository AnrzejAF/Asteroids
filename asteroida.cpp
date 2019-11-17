#include "asteroida.h"

Asteroida::Asteroida(int resX, int resY, float scalep, int HP, float vel)
{
	posX = resX / 4;
	posY = resY / 4;
	this->scale = scalep * (1 + (rand()%3));
	this->HP = HP;
	vel = 0;
	velX = 0;
	velY = 0;
	deg = 0;


	shape.setPointCount(8);
	shape.setPoint(0, Vector2f(scale * 0, scale * (2 + random())));
	shape.setPoint(1, Vector2f(scale * (2 + random()), scale * (2 + random())));
	shape.setPoint(2, Vector2f(scale * (3 + random()), scale * 0));
	shape.setPoint(3, Vector2f(scale * (2 + random()), scale * (-2 + random())));
	shape.setPoint(4, Vector2f(scale * 0, scale * (-3 + random())));
	shape.setPoint(5, Vector2f(scale * (-2 + random()), scale * (-2 + random())));
	shape.setPoint(6, Vector2f(scale * (-3 + random()), scale * 0));
	shape.setPoint(7, Vector2f(scale * (-2 + random()), scale * (2 + random())));

	shape.setPosition(posX, posY);

}

	ConvexShape* Asteroida::getShape() { return &shape; }

	void Asteroida::rotate(float deg, float dt)
	{
		shape.rotate(deg * dt);
	}

	float Asteroida::random()
	{
		if(rand()%2)
			return 0.1 * (rand() % 6);
		else
			return -0.1 * (rand() % 6);
	}
	;