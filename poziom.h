#pragma once
#include "SFML/Graphics.hpp"


#define MAX_NUMBER_OF_ITEMS 3

class Poziom
{
public:
	Poziom(float width, float height);



	void draw(sf::RenderWindow& window);
	void MoveLeft();
	void MoveRight();
	int GetPressedItem() { return selectedItemIndex; }
	

private:
	int selectedItemIndex;
	sf::Font font;
	sf::Text poziom[MAX_NUMBER_OF_ITEMS];

};
