#pragma once
#include <SFML/Graphics.hpp>
#include "MouseTile.h"

#define MAP_SIZE 50

class Map
{
private:
	MouseTile& m_mouseTile;
	sf::Sprite* m_mapSprites;

public:
	Map(MouseTile& mouseTile);
	~Map();

	void Initialize();
	void Load();
	void Update(double deltaTime, const sf::Vector2f& mousePosition);
	void Draw(sf::RenderWindow& window);
};