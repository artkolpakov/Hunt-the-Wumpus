#ifndef PIT_H
#define PIT_H

#include "event.h"
#include <iostream>
#include <vector>
using namespace std;

class Pit : public Event {

public:

/******************************************************
** Function: Pit constructor
** Description: default constructor for a Pit class, does nothing
** Parameters: -
** Pre-Conditions: Pit and Event classes must exist
** Post-Conditions: Nothing happens 
******************************************************/ 
  Pit();

/******************************************************
** Function: Pit destructor
** Description: default destructor for a Pit class, does nothing
** Parameters: -
** Pre-Conditions: Pit and Event classes must exist
** Post-Conditions: Nothing happens
******************************************************/ 
  ~Pit(); 

/******************************************************
** Function: percept() function for Pit class
** Description: this function is overriden by a Pit class, it prints
* a required percept message, when called
** Parameters: -
** Pre-Conditions: Pit and Event classes must exist
** Post-Conditions: "You feel a breeze." is printed when the function 
* percept is used with Pit class
******************************************************/  
  void percept() override;

/******************************************************
** Function: encounter() function for Pit class
** Description: this function is overriden by Pit class, it prints
* a required encounter message, when called
** Parameters: -
** Pre-Conditions: Pit and Event classes must exist
** Post-Conditions: "You got into the bottomless pit and died :( " is printed when 
* the function percept is used with Pit class
******************************************************/
  void encounter() override;

protected:
  
};

#endif