#ifndef EVENT_H
#define EVENT_H

#include <iostream>
using namespace std;

class Event{

public:

/******************************************************
** Function: Event constructor
** Description: default constructor for an Event class, does nothing
** Parameters: -
** Pre-Conditions: Event class must exist
** Post-Conditions: Nothing happens 
******************************************************/ 
Event();

/******************************************************
** Function: abstract Event destructor
** Description: default destructor for an Event class, does nothing 
* and gets overriden by classes that inherit Event
** Parameters: -
** Pre-Conditions: bats class must exist
** Post-Conditions: Nothing happens 
******************************************************/ 
virtual ~Event();

/******************************************************
** Function: percept() function 
** Description: this function is overriden by all classes that that inherit Event
* clas, also this method is called whenever the adventurer is in a room adjacent
* to the event
** Parameters: -
** Pre-Conditions: Event class must exist
** Post-Conditions: any other class which inherits Event can 'edit' this function 
* the way that it's unique for this class 
******************************************************/
virtual void percept() = 0;

/******************************************************
** Function: encounter() function 
** Description: this function is overriden by all classes that that inherit Event
* clas, also this method is called when the adventurer enters the same room as the event
** Parameters: -
** Pre-Conditions: Event class must exist
** Post-Conditions: any other class which inherits Event can 'edit' this function 
* the way that it's unique for this class 
******************************************************/
virtual void encounter() = 0;

protected:
  
};

#endif