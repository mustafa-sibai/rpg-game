#include "Button.h"
#include <iostream>

namespace GUI
{
	Button::Button(const sf::Vector2f& position, const sf::Vector2f& scale) :
		m_position(position), m_scale(scale), m_mousePosition(nullptr), isMousePressed(false), isMouseReleased(false)
	{
	}

	Button::~Button()
	{
	}

	void Button::Initialize()
	{

	}

	void Button::Load()
	{
		m_texture.loadFromFile("assets/gui/button.png");
		m_sprite = sf::Sprite(m_texture);
		m_sprite.setPosition(m_position);
		m_sprite.setScale(m_scale);
	}

	void Button::Update(double deltaTime, const sf::Vector2f& mousePosition)
	{
		m_mousePosition = &mousePosition;
		isMouseReleased = false;

		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && !isMouseReleased)
		{
			isMousePressed = true;
		}
		else
		{
			if (isMousePressed)
			{
				isMouseReleased = true;
				isMousePressed = false;
			}
		}
	}

	bool Button::IsPressed()
	{
		if (isMouseReleased)
		{
			const sf::Vector2u& size = m_sprite.getTexture()->getSize();

			sf::Vector2f endPosition = sf::Vector2f(
				m_position.x + size.x * m_scale.x,
				m_position.y + size.y * m_scale.y);

			if (m_mousePosition->x >= m_position.x && m_mousePosition->x <= endPosition.x &&
				m_mousePosition->y >= m_position.y && m_mousePosition->y <= endPosition.y)
			{
				return true;
			}
		}

		return false;
	}

	void Button::Draw(sf::RenderWindow& window)
	{
		window.draw(m_sprite);
	}
}