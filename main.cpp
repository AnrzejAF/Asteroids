#include "statek.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <cmath>


using namespace sf;
#define RESX 800 
#define RESY 600
#define ROTATION_SPEED 3



int main()
{
	Clock clock;
	float dt = 0;
	Statek statek(RESX, RESY, 5, 1, 0.0001);

	ContextSettings settings;
	settings.antialiasingLevel = 8;
	RenderWindow window(VideoMode(RESX, RESY), "Gierka", Style::Default, settings);
	window.setFramerateLimit(60);
	Event event;
	while (window.isOpen())
	{
		statek.move(dt);
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed)
				window.close();
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
		}
		window.clear(Color::Black);
		window.draw(*statek.getShape());
		window.display();
		dt = clock.restart().asSeconds();
	}

	return 0;
}