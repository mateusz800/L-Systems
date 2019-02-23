#include <SFML/Graphics.hpp>
#include "Components/TextField.h"

class Application
{
private:
  sf::RenderWindow* window;
  TextField textField;
public:
  Application();
  void Run();

};
