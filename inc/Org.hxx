#ifndef ORG_HXX
#define ORG_HXX

#include<string>
#include<stdint.h>
#include<sstream>
#include<iostream>

#include "tinyrpg.h"
#include "Ren.hxx"
#include "Item.hxx"
#include "DB.sqlite3.hxx"
#include "Battleable.hxx"

/** Character class
*/
class Org : public Battleable
{
public:
  Org();
  ~Org();

  // For display
  std::string name() const;
  
	statval attack() const;
  statval defend() const;

  statval stamina() const;
  statval hitpoints() const;
  statval speed() const;

  unsigned char getClass() const;
  unsigned char getAlly() const;
  unsigned char getDistortion() const;
  uint64_t getExperience() const;

  // For standard setting
  void setAttack ( statval );
  void setDefense ( statval );
  void setStamina ( statval );
  void setHitpoints ( statval );
  void setName ( std::string );
  void setSpeed ( statval );
  void setClass ( unsigned char );
  void setAlly ( unsigned char );
  void setDistortion ( unsigned char );

  // For battle stuffs (modifiers added)
  statval attack();
  statval defend();
  void receiveDamage ( statval, Org& );
  void receiveExperience ( uint64_t );
  size_t examineOrgList ( const std::vector<Org*>& ) const;

  // Equipment
  void equipAttack ( Item* );
  void equipDefense ( Item* );
  void equipStamina ( Item* );
  void equipSpeed ( Item* );

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
  statval mAttack;  /** Attack respectively to level of Organism */
  statval mDefense; /** Defense respectively to level of Organism */
  statval mStamina; /** Stamina respectively to level of Organism */
  statval mHitpoints; /** Hitpoints respectively to level of Organism */
  statval mSpeed; /** Speed respectively to level of Organism */

  Item* mEquipAttack; /** For equipment traits */
  Item* mEquipDefense;/** For equipment traits */
  Item* mEquipStamina;/** For equipment traits */
  Item* mEquipSpeed;/** For equipment traits */

  statval mBuffAttack;  /** Battle specific attack buff */
  statval mBuffDefense; /** Battle specific defense buff */
  statval mBuffStamina; /** Battle specific speed buff */
  statval mBuffSpeed; /** Battle specific buff */

  unsigned char mClass; /** Rogue, Warrior, Whatever */
  unsigned char mAlly; /** To classify who's side someone's on */
  unsigned char mDistortion; /** percentage to distort an attack up or down. */
  uint64_t mExperience; /** Experience gained from battles */

  // functions
  void augment ( statval );
  void augment_special();

  Ren mRen; /** This to be used whenever we need to call upon randomness. Prevents bad seeds. */
};

#endif

