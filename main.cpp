#include "options.h"
#include "statek.h"
#include "asteroida.h"
#include "menu.h"
#include "help.h"
#include "exit.h"
#include "poziom.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>
#include <string>


using namespace sf;
using namespace std;



int main()
{
	srand(time(0));
	Clock clock;
	int points = 0;
	float dt = 0;
	float next_asteroid = 0;
	Asteroida* asteroids[MAX_N] = { NULL };

	Statek statek(RESX, RESY, 5, 1, 100, RESX/2, RESY/2);
	ContextSettings settings;
	settings.antialiasingLevel = 8;
	RenderWindow window(VideoMode(RESX, RESY), "Gierka", Style::Default, settings);
	window.setFramerateLimit(60);
	Event event;
	Menu menu(window.getSize().x, window.getSize().y);
	Help help(window.getSize().x, window.getSize().y);
	Exit exit(window.getSize().x, window.getSize().y);
	Poziom poziom(window.getSize().x, window.getSize().y);
	bool game_flag = 0;
	bool menu_flag = 1;
	bool help_flag = 0;
	bool exit_flag = 0;
	bool poziom_flag = 0;

	string imie;

	while (window.isOpen())
	{
		window.clear(Color::Black);
		if (menu_flag)
		{
			menu.draw(window);
			while (window.pollEvent(event))
			{
				if (event.type == Event::Closed)
				{
					menu_flag = 0; 
					exit_flag = 1;
				}
				switch (event.type)
				{
				case sf::Event::KeyReleased:
					switch (event.key.code)
					{
					case sf::Keyboard::Up:
						menu.MoveUp();
						break;

					case sf::Keyboard::Down:
						menu.MoveDown();
						break;

					case sf::Keyboard::Return:
						switch (menu.GetPressedItem())
						{
						case 0:
							if (game_flag)
							{
								std::cout << "Resume button has been pressed" << std::endl;
								menu_flag = 0;
								clock.restart().asSeconds();
							}
							break;

						case 1:
							std::cout << "New Game button has been pressed" << std::endl;
							menu_flag = 0;
							srand(time(0));
							menu.NewGame(&points, &dt, &next_asteroid, &statek, asteroids);
							game_flag = 1;

							break;
						case 2:
							std::cout << "Option button has been pressed" << std::endl;
							poziom_flag = 1;
							menu_flag = 0;
							break;
						case 3:
							std::cout << "Help button has been pressed" << std::endl;
							help_flag = 1;
							menu_flag = 0;
							break;
						case 4:
							menu_flag = 0;
							exit_flag = 1;
							break;
						}

						break;
					}
					break;

				}
			}
			
		}
		else if (help_flag)
		{

			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::KeyReleased)
					switch (event.key.code)
					{
					case sf::Keyboard::Escape:
						help_flag = 0;
						menu_flag = 1;
						break;
					}
			}
			help.draw(window);
		}
		else if (exit_flag)
		{
			exit.draw(window);
			if (Keyboard::isKeyPressed(Keyboard::T))
			{
				if (exit_flag)
					window.close();
			}
			if (Keyboard::isKeyPressed(Keyboard::Escape))
			{
				exit_flag = 0;
				menu_flag = 1;
			}
		}
		else if (poziom_flag)
		{
			poziom.draw(window);
			while (window.pollEvent(event))
			{
				switch (event.type)
				{
				case sf::Event::KeyReleased:
					switch (event.key.code)
					{
					case sf::Keyboard::Up:
						if (poziom_flag)
							poziom.MoveLeft();
						break;

					case sf::Keyboard::Down:
						if (poziom_flag)
							poziom.MoveRight();
						break;

					case sf::Keyboard::Escape:
						poziom_flag = 0;
						menu_flag = 1;
						break;

					case sf::Keyboard::Return:
						poziom_flag = 0;
						menu_flag = 1;
						break;

					}

				}
			}
		}
		else if (game_flag)
		{

			while (window.pollEvent(event))
			{
				if (event.type == Event::Closed)
				{
					exit_flag = 1;
					
				}
				switch (event.type)
				{
					case sf::Event::KeyReleased:						
						switch (event.key.code)
						{
							case sf::Keyboard::S:
							{
								fstream plik;
								plik.open("zapis_danych.txt", ios::out);
								plik << points << endl;
								plik.close();
								cout << "Zapisana ilosc punktow:  " << points << endl;
								break;
							}
							case Keyboard::U:
							{
								fstream plik;
								plik.open("zapis_danych.txt", ios::in);
								if (plik.good() == false) cout << "Nie mozna otworzyc pliku!";
								plik >> points;
								plik.close();
								cout << "Wczytane punkty:   " << points << endl;
								break;
							}
						}
						
				}break;
			}

			next_asteroid -= (poziom.GetPressedItem() + 1) * dt;
			if (next_asteroid <= 0)
			{
				next_asteroid = 5 + (float)(rand() % 5);
				for (int i = 0; i < MAX_N; i++)
				{
					if (asteroids[i] == NULL)
					{
						asteroids[i] = new Asteroida(7, 1, 1, &statek, asteroids, &points);
						break;
					}
				}
			}

			statek.move(dt);
			statek.WallCollision(RESX, RESY);
			window.draw(statek.shape);
			window.draw(statek.shapeMirrorTop);
			window.draw(statek.shapeMirrorDown);
			window.draw(statek.shapeMirrorLeft);
			window.draw(statek.shapeMirrorRight);


			for (int i = 0; i < MAX_N; i++)
			{
				if (asteroids[i] != NULL)
				{
					asteroids[i]->move(dt);
					asteroids[i]->rotate(5, dt);
					window.draw(*asteroids[i]->getShape());
					asteroids[i]->collision();

				}
			}


			while (window.pollEvent(event))
			{
				if (event.type == Event::Closed)
					window.close();
			}

			if (Keyboard::isKeyPressed(Keyboard::Left))
			{
				statek.rotate(-ROTATION_SPEED);
			}
			if (Keyboard::isKeyPressed(Keyboard::Right))
			{
				statek.rotate(ROTATION_SPEED);
			}
			if (Keyboard::isKeyPressed(Keyboard::Up))
			{
				statek.accelerate(300, dt);
			}
			if (Keyboard::isKeyPressed(Keyboard::Down))
			{
				statek.accelerate(-200, dt);
			}

			if (Keyboard::isKeyPressed(Keyboard::Escape))
			{
				menu_flag = 1;

			}
			if (Keyboard::isKeyPressed(Keyboard::F1))
			{
				menu_flag = 0;
				help_flag = 1;
			}

			sf::Text pointsText;
			sf::Font font;
			font.loadFromFile("arial.ttf");
			pointsText.setFont(font);
			pointsText.setFillColor(sf::Color::White);
			pointsText.setString("Punkty: " + to_string(points));
			pointsText.setOrigin(0, 0);
			pointsText.setPosition(sf::Vector2f(5, 5));
			window.draw(pointsText);
		}

		dt = clock.restart().asSeconds();
	
	window.display();
	
}
return 0;
}
