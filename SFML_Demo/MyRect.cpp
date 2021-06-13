#include "MyRect.h"

MyRect::MyRect(float width, float height, sf::Color color) : m_RectShape(sf::RectangleShape(sf::Vector2f(width, height))) {
	m_RectShape.setFillColor(color);
}

void MyRect::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_RectShape, states);
}
