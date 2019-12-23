#pragma once
#include "options.h"
#include <SFML/Graphics.hpp>
#include <ctime>
#include "statek.h"


using namespace sf;
using namespace std;

class Asteroida
{
private:
	float posX;
	float posY;
	float scale;
	float sizeX;
	float sizeY;
	float vel;
	float velX;
	float velY;
	float deg;
	float HP;
	float radius;
	ConvexShape shape;
	Statek* statek;
	Asteroida** asteroids;
	int* points;

public:
	Asteroida(float scale, int HP, float vel, Statek *statek, Asteroida *asteroids[], int *points);
	ConvexShape* getShape();
	void rotate(float deg, float dt);
	float random();
	void move(float dt);
	void collision();
	void destroy();
};

