#ifndef INVENTORY_HXX
#define INVENTORY_HXX

#include<iostream> 
#include<vector> 

#include "Item.hxx"

/** Class that will take care of possibly inventories of players or 
enemies */
class Inventory {
public: 
  Inventory(); 
  ~Inventory(); 
private: 
  std::vector<Item*> mSlot; /** Slots for the inventory */
};

#endif 

