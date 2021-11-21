#include <SFML/Graphics.hpp>
#include <iostream>

#include "Player.h"
#include "Skeleton.h"

int main()
{
	//-------------------------------- INITIALIZE --------------------------------
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "RPG Game", sf::Style::Default, settings);
	window.setFramerateLimit(360);
	//-------------------------------- INITIALIZE --------------------------------

	Player player;
	Skeleton skeleton;

	//-------------------------------- INITIALIZE --------------------------------
	player.Initialize();
	skeleton.Initialize();
	//-------------------------------- INITIALIZE --------------------------------

	//-------------------------------- LOAD --------------------------------
	player.Load();
	skeleton.Load();
	//-------------------------------- LOAD --------------------------------

	sf::Clock clock;

	while (window.isOpen())
	{
		sf::Time deltaTimeTimer = clock.restart();
		float deltaTime = deltaTimeTimer.asMilliseconds();

		//-------------------------------- UPDATE --------------------------------
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		skeleton.Update(deltaTime);
		player.Update(deltaTime, skeleton);
		//-------------------------------- UPDATE --------------------------------

		//-------------------------------- DRAW --------------------------------
		window.clear(sf::Color::Black);
		skeleton.Draw(window);
		player.Draw(window);
		window.display();
		//-------------------------------- DRAW --------------------------------
	}

	return 0;
}