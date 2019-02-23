#ifndef TEXTFIELD_H
#define TEXTFIELD_H

#include "Component.h"
#include <string>

class TextField :public Component
{
  private:
    std::string inputText;
    sf::Text text;
    sf::Font font;
    bool isActive;
  public:
    TextField(float x=0,float y=0,float width=100, float height=50);
    void CheckEvent(sf::Event event,sf::RenderWindow* window);
    void Draw(sf::RenderWindow* window);


};

#endif
