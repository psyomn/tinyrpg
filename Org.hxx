#ifndef ORG_HXX
#define ORG_HXX

#include<string>
#include<sstream> 
#include<iostream> 

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

  void setAttack(unsigned int); 
  void setDefense(unsigned int);
  void setStamina(unsigned int);
  void setHitpoints(unsigned int);
  void setName(std::string); 
  void setSpeed(unsigned int); 

  // aug is for augment 
  void augmentAttack(); 
  void augmentDefense(); 
  void augmentStamina(); 

  // utilities 
  std::string to_s();
private:
  std::string mName; 
  unsigned int mAttack; 
  unsigned int mDefense; 
  unsigned int mStamina; 
  unsigned int mHitpoints; 
  unsigned int mSpeed;

  // functions
  void augment(unsigned int); 
};

#endif 

