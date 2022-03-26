#include "Map.h"
#include <iostream>

Map::Map(const Grid& grid, MouseTile& mouseTile) :
	m_grid(grid), m_mouseTile(mouseTile), m_mapSprites(nullptr)
{
}

Map::~Map()
{
}

void Map::Initialize()
{
	m_mapSprites = new sf::Sprite[MAP_SIZE];
}

void Map::Load()
{
}

void Map::Update(double deltaTime, const sf::Vector2f& mousePosition)
{
	sf::Vector2f tilePosition;
	sf::Vector2i gridPosition;

	if (m_mouseTile.IsMouseClickedOnTile(tilePosition, gridPosition, mousePosition))
	{
		int i = gridPosition.x + gridPosition.y * m_grid.GetTotalCells().x;
		m_mapSprites[i] = m_mouseTile.GetSprite();
	}
}

void Map::Draw(sf::RenderWindow& window)
{
	for (size_t i = 0; i < MAP_SIZE; i++)
	{
		window.draw(m_mapSprites[i]);
	}
}