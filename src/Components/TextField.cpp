#include "TextField.h"
#include <iostream>
#include <string>

TextField::TextField(float x,float y,float width, float height):Component(x,y,width,height){
    isActive=false;
    if (!font.loadFromFile("resources/fonts/Lato-Black.ttf"))
    {
      std::cerr<<"Failed to load font"<<std::endl;
    }
    text.setFont(font);
    text.setCharacterSize(24);

  }

void TextField::CheckEvent(sf::Event event,sf::RenderWindow* window){
  sf::Vector2f mousePos = sf::Vector2f((float)sf::Mouse::getPosition(*window).x,(float)sf::Mouse::getPosition(*window).y);
  switch(event.type){
    case sf::Event::MouseButtonPressed:
      if(rectangle.getGlobalBounds().contains(mousePos) ){
        isActive=true;
        rectangle.setFillColor(sf::Color(100,100,100));
      }
      else{
        isActive=false;
        rectangle.setFillColor(sf::Color(255,255,255));
      }
      break;
    case sf::Event::TextEntered:
      if(isActive){
        if(event.text.unicode=='\b' && inputText.length()>0){
          inputText.erase(inputText.length()-1);
        }
        else{
        inputText+=event.text.unicode;
        }
        text.setString(inputText);
      }
      break;
  }
}



void TextField::Draw(sf::RenderWindow* window){
  text.setPosition(position.x,position.y);
  window->draw(rectangle);
  window->draw(text);
}
