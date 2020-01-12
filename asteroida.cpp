#include "asteroida.h"

using namespace std;

Asteroida::Asteroida(float scalep, int HP, float vel, Statek* statek, Asteroida *asteroids[], int *points)
{
	posX = rand() % RESX;
	posY = rand() % RESY;
	this->scale = scalep * (1 + (rand()%3));
	this->HP = HP;
	vel = 0;
	velX = (rand() % 51) - 25;
	velY = (rand() % 51) - 25;
	deg = 0;
	radius = 3.05 * scalep + statek->radius;
	this->statek = statek;
	this->asteroids = asteroids;
	this->points = points;

	shape.setPointCount(8);
	shape.setPoint(0, Vector2f(scale * 0, scale * (3 + random())));
	shape.setPoint(1, Vector2f(scale * (2 + random()), scale * (2 + random())));
	shape.setPoint(2, Vector2f(scale * (3 + random()), scale * 0));
	shape.setPoint(3, Vector2f(scale * (2 + random()), scale * (-2 + random())));
	shape.setPoint(4, Vector2f(scale * 0, scale * (-3 + random())));
	shape.setPoint(5, Vector2f(scale * (-2 + random()), scale * (-2 + random())));
	shape.setPoint(6, Vector2f(scale * (-3 + random()), scale * 0));
	shape.setPoint(7, Vector2f(scale * (-2 + random()), scale * (2 + random())));

	shape.setPosition( posX, posY);

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


	void Asteroida::move(float dt)
	{
		posX += velX * dt;
		posY += velY * dt;
		shape.setPosition(  posX, posY);
	}

	void Asteroida::collision()
	{
		if (sqrt(pow((posX - statek->posX), 2) + pow((posY - statek->posY), 2)) <= radius)
		{
			*points += 1;
			destroy();
			return;
		}

		if (posY > RESY || posY < 0 || posX > RESX || posX < 0)
			destroy();
			
	}

	void Asteroida::destroy()
	{
		for (int i = 0; i < MAX_N; i++)
		{
			if (asteroids[i] == this)
			{
				asteroids[i] = NULL;
				break;
			}
		}
		this->~Asteroida();
	}
