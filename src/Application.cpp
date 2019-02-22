#include "Application.h"
#include "LSystem.h"
#include "LSystemDrawer.h"
#include <iostream>


Application::Application(){
    window=new sf::RenderWindow(sf::VideoMode(600, 600), "L-system");
}

void Application::Run(){
    LSystem lsystem;
    lsystem.SetAxiom("F");
    lsystem.AddRule('F',"F[-F][+F]");
    lsystem.SetGenerations(5);
    LSystemDrawer tree;
    tree.SetLineLength(50);
    tree.SetLSystem(lsystem.GetString());


    while (window->isOpen()){
      window->clear();
      sf::Event event;
      while (window->pollEvent(event))
      {
          if (event.type == sf::Event::Closed)
              window->close();
      }

      tree.Draw(window);


      window->display();
    }
}
