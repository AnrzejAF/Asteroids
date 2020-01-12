#include "options.h"
#include "statek.h"
#include "asteroida.h"
#include "menu.h"
#include "help.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>



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

	Statek statek(RESX, RESY, 5, 1, 0.0001);
	ContextSettings settings;
	settings.antialiasingLevel = 8;
	RenderWindow window(VideoMode(RESX, RESY), "Gierka", Style::Default, settings);
	window.setFramerateLimit(60);
	Event event;
	Menu menu(window.getSize().x, window.getSize().y);
	Help help(window.getSize().x, window.getSize().y);
	bool menu_flag = 1;
	bool help_flag = 0;
	while (window.isOpen())
	{
		if (menu_flag)
		{
			while (window.pollEvent(event))
			{
				switch (event.type)
				{
				case sf::Event::KeyReleased:
					switch (event.key.code)
					{
					case sf::Keyboard::Up:
						if(!help_flag)
							menu.MoveUp();
						break;

					case sf::Keyboard::Down:
						if (!help_flag)
							menu.MoveDown();
						break;

					case sf::Keyboard::Escape:
						help_flag = 0;
						break;

					case sf::Keyboard::Return:
						if (!help_flag)
							switch (menu.GetPressedItem())
							{
							case 0:
								std::cout << "Resume button has been pressed" << std::endl;
								menu_flag = 0;
								clock.restart().asSeconds();
								break;

							case 1:
								std::cout << "New Game button has been pressed" << std::endl;
								menu_flag = 0;
								srand(time(0));
								menu.NewGame(&points, &dt, &next_asteroid, &statek, asteroids);
							
								break;
							case 2:
								std::cout << "Option button has been pressed" << std::endl;
								break;
							case 3:
								std::cout << "Help button has been pressed" << std::endl;
								help_flag = 1;
								break;
							case 4:
								window.close();
								break;
							}

						break;
					}





					break;
				case sf::Event::Closed:
					window.close();

					break;

				}
			}

			window.clear();
			if (help_flag)
				help.draw(window);
			else
				menu.draw(window);

			window.display();
		}
		else
		{
			window.clear(Color::Black);

			next_asteroid -= dt;


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


			while (window.pollEvent(event)) {
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
				statek.accelerate(0.005, dt);
			}
			if (Keyboard::isKeyPressed(Keyboard::Down))
			{
				statek.accelerate(-0.005, dt);
			}
			if (Keyboard::isKeyPressed(Keyboard::S))
			{
				std::cout << points << std::endl;
			}
			if (Keyboard::isKeyPressed(Keyboard::Escape))
			{
				menu_flag = 1;
			}
			if (Keyboard::isKeyPressed(Keyboard::F1))
			{
				menu_flag = 1;
				help_flag = 1;
			}
			window.display();
			dt = clock.restart().asSeconds();
		}

	}

	return 0;
}