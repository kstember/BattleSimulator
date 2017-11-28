#ifndef MAN_H
#define MAN_H

#include "Good_Warrior.h"

/****************************************************************************************
 *
 * CLASS:        Man
 *
 * PARENT CLASS: Good_Warrior
 *
 * BASE CLASS:   Warrior
 *
 * PURPOSE:      Represents an human Warrior on a battlefield. A Man is a sub class of
 *               "Good_warrior." Is displayed as the letter 'M' on the field when healthy,
 *                and 'm' when injured. Has a row/column for its position
 *                on the battlefield. Will start out with 100% health, but will lose healt\
h
 *                when attacked by opponents.
 *
 * PUBLIC METHODS:
 *
 * - constructor: Assigns a Man a position on the battlefield
 *
 * - Clone:       Dynamically create copy of a Man warrior
 *
 ****************************************************************************************/

class Man : public Good_Warrior
{
public:
    Man (int row, int col);
    virtual Warrior *clone() const;

private:
    virtual char get_symbol() const;
    virtual int roll_to_hit() const;
    virtual int roll_for_damage() const;
    virtual int needed_to_hit() const;
};


#endif
