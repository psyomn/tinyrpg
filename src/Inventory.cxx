#include "Inventory.hxx"

/** Default destructor */
Inventory::Inventory(){
}


/** Default destructor - deallocate teh pointers */ 
Inventory::~Inventory(){
  for(std::vector<Item*>::iterator it=mSlot.begin(); it!=mSlot.end(); ++it){
    delete (*it);
  }
}

