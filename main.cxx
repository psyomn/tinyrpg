#include <iostream>
#include <string> 

#include "Org.hxx"
#include "Battle.hxx"  

int main(){
  Org *op; 
  Org *player; 
  Battle bat; 
  std::string str; 
  int i; 

  std::cout << "Tiny RPG" << std::endl; 
 
  std::cout << "Player name: "; std::cout.flush(); 
  std::cin >> str; 

  player = new Org(); 
  player->setName(str); 

  bat.add(player); 

  for(i=0; i<4; ++i){
    op = new Org();
    op->rand(); 
    bat.add(op); 
  }

  std::cout << bat.to_s() << std::endl; 

  bat.start(); 
  std::cout << "Sorted by speed" << std::endl;
  std::cout << bat.to_s() << std::endl;

  return 0; 
}
