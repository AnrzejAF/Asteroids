#include "exit.h"

Exit::Exit(float width, float height)
{
	font.loadFromFile("arial.ttf");


	exit.setFont(font);
	exit.setFillColor(sf::Color::White);
	exit.setString(L"           CHCESZ WYJŒÆ? \n PotwierdŸ wciskaj¹c klawisz 'T' \n   Aby anulowaæ, naciœnij 'ESC'");
	exit.setOrigin(exit.getLocalBounds().width / 2, exit.getLocalBounds().height / 2);
	exit.setPosition(sf::Vector2f(width / 2, height / 2));
}
void Exit::draw(sf::RenderWindow& window)
{

	window.draw(exit);
}
