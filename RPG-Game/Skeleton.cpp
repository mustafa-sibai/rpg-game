#include "Skeleton.h"
#include <iostream>

Skeleton::Skeleton()
{
}

Skeleton::~Skeleton()
{
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
	boundingRectangle.setPosition(sprite.getPosition());
}

void Skeleton::Draw(sf::RenderWindow& window)
{
	window.draw(sprite);
	window.draw(boundingRectangle);
}