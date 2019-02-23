#include "Application.h"
#include "LSystem.h"
#include "LSystemDrawer.h"
#include <iostream>


Application::Application(){
    window=new sf::RenderWindow(sf::VideoMode(600, 600), "L-system");
}

void Application::Run(){
    LSystem lsystem;
    lsystem.SetAxiom("F+F+F+F");
    lsystem.AddRule('F',"FF+F++F+F");
    lsystem.SetGenerations(4);
    LSystemDrawer tree;
    tree.SetLineLength(30);
    tree.SetLSystem(lsystem.GetString());
    tree.SetRotationAngle(30);
    textField.SetPosition(100.0f,500.0f);

    while (window->isOpen()){
      window->clear();
      sf::Event event;
      while (window->pollEvent(event))
      {
        switch(event.type){
          case sf::Event::Closed:
            window->close();
            break;
        }
        textField.CheckEvent(event,window);


      }
      textField.Draw(window);
      tree.Draw(window);


      window->display();
    }
}
