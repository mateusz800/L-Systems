#include "Application.h"



Application::Application(){
    window=new sf::RenderWindow(sf::VideoMode(600, 600), "L-system");
}

void Application::Run(){
    //LSystem lsystem;
    //lsystem.SetAxiom('F');
    //lsystem.SetRule('F',"F[-F][+F]");
    //lsystem.SetGenerations(3);
    //std::cout<<lsystem.GetString()<<std::endl;
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
