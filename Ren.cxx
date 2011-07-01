#ifndef REN_CXX
#define REN_CXX

#include "Ren.hxx" 

char Ren::mCurSeed = 0;

Ren::Ren(){
  if (!mCurSeed){
    generate();  
  } 
}

Ren::~Ren(){

}

void Ren::generate(){
  std::cout << "GEN SEED" << std::endl;
  srand ( time ( 0 ) );  
  mCurSeed = 1; 
}

// TODO 
void Ren::set(double& r){
  r = 42.42; 
}

// TODO 
void Ren::set(float& r){
  r = 42.43; 
}

std::string Ren::getName() {
  switch(rand() % 10){
    case 0: return "Howard"; break;
    case 1: return "Sheldon"; break;
    case 2: return "Raj"; break;
    case 3: return "Leonard"; break;
    case 4: return "George"; break; 
    case 5: return "Astaroth"; break;
    case 6: return "Yog-Sothoth"; break; 
    case 7: return "Cthulhu"; break; 
    case 8: return "Darwin"; break;
    case 9: return "Jeremy"; break; 
    default: return "Somethingsomewherewentterriblywrong"; break; 
  }

  return "Anon";
}

uint64_t Ren::getRange(uint64_t range){
  return rand() % range; 
}

char Ren::getSign() {
  return rand() % 2 == 0 ? -1 : 1; 
}

#endif 

