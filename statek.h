#pragma once
#include <SFML/Graphics.hpp>
#define PI 3.14159265358979323846
#include <cmath>

using namespace sf;
#define RESX 800 
#define RESY 600


class Statek
{
private:


	float posX;
	float posY;
	float scale;
	float sizeX;
	float sizeY;
	float velMax;
	float vel;
	float velX;
	float velY;
	float deg;
	int HP;

public:
	ConvexShape shape;
	ConvexShape shapeMirrorTop;
	ConvexShape shapeMirrorDown;
	ConvexShape shapeMirrorLeft;
	ConvexShape shapeMirrorRight;
	Statek(int resX, int resY, float scale, int HP, float velMax);
	void rotate(float deg);
	void move(float dt);
	void accelerate(float acceleration, float dt);
	void WallCollision(float resX, float resY);
};

