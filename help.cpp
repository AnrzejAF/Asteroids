#include "help.h"

using namespace sf;


Help::Help(float width, float height)
{
	font.loadFromFile("arial.ttf");


	help.setFont(font);
	help.setFillColor(sf::Color::Red);
	help.setString("no wes");
	help.setPosition(sf::Vector2f(width / 2, height / 2));
}
void Help::draw(sf::RenderWindow& window)
{

	window.draw(help);
}

