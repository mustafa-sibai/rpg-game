#include "Skeleton.h"
#include <iostream>

Skeleton::Skeleton() : 
	health(100)
{
}

Skeleton::~Skeleton()
{
}

void Skeleton::ChangeHealth(int hp)
{
	health += hp;
	healthText.setString(std::to_string(health));
}

void Skeleton::Initialize()
{
	boundingRectangle.setFillColor(sf::Color::Transparent);
	boundingRectangle.setOutlineColor(sf::Color::Blue);
	boundingRectangle.setOutlineThickness(1);

	size = sf::Vector2i(64, 64);
}

void Skeleton::Load()
{
	if (font.loadFromFile("Assets/Fonts/arial.ttf"))
	{
		std::cout << "Arial.ttf font in Assets has been loaded successfully" << std::endl;
		healthText.setFont(font);
		healthText.setString(std::to_string(health));
	}
	else
	{
		std::cout << "Failed to load Arial.ttf font in Assets" << std::endl;
	}

	if (texture.loadFromFile("Assets/Skeleton/Textures/spritesheet.png"))
	{
		std::cout << "Skeleton texture loaded!" << std::endl;
		sprite.setTexture(texture);
		sprite.setPosition(sf::Vector2f(1600, 700));

		int XIndex = 0;
		int YIndex = 2;

		sprite.setTextureRect(sf::IntRect(XIndex * size.x, YIndex * size.y, size.x, size.y));
		sprite.scale(sf::Vector2f(3, 3));

		boundingRectangle.setSize(
			sf::Vector2f(size.x * sprite.getScale().x, size.y * sprite.getScale().y)
		);
	}
	else
	{
		std::cout << "Skeleton texture failed to loaded!" << std::endl;
	}
}

void Skeleton::Update(float deltaTime)
{
	if (health > 0)
	{
		boundingRectangle.setPosition(sprite.getPosition());
		healthText.setPosition(sprite.getPosition());
	}
}

void Skeleton::Draw(sf::RenderWindow& window)
{
	if (health > 0)
	{
		window.draw(sprite);
		window.draw(boundingRectangle);
		window.draw(healthText);
	}
}