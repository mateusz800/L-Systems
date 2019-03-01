#include "TextField.h"
#include <iostream>
#include <string>

void TextField::Draw(sf::RenderWindow* window){
  text.setPosition(position.x,position.y);
  window->draw(rectangle);
  window->draw(text);
}

std::string TextField::GetString() const{
  return inputText;
}

void TextField::CheckEvent(sf::Event event,sf::RenderWindow* window){
  InputField::CheckEvent(event,window);
  switch(event.type){
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
