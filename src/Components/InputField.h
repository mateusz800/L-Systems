#ifndef INPUTFIELD_H
#define INPUTFIELD_H

#include "Component.h"

class InputField:public Component{
protected:
  std::string inputText;
  sf::Text text;
  sf::Font font;
  bool isActive;
public:
      InputField(float x=0,float y=0,float width=100, float height=50);
      virtual void CheckEvent(sf::Event event,sf::RenderWindow* window);
};

#endif
