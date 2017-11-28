/*****
 *  Name:        Kaleb Stemberger
 *
 *  Email:       kstem066@mtroyal.ca
 *
 *  Course:      Comp1633
 *
 *  Instructor:  Paul Pospisil
 *
 *  Assignment:  5
 *
 *  Source File: battle.cpp
 *
 *  Due Date:    April 11, 2014
 *****/

#include <fstream>
#include <cmath>
#include "Field.h"
#include "Troll.h"
#include "Orc.h"
#include "Man.h"
#include "Elf.h"

using namespace std;

#define VIEW_ROWS 24      // dimensions of battlefield view
#define VIEW_COLS 80

/*****
 *
 *  PRIVATE DATA MEMBERS:
 *
 *  - warrior: A partially filled array of Warrior objects, one for each
 *             living or dead warrior on the field.
 *
 *  - fill: The total number of living and dead warriors on the field.
 *
 *****/


/*****
 *
 *  FUNCTION: Field constructor
 *
 *  PURPOSE: Initializes the field to empty.
 *
 *****/

Field::Field(): fill(0)
{
}

/*****
 *
 *  FUNCTION: load
 *
 *  PURPOSE: Loads an initial battlefield configuration from the named file, or
 *           returns false if the file is invalid.
 *
 *  INPUT: filename - the name of the file from which to read the configuration
 *
 *  RETURN VALUE: success - true if and only if a valid field file has been
 *                          loaded
 *
 *  METHOD: For each file input character (except space or newline), add a
 *          warrior of the given race ('M' for man, 'E' for elf, etc.) to the
 *          field at that row/column position, where each line in the file
 *          represents a row of columns.  Stop at EOF or when an invalid
 *          character (anything other than space, newline, 'M', 'E', 'O' or
 *          'T') is encountered.
 *
 *****/

bool Field::load(const char filename[])
{
    bool success = false;        // true when valid file is completely read
    ifstream file;               // file being read in
    int row = 0;                 // the current row being filled
    int col = 0;                 // the current column being filled
    char ch;                     // the current character being read to fill it
    bool bad_char = false;       // true when an invalid character has been read

  
    file.open(filename);
  
    if (!file.fail())
    {
      
        success = true;
        while (!file.eof() && !bad_char)
        {
            
            file.get(ch);
            if (ch == ' ')
                col++;
            else if (ch == '\n')
            {

                row++;
                col = 0;
            }
            else if ( (ch == 'O') || (ch == 'T') || (ch == 'M') || (ch == 'E' ) )
                MakeNewWarrior(ch, row, col);
            else
                {
                cout <<"here"<<endl;
                
                bad_char = true;
                success = false;
                }
            }
        }
    return success;
}

/*****
 *
 *  FUNCTION: MakeNewWarrior
 *
 *  PURPOSE:  To dynamically create new classes of warriors from specified type
 *
 *  INPUT:    Warrior character symbol representing race; 'O' for Orc, 'T' for Troll,
 *            'M' for Man, and 'E' for Elf. Two integer values representing row
 *            and column position of the given warrior.
 *
 *  RETURN VALUE: Updated row and column by reference
 *
 *  METHOD:       Checks what the character symbol is and initializes the corresponding
 *                race
 *
 *****/

void Field::MakeNewWarrior(const char ch, int& row, int& col)
{
    if (ch == 'O')
        warrior[fill] = new Orc(row, col);

    else if (ch == 'T')
        warrior[fill] = new Troll(row, col);

    else if (ch == 'E')
        warrior[fill] = new Elf(row, col);

    else
        warrior[fill] = new Man(row, col);

    fill++;
    col++;

}

/*****
 *
 *  FUNCTION: evolve
 *
 *  PURPOSE: Updates the field by giving each warrior a turn to attack or
 *           move.
 *
 *  METHOD: For each warrior pointed to by the "warrior" array, tell it to
 *          take a turn.
 *
 *  NOTE: The turn order is determined by the order of the array elements,
 *        which is determined by the order warriors are loaded from the
 *        initial battlefield file.  Although this is slighty unfair, it is
 *        a sufficient method for now.
 *
 *****/

void Field::evolve()
{
    int index = 0;

    while (index < fill)
    {
        warrior[index]->take_turn(*this);
        index++;
    }
}


/*****
 *
 *  FUNCTION: get_num_warriors
 *
*  PURPOSE: Counts the number of living good and evil warriors.
 *
 *  OUTPUT: good - the number of living good warriors
 *          evil - the number of living evil warriors
 *
 *****/

void Field::get_num_warriors(int &good, int &evil) const
{
    int index = 0;

    good = 0;                                   \
    evil = 0;

    if (fill > 0)
    {
        while (index < fill)
        {
            if ( warrior[index]->is_good() &&  warrior[index]->is_alive() )
                good++;
            else if ( warrior[index]->is_alive() )
                evil++;
            index++;
        }
    }
}

/*****
 *
 *  FUNCTION: write
 *
 *  PURPOSE: Displays a 2D representation of the field to the given output
 *           stream.
 *
 *  INPUT: out - the stream to which to write the field representation
 *
 *  OUTPUT out - the stream position has been updated
 *
 *  METHOD: - create a 2D "view" array, initialized to blank
 *          - for each living warrior on the field, add his symbol to the view
 *            at his given row/column coordinates
 *          - write the view array to the stream, one row ("line") at a time
 *
 *  NOTE: The battlefield has no borders!  Warriors can still be on the field
 *        but outside of the view frame.  In this case, they are still
 *        present but are invisible unless they move back into view.
 *
 *****/

