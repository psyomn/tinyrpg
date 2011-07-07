#ifndef INTERFACE_CXX
#define INTERFACE_CXX

#include "Interface.hxx" 
#include "Org.hxx"
#include "Battle.hxx"  

Interface::Interface(){
}

Interface::~Interface(){
}

void Interface::simple(){
  Org *op; 
  Org *player; 
  Battle bat; 
  std::string str; 
  int i; 

  std::cout << "Tiny RPG" << std::endl; 
 
  std::cout << "Player name: ";
  std::cin >> str; 

  player = new Org(); 
  player->rand(); 
  player->setName(str); 
  player->setAlly(0); 

  std::cout << "Here are your stats : " << std::endl; 
  std::cout << player->to_s() << std::endl; 

  bat.add(player); 

  for(i=0; i<4; ++i){
    op = new Org();
    op->rand(); 
    bat.add(op); 
  }

  bat.start(); 

  while(!bat.done()){
    std::cout << bat.to_s() << std::endl;
    bat.step(); 
  }
}

#endif 

