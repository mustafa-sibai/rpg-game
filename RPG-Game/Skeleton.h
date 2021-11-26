#pragma once
#include <SFML/Graphics.hpp>

class Skeleton
{
private:
	sf::Texture texture;

	sf::Text healthText;
	sf::Font font;



public:
	sf::Sprite sprite;

	sf::RectangleShape boundingRectangle;
	sf::Vector2i size;

	int health;

public:
	Skeleton();
	~Skeleton();

	void ChangeHealth(int hp);

	void Initialize();
	void Load();
	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window);
};