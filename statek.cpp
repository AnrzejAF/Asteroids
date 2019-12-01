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
	radius = 4 * scale;

	shape.setPointCount(4);
	shape.setPoint(0, Vector2f(scale * -3.f, scale * -2.66f));
	shape.setPoint(1, Vector2f(0.f, scale * 4.f));
	shape.setPoint(2, Vector2f(scale * 3.f, scale * -2.66f));
	shape.setPoint(3, Vector2f(0.f, scale * -1.5f));
	sizeX = 6 * scale;
	sizeY = 8 * scale;

	shape.setRotation(180);
	shape.setPosition(posX, posY);
	shapeMirrorTop = shape;
	shapeMirrorDown = shape;
	shapeMirrorLeft = shape;
	shapeMirrorRight = shape;
	shapeMirrorTop.setRotation(180);
	shapeMirrorDown.setRotation(180);
	shapeMirrorLeft.setRotation(180);
	shapeMirrorRight.setRotation(180);

}

void Statek::rotate(float deg)
{
	shape.rotate(deg);
	shapeMirrorTop.rotate(deg);
	shapeMirrorDown.rotate(deg);
	shapeMirrorLeft.rotate(deg);
	shapeMirrorRight.rotate(deg);
	this->deg = shape.getRotation();
}

void Statek::move(float dt)
{
	posX += velX * dt;
	posY += velY * dt;

	shape.setPosition(posX, posY);
	shapeMirrorTop.setPosition(posX, posY - RESY);
	shapeMirrorDown.setPosition(posX, posY + RESY);
	shapeMirrorLeft.setPosition(posX - RESX, posY);
	shapeMirrorRight.setPosition(posX + RESX, posY);
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

void Statek::WallCollision(float resX, float resY)
{
	if (posX < 0.0f)  posX = resX;
	else if (posX >= resX)	posX = 0;

	if (posY < 0.0f)	posY = resY;
	else if (posY >= resY)	posY = 0;
}

