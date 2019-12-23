#include "options.h"
#include "statek.h"
#include "asteroida.h"
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
	while (window.isOpen())
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

		window.display();
		dt = clock.restart().asSeconds();
	}

	return 0;
}