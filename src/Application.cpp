#include "Application.h"

Application::Application(){
    window=new sf::RenderWindow(sf::VideoMode(200, 200), "SFML works!");
}

void Application::Run(){
    while (window->isOpen()){
      sf::Event event;
      while (window->pollEvent(event))
      {
          if (event.type == sf::Event::Closed)
              window->close();
      }

      window->clear();
      window->display();
    }
}
