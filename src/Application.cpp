#include "Application.h"
#include "LSystem.h"
#include "LSystemDrawer.h"
#include <iostream>


Application::Application(unsigned int width,unsigned int height):width(width),height(height){
    window=new sf::RenderWindow(sf::VideoMode(width,height), "L-system");
    panel=Panel(300,height);
    axiomField.SetPosition(5,height-55);
    axiomField.SetSize(width/3,50);
    ruleField.SetPosition(width/3+10,height-55);
    ruleField.SetSize(width/2,50);
    generationsField.SetSize(width/10,50);
    generationsField.SetPosition(5*width/6+15,height-55);
    components.push_back(&axiomField);
    components.push_back(&ruleField);
    components.push_back(&generationsField);
}

void Application::Run(){
    LSystem lsystem;
    lsystem.SetGenerations(4);
    LSystemDrawer picture;
    picture.SetLineLength(30);
    picture.SetRotationAngle(30);

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
        for(int i=0;i<components.size();i++ ){
          components[i]->CheckEvent(event,window);
        }
        lsystem.SetAxiom(axiomField.GetString());
        lsystem.AddRule('F',ruleField.GetString());
        lsystem.SetGenerations(generationsField.GetNumber());
        picture.SetLSystem(lsystem.GetString());

      }

      picture.Draw(window);
      for(int i=0;i<components.size();i++ ){
        components[i]->Draw(window);
      }
    //  panel.Draw(window);

      window->display();
    }
}
