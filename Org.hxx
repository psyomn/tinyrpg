#ifndef ORG_HXX
#define ORG_HXX

#include<string>
#include<sstream> 
#include<iostream> 

#include "Ren.hxx"

class Org {
public:
  Org(); 
  ~Org(); 
  std::string getName(); 
  unsigned int getAttack(); 
  unsigned int getDefense();
  unsigned int getStamina(); 
  unsigned int getHitpoints();
  unsigned int getSpeed(); 
  unsigned char getClass(); 
  unsigned char getAlly(); 
  unsigned char getDistortion(); 

  void setAttack(unsigned int); 
  void setDefense(unsigned int);
  void setStamina(unsigned int);
  void setHitpoints(unsigned int);
  void setName(std::string); 
  void setSpeed(unsigned int); 
  void setClass(unsigned char);
  void setAlly(unsigned char);
  void setDistortion(unsigned char); 

  // aug is for augment 
  void augmentAttack(); 
  void augmentDefense(); 
  void augmentStamina(); 
  void augmentClass(); 

  // utilities 
  std::string to_s();
  void rand(); 
private:
  std::string mName; 
  unsigned int mAttack; 
  unsigned int mDefense; 
  unsigned int mStamina; 
  unsigned int mHitpoints; 
  unsigned int mSpeed;
  unsigned char mClass; /** Rogue, Warrior, Whatever */ 
  unsigned char mAlly; /** To classify who's side someone's on */
  unsigned char mDistortion; /** percentage to distort an attack up or down. */

  // functions
  void augment(unsigned int); 
  void augment_special(); 

  static Ren mRen; /** This to be used whenever we need to call upon randomness. Prevents bad seeds. */
};

#endif 

