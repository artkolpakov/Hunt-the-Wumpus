#ifndef GAME_H
#define GAME_H

#include "room.h"
#include "event.h"
#include "wumpus.h"
#include "pit.h"
#include "bats.h"
#include "gold.h"


#include <iostream>
#include <vector>
#include <cstdlib>
#include <stdlib.h>
#include <time.h>

using namespace std;

class Game {
public:

/******************************************************
** Function: set_square_size
** Description: this function allows us to assign values
* to the private class member variable: int square_size
** Parameters: square_size - value that we assign
** Pre-Conditions: Game class must exist
** Post-Conditions: now we can directly assign values to 
* private member variable square_size of a class, when this 
* function is called
******************************************************/  
  void set_square_size(int);

/******************************************************
** Function: Game constructor
** Description: default constructor for a Game class, does nothing
** Parameters: -
** Pre-Conditions: Game class must exist
** Post-Conditions: Nothing happens 
******************************************************/ 
  Game();

/******************************************************
** Function: Game destructor
** Description: default destructor for a Game class, does nothing
** Parameters: -
** Pre-Conditions: Game class must exist
** Post-Conditions: Nothing happens
******************************************************/  
  ~Game();

/******************************************************
** Function: Game class copy constructor 
** Description: makes a 'deep' copy of an old Game when we 
* create a new class Game and instantly set it equal to 
* the old Game class
** Parameters: old Game class 
** Pre-Conditions: Game class must exist
** Post-Conditions: a deep copy is made
*****************************************************/
  Game(const Game& old_game); 

/******************************************************
** Function: Game class overloaded assignment operator
** Description: makes a 'deep' copy of an old Game when we 
* create a new class Game and at some point set it equal to 
* the old Game class
** Parameters: old Game
** Pre-Conditions: Game class must exist
** Post-Conditions: a deep copy is made
*****************************************************/
  Game& operator=(const Game&);

/******************************************************
** Function: allocate_the_array
** Description: this function dynamically allocates the game_board, which is 
* a 2D vector of needed square size by using the push_back function
** Parameters: -
** Pre-Conditions: game, room, event, wumpus, pit, bats, gold classes must exist 
** Post-Conditions: the 2D game_board is dynamically allocated and initialized
******************************************************/  
	void allocate_the_array();

/******************************************************
** Function: print_cheat_board
** Description: using several loops prints the cheat game board, where all the events 
* are shown
** Parameters: -
** Pre-Conditions: game, room, event, wumpus, pit, bats, gold classes must exist 
** Post-Conditions: the 2D cave is printed with all the events shown on it
******************************************************/  
  void print_cheat_board();

/******************************************************
** Function: print_normal_board
** Description: using several loops prints the normal game board, where all the events 
* are hidden except of the player's chip (*)
** Parameters: -
** Pre-Conditions: game, room, event, wumpus, pit, bats, gold classes must exist 
** Post-Conditions: the 2D cave is printed with all the events hidden on it
******************************************************/  
  void print_normal_board();

/******************************************************
** Function: spawn_player
** Description: Randomly generates the player's Y and X coordinates so that 
* he spawns in the empty room 
** Parameters: -
** Pre-Conditions: game class must exist 
** Post-Conditions: when function is called the player's coordinates are
* randomly generated so that the player gets spawned in the random empty room 
******************************************************/    
  void spawn_player();

/******************************************************
** Function: spawn_wumpus
** Description: Randomly generates the Wumpus's Y and X coordinates so that 
* it spawns in the empty room 
** Parameters: -
** Pre-Conditions: game class must exist 
** Post-Conditions: when function is called the Wumpus's coordinates are
* randomly generated so that the Wumpus gets spawned in the random empty room 
******************************************************/   
  void spawn_wumpus();

/******************************************************
** Function: spawn_1st_pit
** Description: Randomly generates the Y and X coordinates of the 1st pit on the map 
* so that it spawns in the empty room 
** Parameters: -
** Pre-Conditions: game class must exist 
** Post-Conditions: when function is called the pit's coordinates are
* randomly generated so that the pit gets spawned in the random empty room 
******************************************************/ 
  void spawn_1st_pit();

/******************************************************
** Function: spawn_2nd_pit
** Description: Randomly generates the Y and X coordinates of the 2nd pit on the map 
* so that it spawns in the empty room 
** Parameters: -
** Pre-Conditions: game class must exist 
** Post-Conditions: when function is called the pit's coordinates are
* randomly generated so that the pit gets spawned in the random empty room 
******************************************************/ 
  void spawn_2nd_pit();

/******************************************************
** Function: spawn_gold
** Description: Randomly generates the Y and X coordinates of the gold on the map 
* so that it spawns in the empty room 
** Parameters: -
** Pre-Conditions: game class must exist 
** Post-Conditions: when function is called the gold's coordinates are
* randomly generated so that the gold gets spawned in the random empty room 
******************************************************/ 
  void spawn_gold();

/******************************************************
** Function: spawn_1st_bat
** Description: Randomly generates the Y and X coordinates of the 1st bat on the map 
* so that it spawns in the empty room 
** Parameters: -
** Pre-Conditions: game class must exist 
** Post-Conditions: when function is called the bat's coordinates are
* randomly generated so that the bat gets spawned in the random empty room 
******************************************************/ 
  void spawn_1st_bat();

/******************************************************
** Function: spawn_2nd_bat
** Description: Randomly generates the Y and X coordinates of the 2nd bat on the map 
* so that it spawns in the empty room 
** Parameters: -
** Pre-Conditions: game class must exist 
** Post-Conditions: when function is called the bat's coordinates are
* randomly generated so that the bat gets spawned in the random empty room 
******************************************************/ 
  void spawn_2nd_bat();

/******************************************************
** Function: spawn_2nd_bat
** Description: calls all of the spawn_ function so that all of the 
* events are getting spawned in random empty rooms
** Parameters: -
** Pre-Conditions: game class must exist 
** Post-Conditions: all creatures of the cave are getting spawned in the 
* new random rooms of the cave
******************************************************/ 
  void spawn_everything();

/******************************************************
** Function: get_choice
** Description: takes a move choice (wasd) from the user, checks if it is 
* valid, if so returns a move choice string, otherwise keeps asking for the input 
* until it is correct
** Parameters: -
** Pre-Conditions: game class must exist 
** Post-Conditions: the valed moove choice is returned 
******************************************************/ 
  string get_choice();

/******************************************************
** Function: is_valid_choice
** Description: a helper function for get_choice, checks if user 
* enters the correct input, keeps asking for the input until it is correct
** Parameters: -
** Pre-Conditions: game class must exist 
** Post-Conditions: the valed moove choice is returned
******************************************************/ 
  string is_valid_choice(string);

/******************************************************
** Function: make_moove
** Description: gets a move choice, by calling the get_choice function, and then based on it,
* makes a moove in the needed direction, replaces player's chip (*) to the needed room, changes 
* the X and Y coordinates of the player, erases the previous room name, where the player was. Or 
* makes a shoot if player chose to use a bow as his move choice
** Parameters: -
** Pre-Conditions: game, room, event, wumpus, pit, bats, gold classes must exist 
** Post-Conditions: the player changes his position in the cave depending on the choice of his move
******************************************************/ 
  void make_moove();

/******************************************************
** Function: make_moove1
** Description: is a helper function of a make_moove, gets a move choice, by calling the
* get_choice function, and then based on it, makes a moove in the needed direction, replaces
* player's chip (*) to the needed room, changes the X and Y coordinates of the player 
** Parameters: -
** Pre-Conditions: game, room, event, wumpus, pit, bats, gold classes must exist 
** Post-Conditions: the player changes his position in the cave depending on the choice of his move
******************************************************/
  void make_moove1(string);

/******************************************************
** Function: shoot_up
** Description: gets and checks a move choice, as a passed string parameter, and then based on it,
* makes an arrow shoot in the upwards direction, checks if arrow hits the wumpus, kills the wumpus if so,
* decrements the arrows number
** Parameters: string move choice
** Pre-Conditions: game, room, event, wumpus, pit, bats, gold classes must exist 
** Post-Conditions: the arrow gets shoot up if users choice is " w", wumpus gets killed if arrow 
* hits it, teleports with 75% probability otherwise. The arrows number is decremented 
******************************************************/
  int shoot_up(string);

/******************************************************
** Function: shoot_down
** Description: gets and checks a move choice, as a passed string parameter, and then based on it,
* makes an arrow shoot in the downwards direction, checks if arrow hits the wumpus, kills the wumpus if so,
* decrements the arrows number
** Parameters: string move choice
** Pre-Conditions: game, room, event, wumpus, pit, bats, gold classes must exist 
** Post-Conditions: the arrow gets shoot down if users choice is " s", wumpus gets killed if arrow 
* hits it, teleports with 75% probability otherwise. The arrows number is decremented 
******************************************************/
  int shoot_down(string);

/******************************************************
** Function: shoot_left
** Description: gets and checks a move choice, as a passed string parameter, and then based on it,
* makes an arrow shoot in the left direction, checks if arrow hits the wumpus, kills the wumpus if so,
* decrements the arrows number
** Parameters: string move choice
** Pre-Conditions: game, room, event, wumpus, pit, bats, gold classes must exist 
** Post-Conditions: the arrow gets shoot left if users choice is " a", wumpus gets killed if arrow 
* hits it, teleports with 75% probability otherwise. The arrows number is decremented 
******************************************************/
  int shoot_left(string);

/******************************************************
** Function: shoot_right
** Description: gets and checks a move choice, as a passed string parameter, and then based on it,
* makes an arrow shoot in the right direction, checks if arrow hits the wumpus, kills the wumpus if so,
* decrements the arrows number
** Parameters: string move choice
** Pre-Conditions: game, room, event, wumpus, pit, bats, gold classes must exist 
** Post-Conditions: the arrow gets shoot right if users choice is " d", wumpus gets killed if arrow 
* hits it, teleports with 75% probability otherwise. The arrows number is decremented 
******************************************************/
  int shoot_right(string);

/******************************************************
** Function: wumpus_teleport
** Description: works the same as spawn_wumpus, with 75% chance randomly generates the Wumpus's
* Y and X coordinates so that it teleports to the new empty room 
** Parameters: -
** Pre-Conditions: game, room, event, wumpus, pit, bats, gold classes must exist 
** Post-Conditions: when function is called with 75% probability the Wumpus's coordinates are
* randomly generated so that the Wumpus gets teleposted to the new random empty room 
******************************************************/   
  void wumpus_teleport();

/******************************************************
** Function: player_teleport
** Description: works the same as spawn_player, randomly generates the player's
* Y and X coordinates so that the player teleports to the new room, which can have
* other events in it (is not 100% empty)
** Parameters: -
** Pre-Conditions: game, room, event, wumpus, pit, bats, gold classes must exist 
** Post-Conditions: when function is called the Player's coordinates are
* randomly generated so that the Player gets teleposted to the new random room 
******************************************************/ 
  void player_teleport();

/******************************************************
** Function: meet_the_wumpus
** Description: checks if the player enters the same room with Wumpus, 
* if so - kills the player, calls encounter function for Wumpus class
** Parameters: -
** Pre-Conditions: game, room, event, wumpus, pit, bats, gold classes must exist 
** Post-Conditions: player dies and game ends if player's X and Y coordinates are the same as 
* Wumpus's X and Y coordinates, abstract encounter function is called 
******************************************************/ 
  void meet_the_wumpus();

/******************************************************
** Function: meet_the_bats
** Description: checks if the player enters the same room with one of the bats, 
* if so - teleports the player, calls encounter function for Bats class
** Parameters: -
** Pre-Conditions: game, room, event, wumpus, pit, bats, gold classes must exist 
** Post-Conditions: player gets teleported if player's X and Y coordinates are the same as 
* X and Y coordinates of one of the bats, abstract encounter function is called 
******************************************************/ 
  void meet_the_bats();

/******************************************************
** Function: meet_the_pits
** Description: checks if the player enters the same room with one of the pits, 
* if so - kills the player, calls encounter function for Pit class
** Parameters: -
** Pre-Conditions: game, room, event, wumpus, pit, bats, gold classes must exist 
** Post-Conditions: player gets killed and game ends if player's X and Y coordinates are the same
* as X and Y coordinates of one of the pits, abstract encounter function is called 
******************************************************/ 
  void meet_the_pits();

/******************************************************
** Function: meet_the_gold
** Description: checks if the player enters the same room with gold, 
* if so - changes the 'if gold found' status to yes, calls encounter function for Gold class
** Parameters: -
** Pre-Conditions: game, room, event, wumpus, pit, bats, gold classes must exist 
** Post-Conditions: the 'if gold found' status changes to yes if player's X and Y coordinates
* are the same as Gold's X and Y coordinates, abstract encounter function is called 
******************************************************/ 
  void meet_the_gold();

/******************************************************
** Function: check_for_event
** Description: collects all of the meet_ events in one function, so that they are called all
* together at once
** Pre-Conditions: game, room, event, wumpus, pit, bats, gold classes must exist 
** Post-Conditions: the game checks for all of the events and performs the corresponding 
* actions when this function is called 
******************************************************/ 
  void check_for_event();

/******************************************************
** Function: is_wumpus_close
** Description: checks if the player enters the room adjacent to Wumpus's location, 
* if so - calls percept function for Wumpus class
** Parameters: -
** Pre-Conditions: game, room, event, wumpus, pit, bats, gold classes must exist 
** Post-Conditions: abstract percept function is called if the player 
* is in the adjacent room to the Wumpus
******************************************************/ 
  void is_wumpus_close();

/******************************************************
** Function: is_pit_close
** Description: checks if the player enters the room adjacent to one of the 
* pits location, if so - calls percept function for Pit class
** Parameters: -
** Pre-Conditions: game, room, event, wumpus, pit, bats, gold classes must exist 
** Post-Conditions: abstract percept function is called if the player 
* is in the adjacent room to one of the pits
******************************************************/ 
  void is_pit_close();

/******************************************************
** Function: is_bat_close
** Description: checks if the player enters the room adjacent to one of the 
* bats location, if so - calls percept function for Bats class
** Parameters: -
** Pre-Conditions: game, room, event, wumpus, pit, bats, gold classes must exist 
** Post-Conditions: abstract percept function is called if the player 
* is in the adjacent room to one of the bats
******************************************************/ 
  void is_bat_close();

/******************************************************
** Function: is_gold_close
** Description: checks if the player enters the room adjacent to Gold's location, 
* if so - calls percept function for Gold class
** Parameters: -
** Pre-Conditions: game, room, event, wumpus, pit, bats, gold classes must exist 
** Post-Conditions: abstract percept function is called if the player 
* is in the adjacent room to the Gold
******************************************************/ 
  void is_gold_close();

/******************************************************
** Function: check_for_win
** Description: this function checks if the player exited the cave (turned back to the 
* same location where he was spawned and) and stole Wumpus's gold, prints the winning message if so,
* ends the game 
** Parameters: -
** Pre-Conditions: game, room, event, wumpus, pit, bats, gold classes must exist 
** Post-Conditions: the game is ended if the player exited the cave and stole Wumpus's gold
******************************************************/ 
  void check_for_win();

/******************************************************
** Function: print_status
** Description: prints status of the game: number of arrows left, is gold found,
* is Wumpus killed
** Parameters: -
** Pre-Conditions: game, room, event, wumpus, pit, bats, gold classes must exist 
** Post-Conditions: the current game status is printed if function is called
******************************************************/   
  void print_status();

/******************************************************
** Function: play_cheat_game
** Description: collect all of the function needed to play the game and loops them, 
* until the player wins or loses, prints the cheat board, where all the events are visible to the player
** Parameters: -
** Pre-Conditions: game, room, event, wumpus, pit, bats, gold classes must exist 
** Post-Conditions: the cheat game mode is played until the player wins or loses
******************************************************/   
  void play_cheat_game();

/******************************************************
** Function: play_normal_game
** Description: collect all of the function needed to play the game and loops them, 
* until the player wins or loses, prints the normal board, where all the events are hidden from the player
** Parameters: -
** Pre-Conditions: game, room, event, wumpus, pit, bats, gold classes must exist 
** Post-Conditions: the normal game mode is played until the player wins or loses
******************************************************/   
  void play_normal_game();

/******************************************************
** Function: set_if_cheat_mode
** Description: this function allows us to assign values
* to the private class member variable: int if_cheat_mode
** Parameters: if_cheat_mode - int value that we assign
** Pre-Conditions: game class must exist
** Post-Conditions: now we can directly assign values to 
* private member variable if_cheat_mode of a class, when this 
* function is called
******************************************************/ 
  void set_if_cheat_mode(int);

/******************************************************
** Function: get_if_lost
** Description: we need this function in order to gain access 
* to the private member of a Game class: int if_lost
** Parameters: -
** Pre-Conditions: Game class must exist
** Post-Conditions: returns the int value of private member 
* variable if_lost of a class
******************************************************/
  int get_if_lost();

/******************************************************
** Function: get_if_won
** Description: we need this function in order to gain access 
* to the private member of a Game class: int if_won
** Parameters: -
** Pre-Conditions: Game class must exist
** Post-Conditions: returns the int value of private member 
* variable if_won of a class
******************************************************/
  int get_if_won();

private:
  int square_size = 5; // length of one side  
  vector<vector<Room> > game_board;

  int arrow_num = 3;
  
  int playerX;
  int playerY;

  int escape_roomX;
  int escape_roomY;

  int arrowX;
  int arrowY;

  int wumpusX;
  int wumpusY;

  int pit1X;
  int pit1Y;

  int pit2X;
  int pit2Y;

  int bat1X;
  int bat1Y;

  int bat2X;
  int bat2Y;

  int goldX;
  int goldY;

  bool game_over = 0;
  int if_lost = 0;
  int if_won = 0;
  int if_w_killed = 0;
  int gold_found = 0;
  int if_cheat_mode = 0;
};
#endif
