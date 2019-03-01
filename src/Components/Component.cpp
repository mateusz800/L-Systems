#include "Component.h"
#include <iostream>

Component::Component(float x, float y,float width,float height,sf::Color backgroundColor):width(width),height(height),backgroundColor(backgroundColor){
  position.x=x;
  position.y=y;
  rectangle=sf::RectangleShape(sf::Vector2f(width,height));
  rectangle.setPosition(x,y);
  rectangle.setFillColor(backgroundColor);
}

void Component::SetPosition(float x, float y){
  position.x=x;
  position.y=y;
  rectangle.setPosition(x,y);

}

void Component::SetSize(float width,float height){
  this->width=width;
  this->height=height;
  rectangle.setSize(sf::Vector2f(width,height));
}
