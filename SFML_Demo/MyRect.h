#pragma once
#include <SFML/Graphics.hpp>
#include "node.h"

class MyRect : public Node
{
	private:
		sf::RectangleShape m_RectShape;

	public:
		MyRect(float width, float height, sf::Color color = sf::Color::Red);
		virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
};

