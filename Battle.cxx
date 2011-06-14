#ifndef BATTLE_CXX
#define BATTLE_CXX

#include "Battle.hxx"

Battle::Battle() : 
  mEnemies(0), 
  mDone(false),
  mWon(false)
{}

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
  
  // Count the amount of enemies added to the battle list
  if(o->getAlly() != 0) 
    mEnemies += 1; 
}

std::string Battle::to_s() const {
  std::vector<Org*>::const_iterator it; 
  std::string str = ""; 

  for (it=mOrgList.begin(); it!=mOrgList.end(); ++it) {
    str += (*it)->to_ms() + "\n"; 
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

/** Status of the battle */
bool Battle::done(){
  return mDone; 
}

void Battle::step(){
  std::vector<Org*>::iterator it; 
  std::string str;
  std::stringstream ss; 
  int choice;

  for (it=mOrgList.begin(); it!=mOrgList.end(); ++it){
    if (!(*it)->getAlly()){
      // Player turn 
      std::cout << "Attack who?"; 
      std::cin >> str;
      ss.str(str); 
      ss >> choice; 
      
      mOrgList[choice]->receiveDamage((*it)->attack()); 
      
    } else {
      // Enemy turn 
    }
  }
}

void Battle::query(){
}

void Battle::debug(){
  std::vector<Org*>::iterator it; 

  for (it=mOrgList.begin(); it!=mOrgList.end(); ++it){
    std::cout << std::hex << *it << std::endl;
  }

  std::cout << std::dec; 
}

size_t Battle::numOrgs() {
  return mOrgList.size(); 
}

#endif 

