#include "NumberField.h"

int NumberField::GetNumber()const{
  return number;
}

void NumberField::CheckEvent(sf::Event event,sf::RenderWindow* window){
  InputField::CheckEvent(event,window);
  switch(event.type){
    case sf::Event::TextEntered:
      if(isActive){
        char key=event.text.unicode;
        if(key=='\b' && inputText.length()>0){
          inputText.erase(inputText.length()-1);
        }
        else if(key>='0' && key<='9'){
          inputText+=event.text.unicode;
          number=key-'0';
        }
        text.setString(inputText);
      }
      break;
  }
}

void NumberField::Draw(sf::RenderWindow* window){
  text.setPosition(position.x,position.y);
  window->draw(rectangle);
  window->draw(text);
}
