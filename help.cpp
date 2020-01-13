#include "help.h"

using namespace sf;


Help::Help(float width, float height)
{
	font.loadFromFile("arial.ttf");


	help.setFont(font);
	help.setFillColor(sf::Color::White);
	help.setString(L"            Asteroidki \nporuszaj siê strza³kami\n           kitraj g³azy\n naciœnij ESC by wyjœæ  ");
	help.setOrigin(help.getLocalBounds().width / 2, help.getLocalBounds().height / 2);
	help.setPosition(sf::Vector2f(width / 2, height / 2));
}
void Help::draw(sf::RenderWindow& window)
{

	window.draw(help);
}

