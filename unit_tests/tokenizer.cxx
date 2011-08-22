#include <iostream>
#include <string> 
using namespace std;
 
#include "../Tokenizer.hxx"

int main(){
  string phrase = "the quick brown fox jumps over the lazy dog." ; 
  Tokenizer tok; 

  tok.tokenize(phrase); 

  return 0; 
}
