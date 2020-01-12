#pragma once
#include "SFML/Graphics.hpp"
#include "statek.h"
#include "asteroida.h"

#define MAX_NUMBER_OF_ITEMS 5

class Menu
{
public:
	Menu(float width, float height);
	
	

	void draw(sf::RenderWindow& window);
	void MoveUp();
	void MoveDown();
	int GetPressedItem() { return selectedItemIndex; }
	void NewGame(int* points, float* dt, float* next_asteroid, Statek* statek, Asteroida** asteroids);

private:
	int selectedItemIndex;
	sf::Font font;
	sf::Text menu[MAX_NUMBER_OF_ITEMS];

};
