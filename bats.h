#ifndef BATS_H
#define BATS_H

#include "event.h"
#include <iostream>
#include <vector>

using namespace std;

class Bats : public Event {

public:

/******************************************************
** Function: Bats constructor
** Description: default constructor for an Bats class, does nothing
** Parameters: -
** Pre-Conditions: Bats and Event classes must exist
** Post-Conditions: Nothing happens 
******************************************************/ 
  Bats();

/******************************************************
** Function: Bats destructor
** Description: default destructor for an Bats class, does nothing
** Parameters: -
** Pre-Conditions: Bats and Event classes must exist
** Post-Conditions: Nothing happens 
******************************************************/ 
  ~Bats();

/******************************************************
** Function: percept() function for Bats class
** Description: this function is overriden by Bats class, it prints
* a required percept message, when called
** Parameters: -
** Pre-Conditions: Bats and Event classes must exist
** Post-Conditions: "You hear wings flapping." is printed when the function 
* percept is used with Bats class
******************************************************/
  void percept() override;

/******************************************************
** Function: encounter() function for Bats class
** Description: this function is overriden by Bats class, it prints
* a required encounter message, when called
** Parameters: -
** Pre-Conditions: Bats and Event classes must exist
** Post-Conditions: "You met a bat! ..." is printed when the function 
* percept is used with Bats class
******************************************************/
  void encounter() override;

protected:
  
};

#endif
