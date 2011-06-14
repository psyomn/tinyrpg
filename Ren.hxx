#ifndef REN_HXX
#define REN_HXX

#include <cstdlib>
#include <stdint.h>
#include <ctime> 
#include <limits> 
#include <iostream> 
#include <string> 
#include <vector>

/** Simple random engine. */
class Ren {
public: 
  Ren(); 
  ~Ren();
  template <typename T> 
  void set(T& x){
    x = rand() % std::numeric_limits<T>::max();  
  }
  void set(double&); 
  void set(float&); 
  static std::string getName(); 

  // TODO 
  static uint64_t getRange(uint64_t); 
  static char getSign(); 

private: 
  static time_t mCurSeed; 
  //functions 
  void generate();

};

#endif 

