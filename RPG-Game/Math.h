#pragma once
#include <SFML/Graphics.hpp>

class Math
{
public:
	static sf::Vector2f NormalizeVector(sf::Vector2f vector);
	static bool DidRectCollide(sf::FloatRect rect1, sf::FloatRect rect2);
};