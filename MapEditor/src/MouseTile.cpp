#include "MouseTile.h"

MouseTile::MouseTile(
	const sf::Vector2i& tileSize, 
	const sf::Vector2f& tileScale) :
	m_tileSize(tileSize),
	m_tileScale(tileScale)
{
}

MouseTile::~MouseTile()
{
}

void MouseTile::Initialize()
{
}

void MouseTile::Load()
{
	m_tileSheet.loadFromFile("assets/world/prison/tilesheet.png");
	m_tile.setTexture(m_tileSheet);
	m_tile.setTextureRect(sf::IntRect(11 * m_tileSize.x, 0, m_tileSize.x, m_tileSize.y));
	m_tile.setScale(m_tileScale);
}

void MouseTile::Update(double deltaTime, sf::Vector2f mousePosition)
{
	int intX = mousePosition.x / (m_tileSize.x * m_tileScale.x);
	int x = intX * (m_tileSize.x * m_tileScale.x);

	int intY = mousePosition.y / (m_tileSize.y * m_tileScale.y);
	int y = intY * (m_tileSize.y * m_tileScale.y);

	m_tile.setPosition(sf::Vector2f(x, y));
}

void MouseTile::Draw(sf::RenderWindow& window)
{
	window.draw(m_tile);
}