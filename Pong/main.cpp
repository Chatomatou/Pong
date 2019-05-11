#include "Paddle.hpp"
#include "Ball.hpp"
#include "Constants.hpp"

#include <iostream>

int main()
{
	 
	sf::RenderWindow window{ sf::VideoMode{static_cast<unsigned int>(WIDTHSCREEN), static_cast<unsigned int>(HEIGHTSCREEN)}, "Pong", sf::Style::Fullscreen};
	window.setMouseCursorVisible(false);
	sf::Event events;

	window.setFramerateLimit(60);

	Paddle player{ window, 20, HEIGHTSCREEN / 2 - HEIGHT_PADDLE<int> / 2, WIDTH_PADDLE<int>, HEIGHT_PADDLE<int>};
	player.setControllable(true);
	Paddle bot{ window, WIDTHSCREEN -WIDTH_PADDLE<int> -20, HEIGHTSCREEN / 2 - HEIGHT_PADDLE<int> / 2, WIDTH_PADDLE<int>, HEIGHT_PADDLE<int> };
	bot.setControllable(false);

	Ball ball{ window, 6 };

	sf::Clock clock;
	sf::Time dt;

	while (window.isOpen())
	{
		while (window.pollEvent(events))
		{
			switch (events.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::KeyPressed:
				if (events.key.code == sf::Keyboard::Escape)
					window.close();
				break;
			}
		}
		
		dt = clock.restart();

		player.update(dt, ball);
		bot.update(dt, ball);
		ball.update(dt);

		window.clear();

		player.draw();
		bot.draw();
		ball.draw();

		window.display();

	}


	return 0;
}