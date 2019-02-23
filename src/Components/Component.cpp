#include "Component.h"
#include <iostream>

Component::Component(float x, float y,float width,float height):width(width),height(height){
  position.x=x;
  position.y=y;
  rectangle=sf::RectangleShape(sf::Vector2f(width,height));
  rectangle.setPosition(x,y);
}

void Component::Draw(sf::RenderWindow* window){

}

void Component::SetPosition(float x, float y){
  position.x=x;
  position.y=y;
  rectangle.setPosition(x,y);

}
