#ifndef GOLD_H
#define GOLD_H

#include "event.h"
#include <iostream>
#include <vector>

using namespace std;

class Gold : public Event {

public:

/******************************************************
** Function: Gold constructor
** Description: default constructor for a Gold class, does nothing
** Parameters: -
** Pre-Conditions: Gold and Event classes must exist
** Post-Conditions: Nothing happens 
******************************************************/ 
  Gold();

/******************************************************
** Function: Gold destructor
** Description: default destructor for a Gold class, does nothing
** Parameters: -
** Pre-Conditions: Gold and Event classes must exist
** Post-Conditions: Nothing happens
******************************************************/ 
  ~Gold();
  
/******************************************************
** Function: percept() function for Gold class
** Description: this function is overriden by a Gold class, it prints
* a required percept message, when called
** Parameters: -
** Pre-Conditions: Gold and Event classes must exist
** Post-Conditions: "You see a glimmer nearby." is printed when the function 
* percept is used with Gold class
******************************************************/
  void percept() override;

/******************************************************
** Function: encounter() function for Gold class
** Description: this function is overriden by Gold class, it prints
* a required encounter message, when called
** Parameters: -
** Pre-Conditions: Gold and Event classes must exist
** Post-Conditions: "You found the gold !!!" is printed when the function 
* percept is used with Gold class
******************************************************/
  void encounter() override;

protected:
  
};

#endif
