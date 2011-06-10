#ifndef REN_HXX
#define REN_HXX

#include <cstdlib>
#include <ctime> 
#include <limits> 

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

  // TODO 
  void setRange(); 

private: 
  static time_t mCurSeed; 

  //functions 
  void generate();

};

#endif 

