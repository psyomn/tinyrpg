#ifndef REN_CXX
#define REN_CXX

#include "Ren.hxx" 

time_t Ren::mCurSeed = 0; 

Ren::Ren(){
  if (!mCurSeed || mCurSeed + 300 < time(0) )
    generate();  
}

Ren::~Ren(){

}

void Ren::generate(){
  srand ( time ( 0 ) );  
}

// TODO 
void Ren::set(double& r){
  r = 42.42; 
}

// TODO 
void Ren::set(float& r){
  r = 42.43; 
}

#endif 

