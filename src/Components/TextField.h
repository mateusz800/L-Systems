#ifndef TEXTFIELD_H
#define TEXTFIELD_H

#include "InputField.h"
#include <string>

class TextField :public InputField
{
  public:
    void Draw(sf::RenderWindow* window);
    std::string GetString()const;
    void CheckEvent(sf::Event event, sf::RenderWindow* window);


};

#endif
