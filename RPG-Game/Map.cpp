#include "Map.h"
#include <iostream>

Map::Map() :
	tileWidth(16), tileHeight(16), totalTilesX(0), totalTilesY(0)
{
}

Map::~Map()
{
}

void Map::Initialize()
{
}

void Map::Load()
{
	if (tileSheetTexture.loadFromFile("Assets/World/Prison/Tilesheet.png"))
	{
		totalTilesX = tileSheetTexture.getSize().x / tileWidth;
		totalTilesY = tileSheetTexture.getSize().y / tileHeight;

		std::cout << totalTilesX << std::endl;
		std::cout << totalTilesY << std::endl;

		std::cout << "World prison tilesheet in Assets has been loaded successfully" << std::endl;

		for (size_t i = 0; i < 10; i++)
		{
			sprites[i].setTexture(tileSheetTexture);
			sprites[i].setTextureRect(sf::IntRect(i * tileWidth, 0 * tileHeight, tileWidth, tileHeight));
			sprites[i].setScale(sf::Vector2f(5, 5));
			sprites[i].setPosition(sf::Vector2f(100 + i * tileWidth * 5, 100));
		}
	}
	else
	{
		std::cout << "Failed to load world prison tilesheet in Assets" << std::endl;
	}
}

void Map::Update(float deltaTime)
{
}

void Map::Draw(sf::RenderWindow& window)
{
	for (size_t i = 0; i < 10; i++)
		window.draw(sprites[i]);
}