#include "LSystemDrawer.h"
#include <math.h>
#include <iostream>


LSystemDrawer::LSystemDrawer(unsigned int lineLength,float angle):lineLength(lineLength),rotationAngle(angle){
  setStartingPosition();
}

void LSystemDrawer::setStartingPosition(){
  positionStack.push(Position(300,300,0));
}

void LSystemDrawer::move(sf::RenderWindow* window){
  Position pos=positionStack.top();
  Position nextPos=Position(pos.x+lineLength*sin(pos.angle),pos.y-lineLength*cos(pos.angle),pos.angle);
  sf::Vertex line[]={
    sf::Vertex(sf::Vector2f(pos.x,pos.y)),
    sf::Vertex(sf::Vector2f(nextPos.x,nextPos.y))
  };
  window->draw(line,2,sf::Lines);
  positionStack.pop();
  positionStack.push(nextPos);
}

void LSystemDrawer::rotateRight(){
  positionStack.top().angle+=M_PI*rotationAngle/180;
}

void LSystemDrawer::rotateLeft(){
  positionStack.top().angle-=M_PI*rotationAngle/180;
}

void LSystemDrawer::push(){
  positionStack.push(positionStack.top());
}

void LSystemDrawer::pop(){
  positionStack.pop();
}

void LSystemDrawer::SetLSystem(std::string lsystem){
  this->lsystem=lsystem;
}

void LSystemDrawer::SetLineLength(unsigned int length){
  lineLength=length;
}

void LSystemDrawer::SetRotationAngle(float angle){
  this->rotationAngle=angle;
}

void LSystemDrawer::Draw(sf::RenderWindow* window){
  for(int i=0;i<lsystem.length();i++){
    switch(lsystem[i]){
      case 'F':
        move(window);
        break;
      case '+':
        rotateRight();
        break;
      case '-':
        rotateLeft();
        break;
      case '[':
        push();
        break;
      case ']':
        pop();
        break;
    }
  }
  setStartingPosition();
}
