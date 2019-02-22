#ifndef LSYSTEMDRAWER_H
#define LSYSTEMDRAWER_H

#include <SFML/Graphics.hpp>
#include <stack>
#include "LSystem.h"

struct Position{
  float x;
  float y;
  float angle;
  inline Position(float x,float y,float angle):x(x),y(y),angle(angle){};
};

class LSystemDrawer{
private:
  std::string lsystem;
  float lineLength;
  float rotationAngle;
  std::stack<Position> positionStack;
  void setStartingPosition();
  void move(sf::RenderWindow* window);
  void rotateRight();
  void rotateLeft();
  void push();
  void pop();
public:
  LSystemDrawer(float lineLength=100,float rotationAngle=30);
  void SetLSystem(std::string lsystem);
  void SetLineLength(float length);
  void Draw(sf::RenderWindow* window);



};

#endif
