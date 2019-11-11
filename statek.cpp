#include "statek.h"

using namespace sf;

Statek::Statek(int resX, int resY, float scale, int HP, float velMax)
{
	posX = resX / 2;
	posY = resY / 2;
	this->scale = scale;
	this->HP = HP;
	this->velMax = velMax;
	vel = 0;
	velX = 0;
	velY = 0;
	deg = 180;

	shape.setPointCount(4);
	shape.setPoint(0, Vector2f(scale * -3.f, scale * -4.f));
	shape.setPoint(1, Vector2f(0.f, scale * 4.f));
	shape.setPoint(2, Vector2f(scale * 3.f, scale * -4.f));
	shape.setPoint(3, Vector2f(0.f, scale * -2.f));
	sizeX = 6 * scale;
	sizeY = 8 * scale;

	shape.setRotation(180);
	shape.setPosition(posX, posY);
}

ConvexShape* Statek::getShape() { return &shape; }

void Statek::rotate(float deg)
{
	shape.rotate(deg);
	this->deg = shape.getRotation();
}

void Statek::move(float dt)
{
	posX += velX*dt;
	posY += velY*dt;
	shape.setPosition(posX, posY);
}

void Statek::accelerate(float acceleration, float dt)
{
	float newVel = vel + acceleration * dt;
	if (newVel < velMax)
	{
		velX = velX - sin(PI / 180 * deg);
		velY = velY + cos(PI / 180 * deg);
	}
}

void Statek::WallCollision(int resX, int resY)
{
	posX = resX / 2;
	posY = resY / 2;

		if (posX <= 0)
		{
			velX = -velX;
		}
		if (posX >= resX)
		{
			velX = velX;
		}
		if (posY <= 0)
		{
			velY = -velY;
		}
		if (posY >= resY)
		{
			velY = -velY;
		}
};

