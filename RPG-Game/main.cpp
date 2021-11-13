#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <math.h>

sf::Vector2f NormalizeVector(sf::Vector2f vector)
{
	float m = std::sqrt(vector.x * vector.x + vector.y * vector.y);

	sf::Vector2f normalizedVector;

	normalizedVector.x = vector.x / m;
	normalizedVector.y = vector.y / m;

	return normalizedVector;
}

int main()
{
	//-------------------------------- INITIALIZE --------------------------------
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "RPG Game", sf::Style::Default, settings);
	//-------------------------------- INITIALIZE --------------------------------

	std::vector<sf::RectangleShape> bullets;
	float bulletSpeed = 0.5f;

	//-------------------------------- LOAD --------------------------------
	//----------------------- Skeleton -----------------------
	sf::Texture skeletonTexture;
	sf::Sprite skeletonSprite;

	if (skeletonTexture.loadFromFile("Assets/Skeleton/Textures/spritesheet.png"))
	{
		std::cout << "Skeleton texture loaded!" << std::endl;
		skeletonSprite.setTexture(skeletonTexture);
		skeletonSprite.setPosition(sf::Vector2f(1600, 700));

		int XIndex = 0;
		int YIndex = 2;

		skeletonSprite.setTextureRect(sf::IntRect(XIndex * 64, YIndex * 64, 64, 64));
		skeletonSprite.scale(sf::Vector2f(3, 3));
	}
	else
	{
		std::cout << "Skeleton texture failed to loaded!" << std::endl;
	}
	//----------------------- Skeleton -----------------------

	//----------------------- Player -----------------------
	sf::Texture playerTexture;
	sf::Sprite playerSprite;

	if (playerTexture.loadFromFile("Assets/Player/Textures/spritesheet.png"))
	{
		std::cout << "Player texture loaded!" << std::endl;
		playerSprite.setTexture(playerTexture);

		int XIndex = 0;
		int YIndex = 0;

		playerSprite.setTextureRect(sf::IntRect(XIndex * 64, YIndex * 64, 64, 64));
		playerSprite.scale(sf::Vector2f(3, 3));
		playerSprite.setPosition(sf::Vector2f(0, 0));
	}
	else
	{
		std::cout << "Player texture failed to loaded!" << std::endl;
	}
	//----------------------- Player -----------------------
	//-------------------------------- LOAD --------------------------------

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

		sf::Vector2f position = playerSprite.getPosition();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			playerSprite.setPosition(position + sf::Vector2f(1, 0));

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			playerSprite.setPosition(position + sf::Vector2f(-1, 0));

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			playerSprite.setPosition(position + sf::Vector2f(0, -1));

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			playerSprite.setPosition(position + sf::Vector2f(0, 1));

		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
		{
			bullets.push_back(sf::RectangleShape(sf::Vector2f(50, 25)));

			int i = bullets.size() - 1;
			bullets[i].setPosition(playerSprite.getPosition());
		}

		for (size_t i = 0; i < bullets.size(); i++)
		{
			sf::Vector2f bulletDirection = skeletonSprite.getPosition() - bullets[i].getPosition();
			bulletDirection = NormalizeVector(bulletDirection);
			bullets[i].setPosition(bullets[i].getPosition() + bulletDirection * bulletSpeed);
		}

		//-------------------------------- UPDATE --------------------------------

		//-------------------------------- DRAW --------------------------------
		window.clear(sf::Color::Black);
		window.draw(skeletonSprite);
		window.draw(playerSprite);

		for (size_t i = 0; i < bullets.size(); i++)
		{
			window.draw(bullets[i]);
		}

		window.display();
		//-------------------------------- DRAW --------------------------------
	}

	return 0;
}