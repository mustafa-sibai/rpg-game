#include "Map.h"
#include <iostream>

Map::Map() :
	totalTilesX(0), totalTilesY(0),
	totalTiles(0), tiles(nullptr), mapSprites(nullptr)
{
}

Map::~Map()
{
	delete[] mapSprites;
	delete[] tiles;
}

void Map::Initialize()
{
}

void Map::Load(std::string filename)
{
	mapLoader.Load(filename, md);
	mapSprites = new sf::Sprite[md.dataLength];

	if (tileSheetTexture.loadFromFile(md.tilesheet))
	{
		std::cout << "World prison tilesheet in Assets has been loaded successfully" << std::endl;

		totalTilesX = tileSheetTexture.getSize().x / md.tileWidth;
		totalTilesY = tileSheetTexture.getSize().y / md.tileHeight;

		totalTiles = totalTilesX * totalTilesY;

		tiles = new Tile[totalTiles];

		for (int y = 0; y < totalTilesY; y++)
		{
			for (int x = 0; x < totalTilesX; x++)
			{
				int i = x + y * totalTilesX;

				tiles[i].id = i;
				tiles[i].position = sf::Vector2i(x * md.tileWidth, y * md.tileHeight);
			}
		}
	}
	else
	{
		std::cout << "Failed to load world prison tilesheet in Assets" << std::endl;
	}

	for (size_t y = 0; y < md.mapHeight; y++)
	{
		for (size_t x = 0; x < md.mapWidth; x++)
		{
			int i = x + y * md.mapWidth;

			int index = md.data[i];

			mapSprites[i].setTexture(tileSheetTexture);

			mapSprites[i].setTextureRect(sf::IntRect(
				tiles[index].position.x,
				tiles[index].position.y,
				md.tileWidth,
				md.tileHeight));

			mapSprites[i].setScale(sf::Vector2f(md.scaleX, md.scaleY));
			mapSprites[i].setPosition(sf::Vector2f(
				x * md.tileWidth * md.scaleX,
				100 + y * md.tileHeight * md.scaleY));
		}
	}
}

void Map::Update(double deltaTime)
{
}

void Map::Draw(sf::RenderWindow& window)
{
	for (size_t i = 0; i < md.dataLength; i++)
		window.draw(mapSprites[i]);
}