#ifndef PANEL_H
#define PANEL_H

#include <SFML/Graphics.hpp>
#include "Component.h"

class Panel:public Component{
private:
public:
  Panel(float width=300,float height=600);
  void Draw(sf::RenderWindow* window );
  void CheckEvent(sf::Event event,sf::RenderWindow* window);
};

#endif
