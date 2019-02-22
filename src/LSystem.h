#ifndef LSYSTEM_H
#define LSYSTEM_H

#include <string>
#include <map>

class LSystem
{
private:
  std::string axiom;
  std::map<char,std::string> rules;
  unsigned int generations;
  std::string result;
  void generate();
public:
  void SetAxiom(std::string);
  void AddRule(char name,std::string rule);
  void SetGenerations(unsigned int count);
  std::string GetString();
};

#endif
