
#include "Troll.h"

/*****
 *
 * PRIVATE DATA MEMBERS:
 *
 * - get_symbol: Provides the symbol for an Elf, 'E' or 'e' depending on health
 *
 * - get_range:  To get the range of an Elven Warrior
 *
 * - roll_to_hit:  To find a random number as the chance that an attack will be succesful
 *
 * - roll_for_damage: To get a random number for amount of damage to deal
 *
 * - needed_to_hit:  To return the number needed to succesfull hit.
 *                   If their hit value is grater than or equal to this,
 *                   the attack will be succesful
 *
 *****/

/*****
 *
 * FUNCTION: Troll constructor
 *
 * PURPOSE:  Initializes the Troll's position, health
 *
 *****/

Troll::Troll(int row, int col) : Evil_Warrior(row, col, 100)
{
}

/*****
 *
 * FUNCTION: get_symbol
 *
 * PURPOSE:  To get the symbol for an Troll Warrior
 *
 * RETURN VALUE: Char - the symbol for the Troll race
 *
 *****/

char Troll::get_symbol() const
{
    return adjust_symbol('T');
}

/*****
 *
 * FUNCTION: get_range
 *
 * PURPOSE:  To get the range of a Troll Warrior
 *
 * RETURN VALUE: Double - Range of a Troll Warrior
 *
 *****/

double Troll::get_range() const
{
    return 2.85; // distance Troll can hit an opponent from
}

/*****
 *
 * FUNCTION: roll_to_hit
 *
 * PURPOSE:  To find a random number as the chance that an attack will be succesful
 *
 * RETURN VALUE: int - random number for chance to land an attack
 *
 *****/

int Troll::roll_to_hit() const
{
    int hit = roll (20,90); // chance of hitting the opponent

    return hit;
}

/*****
 *
 * FUNCTION: roll_for_damage
 *
 * PURPOSE:  To get a random number for amount of damage to deal
 *
 * METHOD:   Finds a random number to be the amount of damage they deal, between two set
 *           values (10 - 30) inclusive
 *
 * RETURN VALUE: The damage that they will produce
 *
*****/

int Troll::roll_for_damage() const
{
    int damage = roll (10, 30); // damage to deal if hit successful

    return damage;
}

/*****
 *
 * FUNCTION: needed_to_hit
 *
 * PURPOSE:  To return the number needed to succesfull hit. If their hit value is grater t\
han
 *           or equal to this, the attack will be succesful
 *
 * RETURN VALUE: int - number needed for succesful hit
 *
 *****/

int Troll::needed_to_hit() const
{
    return 40; // minimum needded for an attack to hit an opponent
}

/*****
 *
 * FUNCTION: clone
 *
 * PURPOSE:  Dynamically create copy of a Troll warrior
 *
 * RETURN VALUE: Troll warrior
 *
 *****/

Warrior *Troll::clone() const
{
    return new Troll(*this);
}


