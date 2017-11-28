#include "Elf.h"

/*****
 *
 * PRIVATE DATA MEMBERS:
 *
 * - arrows: Integer value representing number of arrows each elf has left
 *
 * - get_symbol: Provides the symbol for an Elf, 'E' or 'e' depending on health
 *
 * - get_range:  To get the range of an Elven Warrior
 *
 * - attack:     Allows an Elven warrior to attack an opponent
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
 * FUNCTION: Elf constructor
 *
 * PURPOSE:  Initializes the Elf's position, health, and arrow amount
 *
 *****/

Elf::Elf(int row, int col): Good_Warrior(row, col, 15)
{
    arrows = 15;
}

/*****
 *
 * FUNCTION: get_symbol
 *
 * PURPOSE:  To get the symbol for an Elven Warrior
 *
 * RETURN VALUE: Char - the symbol for the Elven race
 *
 *
 *****/

char Elf::get_symbol() const
{
    return adjust_symbol('E');
}

/*****
 *
 * FUNCTION: get_range
 *
 * PURPOSE:  To get the range of an Elven Warrior
 *
 * METHOD:   Checks amount of arrows left in the Elf's quiver. If there is any left they w\
ill
 *            have a greater range (20) than if they use their sword (1.5)
 *
 * RETURN VALUE: Range of an Elven Warrior
 *
 *****/

double Elf::get_range() const
{
    double range = 1.5;  // distance elf can hit opponent from

    if (arrows > 0)
        range = 20;
    return range;
}

/*****
 *
 * FUNCTION:  attack
 *
 * PURPOSE:   Allows an Elven warrior to attack an opponent
 *
 * INPUT:     Pointer to a warrior on the field
 *
 * MEHTOD:    Takes a psuedo random number as the amount of damage they will inflict, and
 *             a psuedo random number for their chance to succesfully land an attack.
 *             Reduces the number of arrows in their quiver
 *
 *****/
void Elf::attack(Warrior *opponent)
{
    int damage; // damage to potentially deal
    int hit;    // chance of hitting opponent

    damage = roll_for_damage();
    hit = roll_to_hit();

    opponent->receive_attack(hit, damage);
    if (arrows > 0)
        arrows--;
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

int Elf::roll_to_hit() const
{
    int hit = roll (20, 100); // chance of hitting opponent

    return hit;
}

/*****
 *
 * FUNCTION: roll_for_damage
 *
 * PURPOSE:  To get a random number for amount of damage to deal
 *
 * METHOD:   Checks the amount of arrows left in the Elf's quiver, as their archery will
 *           produce more damage(1-20) than their sword skills will (1-5)
 *
 * RETURN VALUE: The damage that they will produce
 *
 *****/

int Elf::roll_for_damage() const
{
    int damage; // damage to deal if hit successful. More dealt with arrow than sword

    if (arrows > 0)
        damage = roll (1, 20);
    else
        damage = roll (1,5);

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

int Elf::needed_to_hit() const
{
    return 60;  // minimum needed for an attack to hit opponent
}

/*****
 *
 * FUNCTION: clone
 *
 * PURPOSE:  Dynamically create copy of an Elf warrior
 *
 * RETURN VALUE: Elf Warrior
 *
 *****/

Warrior *Elf::clone() const
{
    return new Elf(*this);
}



