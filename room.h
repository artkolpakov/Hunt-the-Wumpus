#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include "event.h"

#include "wumpus.h"
#include "pit.h"
#include "bats.h"
#include "gold.h"

using namespace std;


class Room {
public:

/******************************************************
** Function: Room constructor
** Description: default constructor for a Room class, sets
* the room name to " " and sets *events to NULL
** Parameters: -
** Pre-Conditions: Wumpus, Pit, Bats, Gold and Event classes must exist
** Post-Conditions: room name and events are initialized and set to " " and NULL
* when a Room class is created
******************************************************/ 
	Room(); 

/******************************************************
** Function: Room class destuctor
** Description: deallocates the dynamically allocated memory 
* when the Room class goes out of scope (program ends in our case)
** Parameters: -
** Pre-Conditions: Wumpus, Pit, Bats, Gold and Event classes must exist
** Post-Conditions: the memory is freed, all dynamically 
* allocated memory is now deleted from the heap
*****************************************************/  
  ~Room();

/******************************************************
** Function: Room alternate constructor
** Description: alternate constructor for a Room class, sets
* the room name to the passed to it string
** Parameters: string
** Pre-Conditions: Room class must exist
** Post-Conditions: room name is initialized and set to the passed string value
* when a Room class is created using alternate constructor 
******************************************************/ 
	Room(string);

/******************************************************
** Function: get_name
** Description: we need this function in order to gain access 
* to the private member of a Room class: string name
** Parameters: -
** Pre-Conditions: Room class must exist
** Post-Conditions: returns the string value of private member 
* variable name of a class
******************************************************/
	string get_name();

/******************************************************
** Function: set_name
** Description: this function allows us to assign values
* to the private class member variable: string name
** Parameters: string name - value that we assign
** Pre-Conditions: Room class must exist
** Post-Conditions: now we can directly assign values to 
* private member variable name of a class, when this 
* function is called
******************************************************/   
  void set_name(string);

/******************************************************
** Function: wumpus_event
** Description: this function first checks if dynamically allocated events is already 
* using other class, if so - deletes events and then fills events with wumpus and calls
* encounter function for the events
** Parameters: -
** Pre-Conditions: Room, Event and Wumpus classes must exist
** Post-Conditions: the needed encounter message for Wumpus's room is printed when this 
* function is called
******************************************************/  
  void wumpus_event();

/******************************************************
** Function: pit_event
** Description: this function first checks if dynamically allocated events is already 
* using other class, if so - deletes events and then fills events with pits and calls
* encounter function for the events
** Parameters: -
** Pre-Conditions: Room, Event and Wumpus classes must exist
** Post-Conditions: the needed encounter message for Pit's room is printed when this 
* function is called
******************************************************/ 
  void pit_event();

/******************************************************
** Function: bat_event
** Description: this function first checks if dynamically allocated events is already 
* using other class, if so - deletes events and then fills events with bats and calls
* encounter function for the events
** Parameters: -
** Pre-Conditions: Room, Event and Wumpus classes must exist
** Post-Conditions: the needed encounter message for Bat's room is printed when this 
* function is called
******************************************************/ 
  void bat_event();

/******************************************************
** Function: gold_event
** Description: this function first checks if dynamically allocated events is already 
* using other class, if so - deletes events and then fills events with gold and calls
* encounter function for the events
** Parameters: -
** Pre-Conditions: Room, Event and Wumpus classes must exist
** Post-Conditions: the needed encounter message for Gold's room is printed when this 
* function is called
******************************************************/ 
  void gold_event();

/******************************************************
** Function: wumpus_percept
** Description: this function first checks if dynamically allocated events is already 
* using other class, if so - deletes events and then fills events with wumpus and calls
* percept function for the events
** Parameters: -
** Pre-Conditions: Room, Event and Wumpus classes must exist
** Post-Conditions: the needed percept message for Wumpus's room is printed when this 
* function is called
******************************************************/ 
  void wumpus_percept();

/******************************************************
** Function: pit_percept
** Description: this function first checks if dynamically allocated events is already 
* using other class, if so - deletes events and then fills events with pits and calls
* percept function for the events
** Parameters: -
** Pre-Conditions: Room, Event and Wumpus classes must exist
** Post-Conditions: the needed percept message for Pit's room is printed when this 
* function is called
******************************************************/ 
  void pit_percept();

/******************************************************
** Function: bat_percept
** Description: this function first checks if dynamically allocated events is already 
* using other class, if so - deletes events and then fills events with bats and calls
* percept function for the events
** Parameters: -
** Pre-Conditions: Room, Event and Wumpus classes must exist
** Post-Conditions: the needed percept message for Bat's room is printed when this 
* function is called
******************************************************/ 
  void bat_percept();

/******************************************************
** Function: gold_percept
** Description: this function first checks if dynamically allocated events is already 
* using other class, if so - deletes events and then fills events with gold and calls
* percept function for the events
** Parameters: -
** Pre-Conditions: Room, Event and Wumpus classes must exist
** Post-Conditions: the needed percept message for Gold's room is printed when this 
* function is called
******************************************************/ 
  void gold_percept();

private:
	string name;
  Event* events;

};
#endif
