#include "Evil_Warrior.h"


Evil_Warrior::Evil_Warrior(int row, int col, int hit_points): Warrior(row, col, hit_points\
)
{
}


bool Evil_Warrior::is_good() const
{
  return false;
}
