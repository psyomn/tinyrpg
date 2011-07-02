#ifndef ORG_CXX
#define ORG_CXX
#include "Org.hxx"

Org::Org() : 
  mName("Default Name"),
  mAttack(1), 
  mDefense(1), 
  mStamina(1), 
  mHitpoints(1),
  mSpeed(1),
  mClass(0), 
  mAlly(1), // 1 denotes AI, enemy. Human players are special, hence need to be set
  mDistortion(10), // % of distortion on attacks 
  mExperience(0) // starting experience is always zero 
{}

Org::~Org() {} 

std::string Org::getName() const { return mName; }
unsigned int Org::getAttack() const { return mAttack; }
unsigned int Org::getDefense() const { return mDefense; }
unsigned int Org::getStamina() const { return mStamina; }
unsigned int Org::getHitpoints() const { return mHitpoints; }
unsigned int Org::getSpeed() const { return mSpeed; }
unsigned char Org::getClass() const { return mClass; } 
unsigned char Org::getAlly() const { return mAlly; }
unsigned char Org::getDistortion() const { return mDistortion; } 
uint64_t Org::getExperience() const { return mExperience; }

void Org::setAttack(unsigned int x){ mAttack = x; }
void Org::setDefense(unsigned int x){ mDefense = x; }
void Org::setStamina(unsigned int x){ mStamina = x; }
void Org::setHitpoints(unsigned int x){ mHitpoints = x; } 
void Org::setName(std::string n){ mName = n; } 
void Org::setSpeed(unsigned int x){ mSpeed = x; }
void Org::setClass(unsigned char x){ mClass= x; } 
void Org::setAlly(unsigned char x){ mAlly = x; } 
void Org::setDistortion(unsigned char x){ mDistortion = x; } 

unsigned int Org::attack(){
  return getAttack() * ( 100 + ( mRen.getSign() *  mRen.getRange(mDistortion) ) ) / 100; 
}

unsigned int Org::defend(){
  return getDefense() * ( 100 + ( mRen.getSign() * mRen.getRange(mDistortion) ) ) / 100;   
}

void Org::augmentAttack(){ augment(0); }
void Org::augmentDefense(){ augment(1); }
void Org::augmentStamina(){ augment(2); }

void Org::augment(unsigned int choice){
  switch(choice){
    case 0: mAttack += 1; break;
    case 1: mDefense += 1; break; 
    case 2: mStamina += 1; break; 
    default: // wtf just happened 
      break; // to remove warnings from shitty compilers 
  }
}

std::string Org::to_s(){
  std::string tmp; 
  std::stringstream ss; 

  tmp  = "Name    : " + mName; 
  tmp += "\n"; 

  tmp += "Attack  : ";
  ss << mAttack;
  tmp += ss.str(); 
  tmp += "\n"; 
  ss.str(""); 

  tmp += "Defense : ";
  ss << mDefense;
  tmp += ss.str(); 
  tmp += "\n"; 
  ss.str(""); 

  tmp += "Speed   : ";
  ss << mSpeed; 
  tmp += ss.str(); 
  tmp += "\n"; 
  ss.str(""); 

  tmp += "Stam/hit: ";
  ss << mStamina; 
  tmp += ss.str(); 
  tmp += "/";
  ss.str("");
  ss << mHitpoints; 
  tmp += ss.str(); 
  tmp += "\n"; 
  ss.str(""); 

  tmp += "Class   : "; 
  ss << int(mClass); 
  tmp += ss.str(); 
  tmp += "\n";
  ss.str(""); 

  return tmp; 
}

std::string Org::to_ms(){
  std::string tmp; 
  std::stringstream ss; 

  ss << "[" << mHitpoints << "|" << mStamina << "]";

  tmp += mName + " : " + ss.str(); 

  return tmp; 
}

/** Generate random information for an organism object */
void Org::rand() {
  unsigned int tmp; 
  std::string stmp = ""; 

  mRen.set(tmp); 
  mAttack = tmp % 20 + 1; 
  mRen.set(tmp); 
  mDefense = tmp % 20 + 1; 
  mRen.set(tmp); 
  mStamina = tmp % 20 + 1;
  mHitpoints = mStamina; 
  mRen.set(tmp); 
  mSpeed = tmp % 20 + 1;
  stmp = mRen.getName(); 
  mName = stmp; 
  mRen.set(tmp); 
  mDistortion = tmp % 16; 
  mRen.set(tmp); 
  mExperience = tmp % 100;
}

/** Main routine for talking about damage and having jackass quotes whenever an org damages itself 
TODO gaining for experience points should go here.
*/
void Org::receiveDamage(unsigned int dmg, Org& other){
  unsigned int tmp = defend(); 

  if (dmg > tmp) 
    dmg -= tmp; 
  else 
    dmg = 1;

  if (this != &other)
    std::cout << this->mName << " receives " << dmg << " damage from " << other.getName() << std::endl; 
  else 
    std::cout << this->mName << " goes emo and damages himself for " << dmg << " hitpoints!" << std::endl; 

  if (mHitpoints > dmg)
    mHitpoints -= dmg; 
  else {
    mHitpoints = 0;

    if (this != &other){
      std::cout << this->mName << " dies from the hands of " << other.getName() << std::endl; 
    
      // Experience Reward 
      std::cout << other.getName() << " receives " << this->getExperience() << " experience points for the kill!" << std::endl;
      other.receiveExperience(this->getExperience()); 

    }
    else 
      std::cout << this->mName << " does it right in the emo way and kills himself." << std::endl;
  }
}

/** Any internal debuging stuff can go here */
void Org::debug(){
}

/** \return the position of their enemy to attack! 
TODO needs tweaking so people don't hurt themselves, or hurt allies */
size_t Org::examineOrgList(const std::vector<Org*>& list) const {
  size_t pos = 0;  // pos to return with minest stamina 
  size_t count = 0;  // current pos 
  unsigned int minhp = ~0; // set to max for min later 

  for(std::vector<Org*>::const_iterator it = list.begin(); it != list.end(); ++it){
    if (minhp > (*it)->getHitpoints() && (*it)->getHitpoints() != 0 && *it != this ){
      minhp = (*it)->getHitpoints(); 
      pos = count; 
    }
    ++count; 
  }

  return pos; 
}

/** Increment the experience points */
void Org::receiveExperience(uint64_t exp) {
  this->mExperience += exp; 
}

#endif 


