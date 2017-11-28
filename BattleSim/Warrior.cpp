#include <cstdlib>
#include <cctype>
#include <stdlib.h>
#include "Warrior.h"

/***********************************************************************************
 * Private Data members
 *
 * - row: row warrior is located in
 *
 * - col: column warrior is located in
 *
 * - initial_hit_points: Health warrior starts with
 *
 * - hit_points: Current health of warrior
 **********************************************************************************/



/*****
 *
 * FUNCTION: Warrior Constructor
 *
 * PURPOSE:  initalize a warrior's position and health
 *
 *****/

Warrior::Warrior(int r, int c, int i):
    row(r),
    col(c),
    initial_hit_points(i)
{
    hit_points = initial_hit_points;
}

void Warrior::get_position(int &r, int &c) const
{
  r = row;
  c = col;
}

bool Warrior::is_alive() const
{
    bool alive = false;

    if (hit_points > 0)
 alive = true;

    return alive;
}

void Warrior::take_turn(Field &field)
{
  Warrior *opponent;
  double distance;

  if (is_alive())
  {
    opponent = field.find_nearest_opponent(this, distance);

    if (opponent != NULL)
    {
      if (distance <= get_range())
          attack(opponent);
      else
        move_closer(field);
    }
  }
}

/*****
 *
 * FUNCTION: receive_attack
 *
 * PURPOSE:  For a warrior under attack to recive an attack from an oppenent and
 *           take damage if needed
 *
 * INPUT:    int - hit_roll, What attacker rolled for chance of hit
 *           int - damage,   Amount of damage to be dealt if hit_roll is high enough
 *
 * MEHTOD:   Compares opponents hit_roll to what is needed for attack to be successful.
 *           If it is, takes damage off of its health
 *
 *****/

void Warrior::receive_attack(int hit_roll, int damage)
{
  if (hit_roll >= needed_to_hit())
      hit_points -= damage;
}

// attempts to move warrior in 9 different ways:
//
//   - row change: -1, 0, or +1
//   - col change: -1, 0, or +1
//
// and then moves warrior in the way that takes it closest to an opponent:

void Warrior::move_closer(Field &field)
{
  int delta_row;
  int delta_col;
  double distance;
  bool first_try = true;
  double min_distance;
  int best_delta_row;
  int best_delta_col;

  for (delta_row = -1; delta_row <= 1; delta_row++)
    for (delta_col = -1; delta_col <= 1; delta_col++)
      {
        row += delta_row;
        col += delta_col;

        if (!field.collision(this))
          {
            field.find_nearest_opponent(this, distance);

            if (first_try || distance < min_distance)
              {
                min_distance = distance;
                best_delta_row = delta_row;
                best_delta_col = delta_col;
                first_try = false;
              }
          }

        row -= delta_row;
        col -= delta_col;
      }

  row += best_delta_row;
  col += best_delta_col;
}


char Warrior::adjust_symbol(char symbol) const
{
  char adjusted;

  if (hit_points <= initial_hit_points / 2)
    adjusted = static_cast<char> (tolower(symbol));
  else
    adjusted = symbol;

  return adjusted;
}

/*****
 *
 * FUNCTION: get_range
 *
 * PURPOSE:  To get the range of a warrior
 *
 * RETURN VALUE: 1.5, base range of a warrior
 *
 *****/

double Warrior::get_range() const
{
    return 1.5;
}

/*****
 *
 * FUNCTION: roll
 *
 * PURPOSE:  To find a psuedo random number between two values
 *
 * INPUT:    int - min: bottom range of number to find
 *           int - max: maxium range of number to find
 *
 * RETURN VALUE: int - random number found
 *
 *****/

int Warrior::roll(int min, int max) const
{
    int random; // random number found within range

    random = rand() % (max - min + 1) + min;

    return random;
}

/*****
 *
 * FUNCTION: attack
 *
 * PURPOSE:  To attack an opponent
 *
 * INPUT:    Warrior - opponent: Pointer to opponent being attacked
 *
 * MEHTOD:  Rolls for random values for damage and hit.
 *          The attacker then gives this information the atackee
 *
 *****/

void Warrior::attack(Warrior *opponent)
{
    int damage; // Damage is what may be dealt.
    int hit;    // Hit is the number which must be a certain value for attack to be succes\
sful

    damage = roll_for_damage();
    hit = roll_to_hit();

    opponent->receive_attack(hit, damage);
}



