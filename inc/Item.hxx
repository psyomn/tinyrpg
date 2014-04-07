#ifndef ITEM_HXX
#define ITEM_HXX

#include "tinyrpg.h"

#include <string> 

/** Class for items, mainly equipable. Maybe something else as well in the future.  */
class Item {
public:
  Item(); 
  ~Item(); 

  void attack(statval);
  void defense(statval); 
  void stamina(statval); 
  void speed(statval); 

  statval attack(); 
  statval defend(); 
  statval stamina(); 
  statval speed(); 
  
private: 
  std::string mName; /** Name of item */
  statval mAttack;  /** Attack power when equiped*/
  statval mDefense; /** Defense power when equiped*/
  statval mStamina; /** Stamina power when equiped*/
  statval mSpeed;  /** Speed power when equiped*/
};

#endif 

