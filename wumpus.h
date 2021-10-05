#ifndef WUMPUS_H
#define WUMPUS_H

#include "event.h"
#include <iostream>
#include <vector>
using namespace std;

class Wumpus : public Event {

public:

/******************************************************
** Function: Wumpus constructor
** Description: default constructor for a Wumpus class, does nothing
** Parameters: -
** Pre-Conditions: Wumpus and Event classes must exist
** Post-Conditions: Nothing happens 
******************************************************/ 
  Wumpus();

/******************************************************
** Function: Wumpus destructor
** Description: default destructor for a Wumpus class, does nothing
** Parameters: -
** Pre-Conditions: Wumpus and Event classes must exist
** Post-Conditions: Nothing happens
******************************************************/ 
  ~Wumpus();

/******************************************************
** Function: percept() function for Wumpus class
** Description: this function is overriden by a Wumpus class, it prints
* a required percept message, when called
** Parameters: -
** Pre-Conditions: Wumpus and Event classes must exist
** Post-Conditions: "You smell a terrible stench." is printed when the function 
* percept is used with Wumpus class
******************************************************/  
  void percept() override;

/******************************************************
** Function: encounter() function for Wumpus class
** Description: this function is overriden by Wumpus class, it prints
* a required encounter message, when called
** Parameters: -
** Pre-Conditions: Wumpus and Event classes must exist
** Post-Conditions: "You see the Wumpus and die :( " is printed when 
* the function percept is used with Wumpus class
******************************************************/    
  void encounter() override;

protected:
  
};


#endif