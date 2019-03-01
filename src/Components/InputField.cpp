#include "InputField.h"
#include <iostream>

InputField::InputField(float x,float y,float width, float height):Component(x,y,width,height){
    isActive=false;
    if (!font.loadFromFile("resources/fonts/Lato-Black.ttf"))
    {
      std::cerr<<"Failed to load font"<<std::endl;
    }
    text.setFont(font);
    text.setCharacterSize(24);
}

void InputField::CheckEvent(sf::Event event,sf::RenderWindow* window){
  sf::Vector2f mousePos = sf::Vector2f((float)sf::Mouse::getPosition(*window).x,(float)sf::Mouse::getPosition(*window).y);
  switch(event.type){
    case sf::Event::MouseButtonPressed:
      if(rectangle.getGlobalBounds().contains(mousePos) ){
        isActive=true;
        rectangle.setFillColor(sf::Color(50,50,100));
      }
      else{
        isActive=false;
        rectangle.setFillColor(backgroundColor);
      }
      break;
  
  }
}
