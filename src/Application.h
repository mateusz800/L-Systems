#include <SFML/Graphics.hpp>
#include "Components/TextField.h"
#include "Components/NumberField.h"
#include "Components/Panel.h"
#include <vector>

class Application
{
private:
  unsigned int  width;
  unsigned int height;
  sf::RenderWindow* window;
  Panel panel;
  std::vector<Component*> components;
  TextField axiomField;
  TextField ruleField;
  NumberField generationsField;

public:
  Application(unsigned int width=600,unsigned int height=600);
  void Run();

};
