#pragma once
#include <SFML/Graphics.hpp>

class Skeleton
{
private:
	sf::Texture texture;

public:
	sf::Sprite sprite;

	sf::RectangleShape boundingRectangle;
	sf::Vector2i size;

public:
	Skeleton();
	~Skeleton();

	void Initialize();
	void Load();
	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window);
};