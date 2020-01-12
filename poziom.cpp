#include "poziom.h"


Poziom::Poziom(float width, float height)
{
	if (!font.loadFromFile("arial.ttf"))
	{
		// handle error
	}

	poziom[0].setFont(font);
	poziom[0].setFillColor(sf::Color::Red);
	poziom[0].setString(L"Trudny");
	poziom[0].setPosition(sf::Vector2f(width / 2.55, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));

	poziom[1].setFont(font);
	poziom[1].setFillColor(sf::Color::White);
	poziom[1].setString(L"Œredni");
	poziom[1].setPosition(sf::Vector2f(width / 2.5, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));

	poziom[2].setFont(font);
	poziom[2].setFillColor(sf::Color::White);
	poziom[2].setString(L"£atwy");
	poziom[2].setPosition(sf::Vector2f(width / 2.45, height / (MAX_NUMBER_OF_ITEMS + 1) * 3));


	selectedItemIndex = 0;
}



void Poziom::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(poziom[i]);
	}
}

void Poziom::MoveLeft()
{
	if (selectedItemIndex - 1 >= 0)
	{
		poziom[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		poziom[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}

void Poziom::MoveRight()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		poziom[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		poziom[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}
