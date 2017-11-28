#include "Man.h"

/*****
 *
 * PRIVATE DATA MEMBERS:
 *
 * - get_symbol: Provides the symbol for a Man, 'M' or 'm' depending on health
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
 * FUNCTION: Man constructor
 *
 * PURPOSE:  Initializes the Man's position, health
 *
 *****/

Man::Man(int row, int col): Good_Warrior(row, col, 20)
{
}

/*****
 *
 * FUNCTION: get_symbol
 *
 * PURPOSE:  To get the symbol for an Human Warrior
 *
 * RETURN VALUE: Char - the symbol for the Human race
 *
 *****/

char Man::get_symbol() const
{
    return adjust_symbol('M');
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

int Man::roll_to_hit() const
{
    int hit = roll (1, 100);  // chance of hitting opponent

    return hit;
}

/*****
 *
 * FUNCTION: roll_for_damage
 *
 * PURPOSE:  To get a random number for amount of damage to deal
 *
 * METHOD:   Finds a random number to be the amount of damage they deal, between two set
 *           values (1-20) inclusive
 *
 * RETURN VALUE: The damage that they will produce
 *
 *****/

int Man::roll_for_damage() const
{
    int damage = roll (1, 20); // damage to deal if hit successful

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

int Man::needed_to_hit() const
{
    return 50; // minimum needed for an attack to hit opponent
}

/*****
 *
 * FUNCTION: clone
 *
 * PURPOSE:  Dynamically copy of Man Warrior
 *
 * RETURN VALUE: Man Warrior
 *
 *****/

Warrior *Man::clone() const
{
    return new Man(*this);
}

