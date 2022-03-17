#include "Grid.h"
#include "MouseTile.h"

Grid::Grid(
	const sf::Vector2f& position,
	const sf::Vector2i& cellSize,
	const sf::Vector2i& totalCells,
	const sf::Vector2i& scale,
	const sf::Color& color,
	int lineThinkness) :
	m_position(position), m_scale(scale), m_totalCells(totalCells),
	m_cellSize(cellSize), m_lineThickness(lineThinkness), m_color(color)
{
	m_totalLines = sf::Vector2i(totalCells.x + 1, totalCells.y + 1);

	m_hLine = new sf::RectangleShape[m_totalLines.y];
	m_vLine = new sf::RectangleShape[m_totalLines.x];
}

Grid::~Grid()
{
	delete[] m_hLine;
	delete[] m_vLine;
}

void Grid::Initialize()
{
	int horizontalLineLength = m_totalCells.x * m_cellSize.x * m_scale.x + m_lineThickness;
	int verticalLineLength = m_totalCells.y * m_cellSize.y * m_scale.y;

	for (size_t i = 0; i < m_totalLines.y; i++)
	{
		m_hLine[i].setSize(sf::Vector2f(horizontalLineLength, m_lineThickness));
		m_hLine[i].setPosition(m_position + sf::Vector2f(0, i * m_cellSize.y * m_scale.x));
		m_hLine[i].setFillColor(m_color);
	}

	for (size_t i = 0; i < m_totalLines.x; i++)
	{
		m_vLine[i].setSize(sf::Vector2f(m_lineThickness, verticalLineLength));
		m_vLine[i].setPosition(m_position + sf::Vector2f(i * m_cellSize.x * m_scale.x, 0));
		m_vLine[i].setFillColor(m_color);
	}
}

void Grid::Load()
{
}

void Grid::Update(double deltaTime)
{
}

void Grid::Draw(sf::RenderWindow& window)
{
	for (size_t i = 0; i < m_totalLines.y; i++)
		window.draw(m_hLine[i]);

	for (size_t i = 0; i < m_totalLines.x; i++)
		window.draw(m_vLine[i]);
}