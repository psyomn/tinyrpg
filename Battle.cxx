#ifndef BATTLE_CXX
#define BATTLE_CXX

#include "Battle.hxx"

Battle::Battle(){

}

/** Deallocate the memory. */
Battle::~Battle(){
  std::vector<Org*>::iterator it; 

  for (it=mOrgList.begin(); it!=mOrgList.end(); ++it) {
    delete (*it); 
  }
}

/** 
TODO this might need to be pointers actually...
*/
void Battle::add(Org* o) {
  mOrgList.push_back(o);
}

std::string Battle::to_s() const {
  std::vector<Org*>::const_iterator it; 
  std::string str = ""; 

  for (it=mOrgList.begin(); it!=mOrgList.end(); ++it) {
    str += (*it)->to_s(); 
    str += "\n-------\n"; 
  }
  str += "\n"; 
  return str; 
}

bool Battle::sortTurnsLogic(Org* o, Org* oo){
  return o->getSpeed() > oo->getSpeed(); 
}

/** Denotes that ready to comence the battle */
void Battle::start(){
  sortTurns(); 
}

void Battle::sortTurns(){
  std::sort (mOrgList.begin(), mOrgList.end(), this->sortTurnsLogic); 
}

#endif 

