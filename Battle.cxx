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
  std::string alive = ""; 
  std::string dead = ""; 
  std::stringstream ss; 
  int count=0; 

  dead += "Dead\n"; 

  for (it=mOrgList.begin(); it!=mOrgList.end(); ++it) {
    ss << count; 
    
    if ( (*it)->getHitpoints() > 0 ) 
      alive += "[" + ss.str() + "] " + (*it)->to_ms() + "\n"; 
    else
      dead += "[" + ss.str() + "] " + (*it)->to_ms() + "\n";  

    ss.str(""); 
    ++count; 
  }

  dead += "\nAlive\n"; 
  dead += alive;
  return dead; 
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
  bool badnum = true; 

  for (it=mOrgList.begin(); it!=mOrgList.end(); ++it){
    if (!(*it)->getAlly()){
      // Player turn 
      // TODO this part should probably call up the player menu, or AI of monster
      std::cout << "Attack who?"; 
      badnum = true; // reset
      
      // Range checking must be done here 
      while(badnum) {
        std::cin >> str;
        ss << str << " "; 
        choice = 0;
        ss >> choice; 
      
        // if in the valid range, break the loop
        if ( choice >= 0 && choice < mOrgList.size() ) 
          badnum = false; 
        else
          std::cout << "You have entered an invalid monster range : " 
                    << choice << "/" << mOrgList.size() << std::endl; 

        ss.str(""); 
      }
      
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

