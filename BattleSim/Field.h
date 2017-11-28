#ifndef FIELD_H
#define FIELD_H


class Warrior;

#include <iostream>
#include "Warrior.h"

using namespace std;


#define MAX_WARRIORS 1000     // maximum number of warriors per field


/*****
 *
 *  CLASS: Field
 *
 *  PURPOSE: Represents a 2D battlefield containing good and evil warriors at
 *           various row/column coordinates.
 *
 *  PUBLIC METHODS:
 *
 *  - constructor: Initializes the field to empty.
 *
 *  - load: Loads an initial battlefield configuration from the named file, or
 *          returns false if the file is invalid.
 *
 *  - evolve: Updates the field by giving each warrior a turn to attack or
 *            move.
 *
 *  - get_num_warriors: Counts the number of living good and evil warriors.
 *
 *  - write: Displays a 2D representation of the field to the given output
 *           stream.
 *
 *  - find_nearest_opponent: For a given warrior, returns the nearest living
 *                           enemy warrior (or NULL if no such warrior).  The
 *                           distance to the enemy warrior is also output.
 *
 *  - collision: For a given warrior, determines if the warrior is at at the
 *               same row/column coordinates as another living warrior (a
 *               "collision", resulting from an illegal move).
 *
 *  - copy constructor: A deep copy is preformed to prevent destruction of any data
 *
 *  - Assignment operator:  provides better method of assignment to prevent data loss
 *
  *****/

class Field
{
 public:
  Field();
  ~Field();
  Field (const Field&);

  bool load(const char filename[]);
  void evolve();
  void get_num_warriors(int &good, int &evil) const;
  void write(ostream &out) const;
  Warrior *find_nearest_opponent(const Warrior *for_warrior, double &distance) const;
  bool collision(const Warrior *for_warrior) const;
  Field& operator= (const Field&);

 private:
  void MakeNewWarrior(const char ch, int& row, int& col);
  double distance_between(const Warrior *w1, const Warrior *w2) const;
  Warrior *warrior[MAX_WARRIORS];
  int fill;
};

ostream& operator << (ostream&, const Field&);

#endif

