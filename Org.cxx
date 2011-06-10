#ifndef ORG_CXX
#define ORG_CXX
#include "Org.hxx"

Org::Org() : 
  mName("Default Name"),
  mAttack(1), 
  mDefense(1), 
  mStamina(1), 
  mHitpoints(1),
  mSpeed(1)
{}

Org::~Org() {} 

std::string Org::getName() { return mName; }
unsigned int Org::getAttack() { return mAttack; }
unsigned int Org::getDefense() { return mDefense; }
unsigned int Org::getStamina() { return mStamina; }
unsigned int Org::getHitpoints() { return mHitpoints; }
unsigned int Org::getSpeed() { return mSpeed; }

void Org::setAttack(unsigned int x){ mAttack = x; }
void Org::setDefense(unsigned int x){ mDefense = x; }
void Org::setStamina(unsigned int x){ mStamina = x; }
void Org::setHitpoints(unsigned int x){ mHitpoints = x; } 
void Org::setName(std::string n){ mName = n; } 
void Org::setSpeed(unsigned int x){ mSpeed = x; }

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

  return tmp; 
}

#endif 


