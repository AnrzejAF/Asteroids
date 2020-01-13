#pragma once
#include "options.h"
#include <SFML/Graphics.hpp>
#include <cmath>

using namespace sf;
using namespace std;



class Statek
{
private:
	float scale;
	float sizeX;
	float sizeY;
	float velMax;
	float vel;
	int HP;

public:	
	float velX;
	float velY;
	float deg;
	float posX;
	float posY;
	float radius;
	ConvexShape shape;
	ConvexShape shapeMirrorTop;
	ConvexShape shapeMirrorDown;
	ConvexShape shapeMirrorLeft;
	ConvexShape shapeMirrorRight;
	Statek(int resX, int resY, float scale, int HP, float velMax, float posX, float posY);
	void rotate(float deg);
	void move(float dt);
	void accelerate(float acceleration, float dt);
	void WallCollision(float resX, float resY);
};

