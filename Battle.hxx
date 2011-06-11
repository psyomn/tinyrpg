#ifndef BATTLE_HXX
#define BATTLE_HXX

// libs
#include<vector> 
#include<string>
#include<algorithm>

// others 
#include "Org.hxx"

/** Should take care of battles, turn coordination and what not. */
class Battle {
public:
  Battle();
  ~Battle(); 
  
  void add(Org*); 

  void start(); 

  // utils
  std::string to_s() const;
private: 
  std::vector<Org*> mOrgList;  

  // func 
  static bool sortTurnsLogic(Org*,Org*);
  void sortTurns(); 
};

#endif 

