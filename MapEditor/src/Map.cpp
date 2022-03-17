#include "Map.h"
#include <iostream>

Map::Map(MouseTile& mouseTile) :
	m_mouseTile(mouseTile), m_mapSprites(nullptr)
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
	sf::Vector2f ww;

	if (m_mouseTile.IsMouseClickedOnTile(ww, mousePosition))
	{
		std::cout << "ww TILE POSITION: " << ww.x << " " << ww.y << std::endl;
	}
}

void Map::Draw(sf::RenderWindow& window)
{
	for (size_t i = 0; i < MAP_SIZE; i++)
		window.draw(m_mapSprites[i]);
}