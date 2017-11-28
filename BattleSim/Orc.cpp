#include "Orc.h"

/*****
 *
 * PRIVATE DATA MEMBERS:
 *
 * - get_symbol: Provides the symbol for an Orc, 'O' or 'o' depending on health
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
 * FUNCTION: Orc constructor
 *
 * PURPOSE:  Initializes the Orc's position, health
 *
 *****/

Orc::Orc(int row, int col) : Evil_Warrior(row, col, 15)
{
}

/*****
 *
 * FUNCTION: get_symbol
 *
 * PURPOSE:  To get the symbol for an Orc Warrior
 *
 * RETURN VALUE: Char - the symbol for the Orc race
 *
 *****/

char Orc::get_symbol() const
{
    return adjust_symbol('O');
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

int Orc::roll_to_hit() const
{
    int hit = roll (1,100); // chance of hitting opponent

    return hit;
}

/*****
 *
 * FUNCTION: roll_for_damage
 *
 * PURPOSE:  To get a random number for amount of damage to deal
 *
 * METHOD:   Finds a random number to be the amount of damage they deal, between two set
 *           values (3-15) inclusive
 *
 * RETURN VALUE: The damage that they will produce
 *
 *****/

int Orc::roll_for_damage() const
{
    int damage = roll (3,15); // damage to deal if hit successful

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
 *
 * RETURN VALUE: int - number needed for succesful hit
 *
 *****/

int Orc::needed_to_hit() const
{
    return 50; // minimum needed for an attack to hit an opponent
}

/*****
 *
 * FUNCTION: clone
 *
 * PURPOSE:  Dynamically create copy of an Orc warrior
 *
 * RETURN VALUE: Orc Warrior
 *
 *****/

Warrior *Orc::clone() const
{
    return new Orc(*this);
}

