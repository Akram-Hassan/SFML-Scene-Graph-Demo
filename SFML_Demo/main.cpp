#include <SFML/Graphics.hpp>
#include "MyRect.h"
#include "node.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 640), "SFML works!");
    window.setFramerateLimit(60);
    
    MyRect sceneRoot(50,60);
    sceneRoot.setPosition(200.f, 200.f);

    MyRect* child1 = new  MyRect(50, 60, sf::Color::Yellow);
    child1->setPosition(10, 10);
    sceneRoot.addChild(child1);

    MyRect* child2 = new  MyRect(50, 60, sf::Color::Green);
    child2->setPosition(10, 10);
    child1->addChild(child2);

    while (window.isOpen())
    {
        //Handle input
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        //Render frame
        window.clear(sf::Color::White);

        sceneRoot.move(1.0f, 0.f);

        //draw the root only from the main loop
        window.draw(sceneRoot);

        window.display();
    }
    //cleanup or use smart pointers
    delete child2;
    delete child1;

    return 0;
}