#ifndef ELF_H
#define ELF_H

#include "Good_Warrior.h"

/****************************************************************************************
 *
 * CLASS:        Elf
 *
 * PARENT CLASS: Good_Warrior
 *
 * BASE CLASS:   Warrior
 *
 * PURPOSE:      Represents an Elven Warrior on a battlefield. The Elf is a sub class of
 *               "Good_warrior." Is displayed as the letter 'E' on the field when healthy,
 *                and 'e' when injured. Has a row/column for its position
 *                on the battlefield. Will start out with 100% health, but will lose healt\
h
 *                when attacked by opponents.
 *
 * PUBLIC METHODS:
 *
 * - constructor:      Assigns an Elf a position on the battlefield
 *
 * - copy constructor: Dynamically create copy of an Elf warrior
 *
 ****************************************************************************************/
class Elf : public Good_Warrior
{
public:
    Elf (int row, int col);
    virtual Warrior *clone() const;

private:
    int arrows;

    virtual char get_symbol() const;
    virtual double get_range() const;
    virtual void attack(Warrior *opponent);
    virtual int roll_to_hit() const;
    virtual int roll_for_damage() const;
    virtual int needed_to_hit() const;
};


#endif
