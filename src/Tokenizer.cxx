#include "Tokenizer.hxx" 

Tokenizer::Tokenizer(){
}

Tokenizer::~Tokenizer(){
}

/** This assumes that we're tokenizing in respect to whitespace*/
void Tokenizer::tokenize(const std::string& str){
  std::stringstream ss; 
  std::string token; 
  ss << str << " "; 

  mTokens.clear(); 

  while(ss >> token){
    mTokens.push_back(token); 
  }
  std::cout << mTokens.size() << " tokens available." << std::endl;
}

std::vector<std::string> Tokenizer::tokens(){
  return mTokens; 
}

