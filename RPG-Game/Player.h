#pragma once
#include <SFML/Graphics.hpp>
#include "Skeleton.h"

class Player
{
private:
	sf::Texture texture;

	std::vector<sf::RectangleShape> bullets;
	float bulletSpeed;
	float playerSpeed;

	sf::RectangleShape boundingRectangle;
	sf::Vector2i size;

public:
	sf::Sprite sprite;

public:
	Player();
	~Player();

	void Initialize();
	void Load();
	void Update(float deltaTime, Skeleton& skeleton);
	void Draw(sf::RenderWindow& window);
};