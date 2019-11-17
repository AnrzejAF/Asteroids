#pragma once
#include <SFML/Graphics.hpp>
#include <ctime>

using namespace sf;

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
	ConvexShape shape;

public:
	Asteroida(int resX, int resY, float scale, int HP, float vel);
	ConvexShape* getShape();
	void rotate(float deg, float dt);
	float random();
};

