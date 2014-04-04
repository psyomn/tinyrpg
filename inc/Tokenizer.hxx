#ifndef TOKENIZER_HXX
#define TOKENIZER_HXX

#include <iostream> 
#include <string> 
#include <vector> 
#include <sstream> 

class Tokenizer {
public:
  Tokenizer(); 
  ~Tokenizer();
  void tokenize(const std::string&); 
  std::vector<std::string> tokens(); 
private: 
  std::vector<std::string> mTokens; 
};

#endif 

