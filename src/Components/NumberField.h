#ifndef NUMBERFIELD_H
#define NUMBERFIELD_H

#include "InputField.h"

class NumberField:public InputField{
private:
  int number;
public:
  int GetNumber()const;
  void CheckEvent(sf::Event event,sf::RenderWindow* window);
  void Draw(sf::RenderWindow* window);
};

#endif
