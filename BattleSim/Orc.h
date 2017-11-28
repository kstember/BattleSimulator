#ifndef ORC_H
#define ORC_H

#include "Evil_Warrior.h"

/****************************************************************************************
 *
 * CLASS:        Orc
 *
 * PARENT CLASS: Evil_Warrior
 *
 * BASE CLASS:   Warrior
 *
 * PURPOSE:      Represents an Orc Warrior on a battlefield. The Orc is a sub class of
 *               "Evil_warrior." Is displayed as the letter 'O' on the field when healthy,
 *                'o' when injured. Has a row/column for its position
 *                on the battlefield. Will start out with 100% health, but will lose healt\
h
 *                when attacked by opponents.
 *
 * PUBLIC METHODS:
 *
 * - constructor:      Assigns an Orc a position on the battlefield
 *
 * - copy constructor:  Dynamically create copy of an Orc warrior
 *
 ****************************************************************************************/

class Orc : public Evil_Warrior
{
public:
    Orc(int row, int col);
    virtual Warrior *clone() const;

private:
    virtual char get_symbol() const;
    virtual int roll_to_hit() const;
    virtual int roll_for_damage() const;
    virtual int needed_to_hit() const;
};


#endif
