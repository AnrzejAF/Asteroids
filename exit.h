#pragma once
#include "SFML/Graphics.hpp"


class Exit
{
public:
	Exit(float width, float height);
	void draw(sf::RenderWindow& window);


private:

	sf::Font font;
	sf::Text exit;

};

