#pragma once
#include "SFML/Graphics.hpp"


class Help
{
public:
	Help(float width, float height);
	void draw(sf::RenderWindow& window);
	

private:

	sf::Font font;
	sf::Text help;

};

