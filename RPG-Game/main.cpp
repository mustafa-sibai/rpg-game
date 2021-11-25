#include <SFML/Graphics.hpp>
#include <iostream>

#include "FrameRate.h"
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

	FrameRate frameRate;
	Player player;
	Skeleton skeleton;

	//-------------------------------- INITIALIZE --------------------------------
	frameRate.Initialize();
	player.Initialize();
	skeleton.Initialize();
	//-------------------------------- INITIALIZE --------------------------------

	//-------------------------------- LOAD --------------------------------
	frameRate.Load();
	player.Load();
	skeleton.Load();
	//-------------------------------- LOAD --------------------------------

	sf::Clock clock;

	while (window.isOpen())
	{
		sf::Time deltaTimeTimer = clock.restart();
		double deltaTime = deltaTimeTimer.asMicroseconds() / 1000.0;

		//-------------------------------- UPDATE --------------------------------
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		frameRate.Update(deltaTime);
		skeleton.Update(deltaTime);
		player.Update(deltaTime, skeleton);
		//-------------------------------- UPDATE --------------------------------

		//-------------------------------- DRAW --------------------------------
		window.clear(sf::Color::Black);
		skeleton.Draw(window);
		player.Draw(window);
		frameRate.Draw(window);
		window.display();
		//-------------------------------- DRAW --------------------------------
	}

	return 0;
}