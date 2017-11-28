
#ifndef GOOD_WARRIOR_H
#define GOOD_WARRIOR_H


#include "Warrior.h"


class Good_Warrior: public Warrior
{
 public:
  virtual bool is_good() const;

 protected:
  Good_Warrior(int row, int col, int hit_points);
};


#endif

