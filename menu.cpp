#include "Menu.h"

Menu::Menu(float width, float height)
{
	if (!font.loadFromFile("arial.ttf"))
	{
		// handle error
	}

	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color::Red);
	menu[0].setString(L"Wzn�w");
	menu[0].setOrigin(menu[0].getLocalBounds().width / 2, menu[0].getLocalBounds().height / 2);
	menu[0].setPosition(sf::Vector2f(width / 2 , height / (MAX_NUMBER_OF_ITEMS + 1) * 1));

	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("Nowa Gra");
	menu[1].setOrigin(menu[1].getLocalBounds().width / 2, menu[1].getLocalBounds().height / 2);
	menu[1].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));

	menu[2].setFont(font);
	menu[2].setFillColor(sf::Color::White);
	menu[2].setString("Opcje");
	menu[2].setOrigin(menu[2].getLocalBounds().width / 2, menu[2].getLocalBounds().height / 2);
	menu[2].setPosition(sf::Vector2f(width / 2 , height / (MAX_NUMBER_OF_ITEMS + 1) * 3));

	menu[3].setFont(font);
	menu[3].setFillColor(sf::Color::White);
	menu[3].setString("Pomoc");
	menu[3].setOrigin(menu[3].getLocalBounds().width / 2, menu[3].getLocalBounds().height / 2);
	menu[3].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 4));

	menu[4].setFont(font);
	menu[4].setFillColor(sf::Color::White);
	menu[4].setString(L"Wyj�cie");
	menu[4].setOrigin(menu[4].getLocalBounds().width / 2, menu[4].getLocalBounds().height / 2);
	menu[4].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 5));

	selectedItemIndex = 0;
}



void Menu::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(menu[i]);
	}
}

void Menu::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}

void Menu::MoveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}


void Menu::NewGame(int* points, float* dt, float* next_asteroid, Statek* statek, Asteroida** asteroids)
{
	*points = 0;
	*dt = 0;
	*next_asteroid = 0;
	statek->posX = RESX / 2;
	statek->posY = RESY / 2;
	statek->velX = 0;
	statek->velY = 0;
	statek->deg = 1800;

	for (int i = 0; i < MAX_N; i++)
	{
		if (asteroids[i] != NULL)
		{
			asteroids[i]->destroy();
		}
	}
}

