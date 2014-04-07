#ifndef BATTLEABLE_H
#define BATTLEABLE_H

#include "tinyrpg.h"

class Battleable {
public:
	Battleable(){}
	virtual ~Battleable(){}

  virtual statval attack() = 0;
  virtual statval defend() = 0;
};

#endif /* Battleable */ 