void Field::write(ostream &out) const
{
  char view[VIEW_ROWS][VIEW_COLS];
  int row;
  int col;
  int index;     // index of each warrior

  for (row = 0; row < VIEW_ROWS; row++)
    for (col = 0; col < VIEW_COLS; col++)
      view[row][col] = ' ';

  for (index = 0; index < fill; index++)
    if (warrior[index]->is_alive())
      {
        warrior[index]->get_position(row, col);

        if (row >= 0 && row < VIEW_ROWS && col >= 0 && col < VIEW_COLS)
          view[row][col] = warrior[index]->get_symbol();
      }

  for (row = 0; row < VIEW_ROWS; row++)
    {
      for (col = 0; col < VIEW_COLS; col++)
        out << view[row][col];

      out << endl;
    }
}


/*****
 *
 *  FUNCTION: find_nearest_opponent
 *
 *  PURPOSE: For a given warrior, returns the nearest living enemy warrior (or
 *           NULL if no such warrior).  The distance to the enemy warrior is
 *           also output.
 *
 *  INPUT: for_warrior - find the nearest opponent for this warrior
 *
 *  OUTPUT: distance - if opponent found, this is the distance between them
 *
 *  RETURN VALUE: opponent - the nearest opponent, or NULL if no such warrior
 *
 *  METHOD: for each living enemy warrior on field
 *               compute distance
 *               if closest so far then best candidate so far
 *
 *****/

Warrior *Field::find_nearest_opponent(const Warrior *for_warrior,
                                      double &distance) const
{
  Warrior *opponent = NULL;
  int index;                    // index of each warrior to consider
  double opponent_distance;

  for (index = 0; index < fill; index++)
    if (warrior[index]->is_alive() &&
        warrior[index]->is_good() != for_warrior->is_good())
      {
        opponent_distance = distance_between(for_warrior, warrior[index]);

        if (opponent == NULL || opponent_distance < distance)
          {
            opponent = warrior[index];
            distance = opponent_distance;
          }
      }

  return opponent;
}


/*****
 *
 *  FUNCTION: collision
 *
 *  PURPOSE: For a given warrior, determines if the warrior is at at the same
 *           row/column coordinates as another living warrior (a "collision",
 *           resulting from an illegal move).
 *
 *  INPUT: for_warrior - ask if this warrior has collided with any others
 *
 *  RETURN VALUE: collides - true if and only if warrior's row/column matches
 *                           another's
 *
 *  METHOD: for each other living warrior
 *               if row/col positions match then collision
 *
 *****/

bool Field::collision(const Warrior *for_warrior) const
{
  bool collides = false;
  int row;                   // row/column of for_warrior
  int col;
  int index;                 // index of other warrior to check
  int curr_row;              // row/column of other warrior
  int curr_col;

  for_warrior->get_position(row, col);

  for (index = 0; !collides && index < fill; index++)
    if (warrior[index] != for_warrior && warrior[index]->is_alive())
      {
        warrior[index]->get_position(curr_row, curr_col);
        collides = ((row == curr_row) && (col == curr_col));
      }

  return collides;
}

/*****
 *
 *  FUNCTION: distance_between
 *
 *  PURPOSE: Computes the distance between two warriors.
 *
 *  INPUT: w1 - a warrior
 *         w2 - a warrior
 *
 *  RETURN VALUE: the distance
 *
 *  METHOD: Applies the Pythagorean theorem based on each warrior's row/col
 *          coordinates.
 *
 *****/

double Field::distance_between(const Warrior * w1, const Warrior *w2) const
{
  int row1;
  int col1;
  int row2;
  int col2;
  double delta_row;
  double delta_col;

  w1->get_position(row1, col1);
  w2->get_position(row2, col2);

  delta_row = row1 - row2;
  delta_col = col1 - col2;

  return sqrt(delta_row * delta_row + delta_col * delta_col);
}

/*****
 *
 * FUNCTION: Overload '<<' operator
 *
 * PURPOSE:  To be able to output members of Field class
 *
 *****/
ostream& operator << (ostream& out, const Field& f)
{
    f.write (out);
    return out;
}

/*****
 *
 * FUNCTION: Copy Constructor
 *
 * PURPOSE:  To provide a deep copy to prevent data destruction
 *
 *****/

Field::Field (const Field& f)
{
    int index = 0;  // index of warrior to check

    fill = f.fill;

    while (index < fill)
    {
        warrior[index]->clone();
        index++;
    }
}

/*****
 *
 * FUNCTION: Assignment Operator
 *
 * PURPOSE:
 *
 *****/
 // overloaded assignment operator

 Field& Field :: operator= (const Field& f)
{
    int index = 0; // index of warrior to check

    fill = f.fill;

    while (index < fill)
    {
        delete warrior[index];
        warrior[index]->clone();
        index++;
    }
    return (*this);
}

/*****
 *
 * FUNCTION: Field Destructor
 *
 * PURPOSE:  Deletes all dynamically allocated variables
 *
 *
 *****/

Field::~Field()
{
    int index = 0;  // index of warrior to check

    while (index < fill)
    {
        delete warrior[index];
        index++;
    }
}





