#include "Menu.h"
#include "statek.h"
#include "asteroida.h"

Menu::Menu(float width, float height)
{
	if (!font.loadFromFile("arial.ttf"))
	{
		// handle error
	}

	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color::Red);
	menu[0].setString("Resume");
	menu[0].setPosition(sf::Vector2f(width / 2.55 , height / (MAX_NUMBER_OF_ITEMS + 1) * 1));


	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("New Game");
	menu[1].setPosition(sf::Vector2f(width / 2.7, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));

	menu[2].setFont(font);
	menu[2].setFillColor(sf::Color::White);
	menu[2].setString("Options");
	menu[2].setPosition(sf::Vector2f(width / 2.5 , height / (MAX_NUMBER_OF_ITEMS + 1) * 3));

	menu[3].setFont(font);
	menu[3].setFillColor(sf::Color::White);
	menu[3].setString("Help");
	menu[3].setPosition(sf::Vector2f(width / 2.3, height / (MAX_NUMBER_OF_ITEMS + 1) * 4));

	menu[4].setFont(font);
	menu[4].setFillColor(sf::Color::White);
	menu[4].setString("Exit");
	menu[4].setPosition(sf::Vector2f(width / 2.25, height / (MAX_NUMBER_OF_ITEMS + 1) * 5));

	selectedItemIndex = 0;
}


Menu::~Menu()
{
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

void NewGame(int* points, float* dt, float* next_asteroid, Statek* statek, Asteroida* asteroids)
{
	*points = 0;
	*dt = 0;
	*next_asteroid = 0;
	statek-> 
}

#include "SFML/Graphics.hpp"
#include <iostream>


//int main()
//{
//	sf::RenderWindow window(sf::VideoMode(600, 600), "Asteroids");
//
//	Menu menu(window.getSize().x, window.getSize().y);
//
//	while (window.isOpen())
//	{
//		sf::Event event;
//
//		while (window.pollEvent(event))
//		{
//			switch (event.type)
//			{
//			case sf::Event::KeyReleased:
//				switch (event.key.code)
//				{
//				case sf::Keyboard::Up:
//					menu.MoveUp();
//					break;
//
//				case sf::Keyboard::Down:
//					menu.MoveDown();
//					break;
//
//				case sf::Keyboard::Return:
//					switch (menu.GetPressedItem())
//					{
//					case 0:
//						std::cout << "Resume button has been pressed" << std::endl;
//
//						break;
//					case 1:
//						std::cout << "New Game button has been pressed" << std::endl;
//						break;
//					case 2:
//						std::cout << "Option button has been pressed" << std::endl;
//						break;
//					case 3:
//						std::cout << "Help button has been pressed" << std::endl;
//						break;
//					case 4:
//						window.close();
//						break;
//					}
//
//					break;
//				}
//
//				break;
//			case sf::Event::Closed:
//				window.close();
//
//				break;
//
//			}
//		}
//
//		window.clear();
//
//		menu.draw(window);
//
//		window.display();
//	}
//}