#pragma once
#include <SFML/Graphics.hpp>

namespace GUI
{
	class Button
	{
	private:
		sf::Sprite m_sprite;
		sf::Texture m_texture;

		const sf::Vector2f& m_position;
		const sf::Vector2f& m_scale;
		const sf::Vector2f* m_mousePosition;

		bool isMousePressed;
		bool isMouseReleased;

	public:
		Button(const sf::Vector2f& position, const sf::Vector2f& scale);
		~Button();

		void Initialize();
		void Load();
		void Update(double deltaTime, const sf::Vector2f& mousePosition);
		void Draw(sf::RenderWindow& window);

		bool IsPressed();
	};
}