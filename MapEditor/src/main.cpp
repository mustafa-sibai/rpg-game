#include <SFML/Graphics.hpp>
#include <iostream>
#include "Grid.h"
#include "MouseTile.h"
#include "Map.h"
#include "GUI/Button.h"
#include "MapSaver.h"

using namespace GUI;

int main()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Map Editor", sf::Style::Default, settings);
	window.setFramerateLimit(360);

	Grid grid(
		sf::Vector2f(200, 150),
		sf::Vector2i(16, 16),
		sf::Vector2i(10, 5),
		sf::Vector2i(10, 10),
		sf::Color(255, 255, 255, 128),
		2);

	MouseTile mouseTile(grid, sf::Vector2i(16, 16), sf::Vector2f(10, 10), sf::Vector2f(200, 150));

	Map map(grid, mouseTile);

	Button button(sf::Vector2f(100, 50), sf::Vector2f(3, 3));
	MapSaver mapSever;

	//-------------------------------- INITIALIZE --------------------------------
	grid.Initialize();
	mouseTile.Initialize();
	map.Initialize();
	button.Initialize();
	//-------------------------------- INITIALIZE --------------------------------

	//-------------------------------- LOAD --------------------------------
	grid.Load();
	mouseTile.Load();
	map.Load();
	button.Load();
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

		sf::Vector2f mousePosition = sf::Vector2f(sf::Mouse::getPosition(window));

		mouseTile.Update(deltaTime, mousePosition);
		grid.Update(deltaTime);
		map.Update(deltaTime, mousePosition);
		button.Update(deltaTime, mousePosition);

		if (button.IsPressed())
		{
			MapData mapData(
				"assets/world/prison/tilesheet.png",
				"Level 1",
				grid.GetPosition().x,
				grid.GetPosition().y,
				grid.GetCellSize().x,
				grid.GetCellSize().y,
				grid.GetTotalCells().x,
				grid.GetTotalCells().y,
				grid.GetScale().x,
				grid.GetScale().y,
				MAP_SIZE,
				map.GetMapIDs());

			std::cout << grid.GetSize().x << std::endl;
			mapSever.Save("TheXFile.rmap", mapData);

			std::cout << "Saved map to file!" << std::endl;
		}
		//-------------------------------- UPDATE --------------------------------

		//-------------------------------- DRAW --------------------------------
		window.clear(sf::Color::Black);
		grid.Draw(window);
		mouseTile.Draw(window);
		map.Draw(window);
		button.Draw(window);
		window.display();
		//-------------------------------- DRAW --------------------------------
	}

	return 0;
}