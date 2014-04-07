#include "Item.hxx"
#include "tinyrpg.h"

/** 
 * Constructor, initializes everything to zero.
 */
Item::Item():
  mName("Default Item Name"), 
  mAttack(0), 
  mDefense(0), 
  mStamina(0), 
  mSpeed(0){
}

Item::~Item(){
}

statval Item::attack()  { return mAttack; }
statval Item::defend() { return mDefense; }
statval Item::stamina() { return mStamina; }
statval Item::speed()   { return mSpeed; } 

void Item::attack(statval x)  { mAttack = x; } 
void Item::defense(statval x) { mDefense = x; } 
void Item::stamina(statval x) { mStamina = x; } 
void Item::speed(statval x)   { mSpeed = x; }

