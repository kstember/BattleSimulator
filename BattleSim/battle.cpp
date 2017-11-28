/*****
 *
 *  PROGRAM: battle (Battlefield: Middle-Earth!)
 *
 *  PURPOSE: A real-time battlefield simulator featuring armies of elves and
 *           men vs. orcs and trolls.
 *
 *  SYNOPSIS: battle (-t | -r) "field filename"
 *
 *  OPTIONS: Choose exactly one of:
 *
 *                -t     "test mode": battle outcome for a given input field
 *                       file is always the same (non-random).
 *
 *                -r     "random mode": each simulation of a given battle is
 *                       different!
 *
 *  FIELD INPUT FILE: A text file consisting of newline characters, spaces, and
 *                    the following:
 *
 *                         E = elf   (good)
 *                         M = man   (good)
 *                         O = orc   (evil)
 *                         T = troll (evil)
 *
 *                    See the assignment spec. for a detailed description of
 *                    each race.
 *
 *                    The row/column position of each warrior, as specified in
 *                    the file, determines the starting position of each on the
 *                    simulated field.
 *
 *  METHOD: - validate the command line arguments
 *          - read and validate the initial battlefield configuration
 *          - seed the random number generator (as per the options above)
 *          - fight!
 *
 *****/


#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>

// #define __USE_BSD

#include <unistd.h>
#include "Field.h"

using namespace std;


#define PAUSE_TIME 300000     // 0.3 seconds between field snapshots


bool check_option(const char arg[], bool &test);
void fight_battle(Field &field);
void display_status(const Field &field);


int main(int argc, char *argv[])
{
  bool test;       // true = -t option, false = -r option
  Field field;

  if (argc != 3 || !check_option(argv[1], test))
    cout << "usage: " << argv[0] << " (-t | -r) \"field filename\"" << endl;
  else if (!field.load(argv[2]))
    cout << "invalid field file" << endl;
  else
    {
      srand(test ? 1 : static_cast<unsigned int>(time(NULL)));
      fight_battle(field);
    }

  return 0;
}


/*****
 *
 *  FUNCTION: check_option
 *
 *  PURPOSE: Validates the command line option, and determines if the user has
 *           selected test or random mode.
 *
 *  INPUT: arg - the command line argument to check
 *
 *  OUTPUT: test - true = test mode selected, false = random mode selected,
 *                 undefined otherwise
 *
 *  RETURN VALUE: specified - true if and only if option is valid
 *
 *****/

bool check_option(const char arg[], bool &test)
{
  bool specified = true;

  if (strncmp(arg, "-t", 2) == 0)
    test = true;
  else if (strncmp(arg, "-r", 2) == 0)
    test = false;
  else
    specified = false;

  return specified;
}


/*****
 *
 *  FUNCTION: fight_battle
 *
 *  PURPOSE: Animates the evolution of the battle.  Eventually, this function
 *           determines the winning army.
 *
 *  INPUT: field - the initial battlefield configuration
 *
 *  OUTPUT: field - only warriors from the victorious army are left alive
 *
 *  METHOD: As the battle evolves, a snapshot of the field is displayed
 *          iteratively.  Since the screen is cleared before each snapshot, and
 *          each is only visible for a short time, the battle will appear to
 *          be animated.  The sentinel loop exits once either the good or
 *          evil count falls to zero.
 *
 *****/

void fight_battle(Field &field)
{
  int good;     // number of living good warriors
  int evil;     // number of living evil warriors

  display_status(field);
  field.get_num_warriors(good, evil);

  while (good > 0 && evil > 0)
  {
    field.evolve();
    display_status(field);
    field.get_num_warriors(good, evil);
  }

  cout << endl;

  if (good == evil)
    cout << "Mutual annihilation.";
  else if (good > 0)
    cout << "Good triumphs!";
  else
    cout << "Evil conquers!";

  cout << endl << endl;
}


/*****
 *
 *  FUNCTION: display_status
 *
 *  PURPOSE: Briefly displays a current snapshot of the field.
 *
 *  INPUT: field - the field to display
 *
 *****/

void display_status(const Field &field)
{
  system("clear");
  cout << field;
  usleep(PAUSE_TIME);
}




