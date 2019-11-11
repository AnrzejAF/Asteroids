#pragma once
#include <SFML/Graphics.hpp>
#define PI 3.14159265358979323846
#include <cmath>

using namespace sf;

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
	ConvexShape shape;

	//int getPosX();
	//int getPosY();
	//int getScale();
	//int getVelX();
	//int getVelY();
	//int getRad();
	//int getHP();
public:
	Statek(int resX, int resY, float scale, int HP, float velMax);
	ConvexShape* getShape();
	void rotate(float deg);
	void move(float dt);
	void accelerate(float acceleration, float dt);
	void WallCollision(int resX, int resY);
};

