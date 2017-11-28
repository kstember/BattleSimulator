
#ifndef EVIL_WARRIOR_H
#define EVIL_WARRIOR_H


#include "Warrior.h"


class Evil_Warrior: public Warrior
{
 public:
  virtual bool is_good() const;

 protected:
  Evil_Warrior(int row, int col, int hit_points);
};


#endif
