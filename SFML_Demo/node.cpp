#include <SFML/Graphics.hpp>
#include "node.h"


void Node::addChild(Node* child)
{
	mChildren.push_back(child);
	child->mParent = this;
}

void Node::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const{
	//Empty default node --> do nothing.
}

void Node::drawChildren(sf::RenderTarget& target, sf::RenderStates states) const {
	for (Node* node : mChildren)
	{
		node->draw(target, states);
	}
}

void Node::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	//pass and combine the transform to the children transforms, 
	//so children transforms are calculated based on the root transform.
	states.transform *= getTransform();
	
	drawCurrent(target, states);
	drawChildren(target, states);
}
