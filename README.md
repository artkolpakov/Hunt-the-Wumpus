# Hunt-the-Wumpus
Hunt the Wumpus is a game set inside the cave of the Wumpus, a scary, gold-hoarding monster who likes to eat people who disturb its sleep. 
The player's goal is to guide an adventurer to kill the Wumpus, find its hidden gold, and escape alive. 
The Wumpus lives in a large cave of rooms arranged in a grid, where each room has four tunnels leading to the rooms to the north, east, south, and west.
The adventurer starts the game in a random empty room in the Wumpus’ cave. 
Her starting position is also the location of the escape rope that she must use to escape after she's completed her task.
Each room may be empty, or it may contain one (and only one) of four "events" (all described below): two kinds of dangerous hazards,
the terrifying Wumpus, and the gold treasure. When the adventurer is in a room that’s adjacent to one containing an "event",
the player will receive a percept (a message) to inform them about the event the adventurer is close to.
If the adventurer perishes while searching for the Wumpus, the player is presented with the option to start the game over with the same cave configuration,
start the game over with a new random cave configuration, or quit the game entirely.
The player wins the game if they can safely guide the adventurer through the cave to kill the Wumpus, pick up the gold, and make it back to the escape rope unharmed!
Note: If you enter the cave, retrieve the gold, and escape without killing the Wumpus, that's okay too. The player still wins.
To navigate the cave system, the player should type "w" (north), "a" (west), "s" (south), or "d" (east).
In order to fire an arrow, a space (" ") should be used, followed by either "w", "a", "s", or "d" to indicate the direction.
For example, the user would enter " d" to fire an arrow towards the east. 

Finally, the program has to be compiled with two command line parameters, the first standing for the cave size and the second being either "true" or "false".
If the parameter is set to false (e.g. ./wumpus 6 false) then the program will run as normal (with events being hidden). If the second command line value
is specified as "true" then the game operates in debug mode with all the events being visible to the player.
