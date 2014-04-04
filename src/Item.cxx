#include "Item.hxx"

/** Constructor, initializes everything to zero for safety. No mutant items please. */
Item::Item():
  mName("Default Item Name"), 
  mAttack(0), 
  mDefense(0), 
  mStamina(0), 
  mSpeed(0){
}

Item::~Item(){
}

unsigned short Item::getAttack() { return mAttack; }
unsigned short Item::getDefense() { return mDefense; }
unsigned short Item::getStamina() { return mStamina; }
unsigned short Item::getSpeed() { return mSpeed; } 

void Item::setAttack(unsigned short x) { mAttack = x; } 
void Item::setDefense(unsigned short x) { mDefense = x; } 
void Item::setStamina(unsigned short x) { mStamina = x; } 
void Item::setSpeed(unsigned short x) { mSpeed = x; }

