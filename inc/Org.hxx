#ifndef ORG_HXX
#define ORG_HXX

#include<string>
#include<stdint.h>
#include<sstream> 
#include<iostream> 

#include "Ren.hxx"
#include "Item.hxx"
#include "DB.sqlite3.hxx"

/** Character class 
TODO inventory
TODO -> Skills 
*/
class Org {
public:
  Org(); 
  ~Org(); 
  
  // For display 
  std::string getName() const; 
  unsigned int getAttack() const; 
  unsigned int getDefense() const;
  unsigned int getStamina() const; 
  unsigned int getHitpoints() const;
  unsigned int getSpeed() const; 
  unsigned char getClass() const; 
  unsigned char getAlly() const; 
  unsigned char getDistortion() const; 
  uint64_t getExperience() const; 

  // For standard setting 
  void setAttack(unsigned int); 
  void setDefense(unsigned int);
  void setStamina(unsigned int);
  void setHitpoints(unsigned int);
  void setName(std::string); 
  void setSpeed(unsigned int); 
  void setClass(unsigned char);
  void setAlly(unsigned char);
  void setDistortion(unsigned char); 

  // For battle stuffs (modifiers added) 
  unsigned int attack(); 
  unsigned int defend(); 
  void receiveDamage(unsigned int, Org&); 
  void receiveExperience(uint64_t); 
  size_t examineOrgList(const std::vector<Org*>&) const; 

  // Equipment 
  void equipAttack(Item*); 
  void equipDefense(Item*); 
  void equipStamina(Item*); 
  void equipSpeed(Item*); 

  // aug is for augment 
  void augmentAttack(); 
  void augmentDefense(); 
  void augmentStamina(); 
  void augmentClass(); 

  // utilities 
  std::string to_s();
  std::string to_ms(); 
  void rand(); 
  void debug(); 
private:
  std::string mName; 
  unsigned int mAttack;  /** Attack respectively to level of Organism */
  unsigned int mDefense; /** Defense respectively to level of Organism */
  unsigned int mStamina; /** Stamina respectively to level of Organism */
  unsigned int mHitpoints; /** Hitpoints respectively to level of Organism */
  unsigned int mSpeed; /** Speed respectively to level of Organism */

  Item* mEquipAttack; /** For equipment traits */
  Item* mEquipDefense;/** For equipment traits */  
  Item* mEquipStamina;/** For equipment traits */ 
  Item* mEquipSpeed;/** For equipment traits */ 

  unsigned int mBuffAttack;  /** Battle specific attack buff */
  unsigned int mBuffDefense; /** Battle specific defense buff */
  unsigned int mBuffStamina; /** Battle specific speed buff */
  unsigned int mBuffSpeed; /** Battle specific buff */

  unsigned char mClass; /** Rogue, Warrior, Whatever */ 
  unsigned char mAlly; /** To classify who's side someone's on */
  unsigned char mDistortion; /** percentage to distort an attack up or down. */
  uint64_t mExperience; /** Experience gained from battles */

  // functions
  void augment(unsigned int); 
  void augment_special(); 

  Ren mRen; /** This to be used whenever we need to call upon randomness. Prevents bad seeds. */
};

#endif 

