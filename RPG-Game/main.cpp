#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
	//-------------------------------- INITIALIZE --------------------------------

	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(800, 600), "RPG Game", sf::Style::Default, settings);

	sf::CircleShape shape(50.0f, 50);
	shape.setFillColor(sf::Color::Red);
	shape.setPosition(sf::Vector2f(100, 100));
	shape.setOutlineThickness(10);
	shape.setOutlineColor(sf::Color::Green);

	sf::RectangleShape rectangle(sf::Vector2f(200, 2));
	rectangle.setPosition(sf::Vector2f(300, 100));
	rectangle.setFillColor(sf::Color::Blue);
	//rectangle.setOrigin(rectangle.getSize() / 2.0f);
	//rectangle.setRotation(45);

	//-------------------------------- INITIALIZE --------------------------------

	//main game loop
	while (window.isOpen())
	{
		//-------------------------------- UPDATE --------------------------------
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		//-------------------------------- UPDATE --------------------------------

		//-------------------------------- DRAW --------------------------------
		window.clear(sf::Color::Black);
		window.draw(shape);
		window.draw(rectangle);
		window.display();
		//-------------------------------- DRAW --------------------------------
	}

	return 0;
}