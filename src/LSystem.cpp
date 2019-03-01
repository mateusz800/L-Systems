#include "LSystem.h"
#include <iostream>
#include <vector>

void LSystem::SetAxiom(std::string axiom){
  this->axiom=axiom;
  result=axiom;
}

void LSystem::AddRule(char name,std::string rule){
    if(rules.find(name)==rules.end())
      rules.insert(std::pair<char,std::string>(name,rule));
    else
      rules.find(name)->second=rule;
}

void LSystem::SetGenerations(unsigned int count){
  generations=count;
}


void LSystem::generate(){
  for(int i=0;i<generations;i++){
    unsigned int offset=0;
    std::vector<size_t> position;
    for(std::map<char,std::string>::iterator iter = rules.begin(); iter != rules.end(); ++iter){
      char sign=iter->first;
      size_t pos=result.find(sign,0);
      while(pos!=std::string::npos){
          position.push_back(pos);
          pos=result.find(sign,pos+1);
      }
      for(int i=0;i<position.size();i++){
        std::string rule=rules.find(sign)->second;
        result.replace(position[i]+offset,1,rule);
        offset+=rule.length()-1 ;
      }
    }
  }
}

std::string LSystem::GetString() {
  generate();
  return result;
}
