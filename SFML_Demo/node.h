#pragma once
#include <SFML/Graphics.hpp>

class Node : public sf::Transformable, public sf::Drawable {
public:
	void addChild(Node* child);
	
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
	virtual void drawChildren(sf::RenderTarget& target, sf::RenderStates states) const;

private:
	std::vector<Node*>	mChildren;
	Node* mParent;
};