#ifndef BATTLE_HXX
#define BATTLE_HXX

// libs
#include<vector> 
#include<string>
#include<algorithm>
#include<iostream> 
#include<sstream> 
#include<ctime> 

// others 
#include "Org.hxx"

/** Should take care of battles, turn coordination and what not. Provides the interface to 
the battle menu as well. */
class Battle {
public:
  Battle();
  ~Battle(); 
  
  void add(Org*); 

  // Very battle specific 
  void start(); 
  void step(); 
  void query(); 
  bool done(); 

  // utils
  std::string to_s() const;
  void debug();
  size_t numOrgs(); 
private: 
  std::vector<Org*> mOrgList;  
  size_t mEnemies; 
  bool mDone; 
  bool mWon; 
  // func 
  static bool sortTurnsLogic(Org*,Org*);
  void sortTurns(); 
};

#endif 

