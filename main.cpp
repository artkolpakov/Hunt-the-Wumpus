/******************************************************
** Program: wumpus.cpp
** Author: Artem Kolpakov
** Date: 05/23/2021
** Description: Hunt the Wumpus is a game set inside the cave of the Wumpus, a scary, 
* gold-hoarding monster who likes to eat people who disturb its sleep. The player's goal 
* is to guide an adventurer to kill the Wumpus, find its hidden gold, and escape alive. 
* The Wumpus lives in a large cave of rooms arranged in a grid, where each room has four 
* tunnels leading to the rooms to the north, east, south, and west. In other words, this is a
* game of a ‘hide n seek’ type, in which the user- player gets into a huge cave, in the rooms
* of which there are different types of events, namely, there is a room of the cave, where a monster
* lives, there is such a room where there is a gold, and there is such a room where there is an exit
* from the cave (also a player gets spawned initially in the room where there is an exit). Therefore,
* the player's goal is to find and kill the monster (Wumpus), find its hidden gold, and escape alive. 
** Input: To navigate the cave system, the player types "w" for north, "a" for west, "s" for south,
* or "d" for east. In order to fire an arrow, a space (" ") should be used, followed by either "w",
* "a", "s", or "d" to indicate the direction. 
** Output: Every round my game prints 1) a new, updated cheat/normal cave, 2) the current status 
* of the game, 3) percepts and encounters. At the end, if player lost, my program asks the player 
* if he wants to start the game over with the same cave configuration, start the game over with a new
* random cave configuration, or quit the game entirely.
******************************************************/


#include "event.h"
#include "game.h"

#include <iostream>
#include <vector>
#include <cstdlib>
#include <stdlib.h>
#include <time.h>

using namespace std;


/******************************************************
** Function: get_valid_arg_num 
** Description: checks the num of line arguments, if there are too many/to few of them
** Parameters: -
** Pre-Conditions: game, room, event, wumpus, pit, bats, gold classes must exist 
** Post-Conditions: returns true is the line arguments num is 3, false otherwise 
*****************************************************/ 
bool get_valid_arg_num (int argc){
  bool flag = true;
   if (argc < 3){
     cout << "You did not enter any arguments or you did not enter enough arguments (there should be 2). Please compile the program again (for example, use ./main 5 false)." << endl;
       flag = false;
   }
/* we check for 3 because ./main is our first argument */
   if (argc > 3){
       cout << "You entered too many arguments (there should be 2). Please compile the program again (for example, use ./main 7 true)." << endl;
       flag = false;
   }

   if (argc == 3){
       flag = true;
   }

   return flag;
}

/******************************************************
** Function: main 
** Description: creates game class, checks the arguments, initializes the game board 
* based on the entered line arguments and then plays a game 
** Parameters: -
** Pre-Conditions: game, room, event, wumpus, pit, bats, gold classes must exist 
** Post-Conditions: the game is played untill the user wins/loses
*****************************************************/ 

int main(int argc, char** argv) {
  srand(time(NULL));

  if (get_valid_arg_num(argc) == 0){
    return 1;
  }
  
  Game game;
  int rows = stoi(argv[1]);
  if (rows < 4) {
    cout << "Caves smaller than four rooms on a side aren't allowed. " << endl;
    return 1;
  }
   // takes a string and returns the integer
  game.set_square_size(rows);
  game.allocate_the_array();
  game.spawn_everything();

  Game game1;
  game1 = game; //reserve copy of the same configuration

  string str1 = "true";
  string str2 = "false";
  if (str1.compare(argv[2]) == 0){
    game.play_cheat_game();
  }
  else if (str2.compare(argv[2]) == 0){
    game.play_normal_game();
  }
  else{
    cout << "Plese use only true or false!" << endl;
  }
  if (game.get_if_lost()== 1){

    int x;
    cout << "Do you want to start the game over with the same cave configuration (1) , start the game over with a new random cave configuration (2) , or quit the game entirely ? (3): ";
    cin >> x;


    if (x == 1){
      if (str1.compare(argv[2]) == 0){
        game1.play_cheat_game();
      }
        else if (str2.compare(argv[2]) == 0){
          game1.play_normal_game();
        }
    }
    if (x == 2){
      
      Game game2;
      game2.set_square_size(rows);
      game2.allocate_the_array();
      game2.spawn_everything();
          if (str1.compare(argv[2]) == 0){
            game2.play_cheat_game();
          }
            else if (str2.compare(argv[2]) == 0){
            game2.play_normal_game();
          }
    }

    if (x == 3){
      cout << "Bye bye. ";
    }
  }
  cout << "Thanks for playing with us! " << endl;
  return 0;
}
