#ifndef CONFIG_HXX
#define CONFIG_HXX

#include <map> 
#include <string> 

class Config {
public: 
  Config(); 
  ~Config(); 
private: 
  std::map<std::string, std::string> mAttributes; 
};

#endif 

