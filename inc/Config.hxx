#ifndef CONFIG_HXX
#define CONFIG_HXX

#include <map> 
#include <string> 
#include "Tokenizer.hxx"

class Config : private Tokenizer {
public: 
  Config(); 
  ~Config(); 
private: 
  std::map<std::string, std::string> mAttributes; 
};

#endif 

