#include "help.h"

using namespace sf;



Help::Help(float width, float height)
{
	if (!font.loadFromFile("arial.ttf"))
	{
		// handle error
	}


	help[0].setFont(font);
	help[0].setFillColor(sf::Color::White);
	help[0].setString(L"ASTEROIDY");
	help[0].setOrigin(help[0].getLocalBounds().width / 2, help[0].getLocalBounds().height / 2);
	help[0].setPosition(sf::Vector2f(width / 2, height / 7 *1));
	
	help[1].setFont(font);
	help[1].setFillColor(sf::Color::White);
	help[1].setString(L"kitraj g³azy");
	help[1].setOrigin(help[1].getLocalBounds().width / 2, help[1].getLocalBounds().height / 2);
	help[1].setPosition(sf::Vector2f(width / 2, height / 7*2));
	
	help[2].setFont(font);
	help[2].setFillColor(sf::Color::White);
	help[2].setString(L"poruszaj siê strza³kami");
	help[2].setOrigin(help[2].getLocalBounds().width / 2, help[2].getLocalBounds().height / 2);
	help[2].setPosition(sf::Vector2f(width / 2, height / 7*3));
	
	help[3].setFont(font);
	help[3].setFillColor(sf::Color::White);
	help[3].setString("S zapisuje wynik ");
	help[3].setOrigin(help[3].getLocalBounds().width / 2, help[3].getLocalBounds().height / 2);
	help[3].setPosition(sf::Vector2f(width / 2, height / 7*4));
	
	help[4].setFont(font);
	help[4].setFillColor(sf::Color::White);
	help[4].setString("U wczytuje ostatni zapis ");
	help[4].setOrigin(help[4].getLocalBounds().width / 2, help[4].getLocalBounds().height / 2);
	help[4].setPosition(sf::Vector2f(width / 2, height / 7*5));

	help[5].setFont(font);
	help[5].setFillColor(sf::Color::White);
	help[5].setString(L"Esc by wyjœæ");
	help[5].setOrigin(help[5].getLocalBounds().width / 2, help[5].getLocalBounds().height / 2);
	help[5].setPosition(sf::Vector2f(width / 2, height / 7 * 6));
}



void Help::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < 6; i++)
	{
		window.draw(help[i]);
	};
};
