#ifndef ITEM_HXX
#define ITEM_HXX

#include <string> 

/** Class for items, mainly equipable. Maybe something else as well in the future.  */
class Item {
public:
  Item(); 
  ~Item(); 

  void setAttack(unsigned short);
  void setDefense(unsigned short); 
  void setStamina(unsigned short); 
  void setSpeed(unsigned short); 

  unsigned short getAttack(); 
  unsigned short getDefense(); 
  unsigned short getStamina(); 
  unsigned short getSpeed(); 
  
private: 
  std::string mName; /** Name of item */
  unsigned short mAttack;  /** Attack power when equiped*/
  unsigned short mDefense; /** Defense power when equiped*/
  unsigned short mStamina; /** Stamina power when equiped*/
  unsigned short mSpeed;  /** Speed power when equiped*/
};

#endif 

