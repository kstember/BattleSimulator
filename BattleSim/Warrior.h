#ifndef WARRIOR_H
#define WARRIOR_H


class Field;

#include "Field.h"


/*****
 *
 *  CLASS: Warrior
 *
 *  PURPOSE: Represents a warrior on a battlefield.  A warrior is either good
 *           or evil, and has a symbol to represent his race and current health
 *           status.  A warrior has a row/column position on the field.  A
 *           warrior starts out healthy, but may become wounded or die due to
 *           attacks from other warriors.
 *
 *  PUBLIC METHODS:
 *
 *  - constructor: Initializes a healthy warrior and assigns him a position.
 *
 *  - is_good: Determines if this warrior is a soldier in the good or evil
 *             army.
 *
 *  - get_symbol: Gets a representative symbol for this soldier based on his
 *                race and current health status (e.g. 'M' for an unwounded
 *                man, 'm' for a wounded man, or 'x' for dead).  A wounded
 *                warrior's symbol is lower case.  A warrior is "wounded" if
 *                his health is at or below 50%.
 *
 *  - get_position: Gets the row/column position of this warrior on the
 *                  field.
 *
 *  - is_alive: Determines if this warrior has been killed or not!
 *
 *  - take_turn: Tells the warrior to either attack or move, based on the
 *               current battlefield situation.  Dead warriors ignore this
 *               message.
 *
 *****/

class Warrior
{
public:
   Warrior(int row, int col, int initial_hit_points);

    virtual bool is_good() const = 0;
    virtual char get_symbol() const = 0;
    void get_position(int &row, int &col) const;
    bool is_alive() const;
    void take_turn(Field &field);
    void receive_attack(int hit_roll, int damage);
    virtual Warrior *clone() const = 0;

protected:
    void move_closer(Field &field);
    char adjust_symbol(char symbol) const;
    virtual  double get_range() const;
    int roll(int min, int max) const;
    virtual void attack(Warrior *opponent);
    virtual int roll_to_hit() const = 0;
    virtual int roll_for_damage() const = 0;
    virtual int needed_to_hit() const = 0;

private:
    int row;
    int col;
    int initial_hit_points;
    int hit_points;
};


#endif

