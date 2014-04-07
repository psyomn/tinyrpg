#include "Battle.hxx"

#include <thread>
#include <chrono>

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
  std::stringstream ss_team; 
  int count=0; 

  dead += "Dead\n"; 

  for (it=mOrgList.begin(); it!=mOrgList.end(); ++it) {
    ss << count; 
    ss_team << int((*it)->getAlly()) ;
    
    if ( (*it)->hitpoints() > 0 ) 
      alive += "[" + ss.str() + "] [team:" 
      + ss_team.str() + "] " 
      + (*it)->to_ms() + "\n"; 
    else
      dead += "[" + ss.str() + "] [team:" 
      + ss_team.str() + "] " 
      + (*it)->to_ms() + "\n";  

    ss.str(""); 
    ss_team.str(""); 
    ++count; 
  }

  dead += "\nAlive\n"; 
  dead += alive;
  return dead; 
}

bool Battle::sortTurnsLogic(Org* o, Org* oo){
  return o->speed() > oo->speed(); 
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
  unsigned int choice;
  bool badnum = true; 

  // TODO this part should probably call up the player menu, or AI of monster
  for (it=mOrgList.begin(); it!=mOrgList.end(); ++it){
    if ((*it)->hitpoints()){
      if (!(*it)->getAlly()){

        std::cout << to_s() << std::endl;
        
        std::cout << "Attack who? "; 
        badnum = true; // reset
        
        // Range checking must be done here 
        while(badnum) {
          std::cin >> str;
          ss << str << " "; 
          choice = 0;
          ss >> choice; 
        
          // if in the valid range, break the loop
          if ( choice < mOrgList.size() ) // note - because unsigned, -1 or whatever will make max, which is greater than size, probably
            badnum = false; 
          else
            std::cout << "You have entered an invalid monster range : " 
              << choice << "/" << mOrgList.size() 
              << "\nAttack who? " << std::endl; 

          ss.str(""); 
        }
        
        mOrgList[choice]->receiveDamage((*it)->attack(), *(*it)); 
        
      } else {
        // Enemy turn / AI  
        std::cout << "Enemy " << (*it)->name() << "\'s turn!" << std::endl; 
        mOrgList[ (*it)->examineOrgList(mOrgList) ]->receiveDamage((*it)->attack(), *(*it)); 
        std::cout << std::endl;

        std::this_thread::sleep_for(std::chrono::seconds(3));
      }
    } // end check if they have any hitpoints left
    // this is where checking to see if a group of specific players has survived 
    
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

