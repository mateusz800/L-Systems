#ifndef COMPONENT_H
#define COMPONENT_H

#include <SFML/Graphics.hpp>




class Component{
protected:
    sf::Vector2f position;
    float width;
    float height;
    sf::RectangleShape rectangle;
    sf::Color backgroundColor;
public:
    Component(float x=0,float y=0,float width=100, float height=50,sf::Color backgroundColor=sf::Color(100,100,100));
    void SetPosition(float x,float y);
    void SetSize(float width,float height);
    virtual void Draw(sf::RenderWindow* window)=0;
    virtual void CheckEvent(sf::Event event,sf::RenderWindow* window)=0;


};

#endif
