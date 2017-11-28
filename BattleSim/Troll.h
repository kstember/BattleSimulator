#ifndef TROLL_H
#define TROLL_H

#include "Evil_Warrior.h"

/****************************************************************************************
 *
 * CLASS:        Troll
 *
 * PARENT CLASS: Evil_Warrior
 *
 * BASE CLASS:   Warrior
 *
 * PURPOSE:      Represents an Troll Warrior on a battlefield. The Troll is a sub class of
 *               "Evil_warrior." Is displayed as the letter 'T' on the field when healthy,
 *                't' when injured. Has a row/column for its position
 *                on the battlefield. Will start out with 100% health, but will lose healt\
h
 *                when attacked by opponents.
 *
 * PUBLIC METHODS:
 *
 * - constructor:      Assigns an Troll a position on the battlefield
 *
 * - copy constructor:  Dynamically create copy of a Troll warrior
 *
 ****************************************************************************************/


class Troll : public Evil_Warrior
{
public:
    Troll(int row, int col);
    virtual Warrior *clone() const;

private:
    virtual char get_symbol() const;
    virtual double get_range() const;
    virtual int roll_to_hit() const;
    virtual int roll_for_damage() const;
    virtual int needed_to_hit() const;
};


#endif
