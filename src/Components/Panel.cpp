#include "Panel.h"

Panel::Panel(float width,float height):Component(0,0,width,height){

}

void Panel::Draw(sf::RenderWindow* window){
  window->draw(rectangle);
}

void Panel::CheckEvent(sf::Event event,sf::RenderWindow* window){

}
