#include <iostream>
#include "game.h"
#include <vector>

using namespace std;

void Game::set_square_size(int square_size){
  this->square_size = square_size;
}

Game::Game(){
  
}

Game::~Game(){

}

void Game::allocate_the_array(){

	//create a 2D vector of the requested size
  for (int i=0; i< square_size; i++){
    vector<Room> test1;
    for(int j=0; j<square_size; j++){
      Room room;
      test1.push_back(room);
    }
    game_board.push_back(test1);
  }
}

void Game::print_cheat_board(){
  int i, j;
  cout << endl;
   for (i = 0; i < square_size; ++i){
      for (j = 0; j < square_size; ++j){
          if (i % 2 == 0 && j % 2 == 0){
              cout << "|\033[30;47m " << game_board[i][j].get_name()
                   << " " << "\033[30;0m";
           }

           else if (i % 2 == 1 && j % 2 == 1){
               cout << "|\033[30;47m " << game_board[i][j].get_name()
                   << " " << "\033[30;0m";
           }

           else
               cout << "|\033[30;0m " << game_board[i][j].get_name() << " ";
       }
       cout << endl;
   }
   cout << endl;
}

void Game::print_normal_board(){
  int i, j;
  cout << endl;
   for (i = 0; i < square_size; ++i){
      for (j = 0; j < square_size; ++j){
          if (i % 2 == 0 && j % 2 == 0){
              if (game_board[i][j].get_name() == "*"){
              cout << "|\033[30;47m " << game_board[i][j].get_name()
                   << " " << "\033[30;0m";
                   }
              else{
                cout << "|\033[30;47m " << " " << " " << "\033[30;0m";
              }
           }

           else if (i % 2 == 1 && j % 2 == 1){
              if (game_board[i][j].get_name() == "*"){
              cout << "|\033[30;47m " << game_board[i][j].get_name()
                   << " " << "\033[30;0m";
                   }
              else{
                cout << "|\033[30;47m " << " " << " " << "\033[30;0m";
              }
           }

           else{
              if (game_board[i][j].get_name() == "*"){
              cout << "|\033[30;0m " << game_board[i][j].get_name()
                   << " ";
                   }
              else{
                cout << "|\033[30;0m " << " " << " ";
              }
        }
       }
       cout << endl;
   }
   cout << endl;
}

void Game::spawn_player(){
  do {
  playerX = rand()%square_size;
  playerY = rand()%square_size;
  } 
  while ( game_board[playerY][playerX].get_name()!= " ");
  escape_roomX = playerX;
  escape_roomY = playerY;

  game_board[playerY][playerX].set_name("*");
}

void Game::spawn_gold(){
  do {
  goldX = rand()%square_size;
  goldY = rand()%square_size;
  } 
  while ( game_board[goldY][goldX].get_name()!= " ");
  game_board[goldY][goldX].set_name("G");
}

void Game::spawn_wumpus(){
  do {
  wumpusX = rand()%square_size;
  wumpusY = rand()%square_size;
  } 
  while ( game_board[wumpusY][wumpusX].get_name()!= " ");
  game_board[wumpusY][wumpusX].set_name("W");
}

void Game::spawn_1st_pit(){
  do {
  pit1X = rand()%square_size;
  pit1Y = rand()%square_size;
  } 
  while (game_board[pit1Y][pit1X].get_name()!= " ");
  game_board[pit1Y][pit1X].set_name("P");
}

void Game::spawn_2nd_pit(){
  do {
  pit2X = rand()%square_size;
  pit2Y = rand()%square_size;
  } 
  while (game_board[pit2Y][pit2X].get_name()!= " ");
  game_board[pit2Y][pit2X].set_name("P");
}


void Game::spawn_1st_bat(){
  do {
  bat1X = rand()%square_size;
  bat1Y = rand()%square_size;
  } 
  while (game_board[bat1Y][bat1X].get_name()!= " ");
  game_board[bat1Y][bat1X].set_name("B");
}

void Game::spawn_2nd_bat(){
  do {
  bat2X = rand()%square_size;
  bat2Y = rand()%square_size;
  } 
  while (game_board[bat2Y][bat2X].get_name()!= " ");
  game_board[bat2Y][bat2X].set_name("B");
}

void Game::spawn_everything(){
  spawn_player();
  spawn_wumpus();
  spawn_1st_pit();
  spawn_2nd_pit();
  spawn_1st_bat();
  spawn_2nd_bat();
  spawn_gold();
}

string Game::get_choice(){
  string choice;
  cout << "Please enter a move choice (wasd): ";
  getline(cin, choice, '\n');
  //cin >> choice;
  if (choice == "w"){        
    if(playerY == 0){
      do {
        cout << "The cave ends here, you can't go up! Please enter a new move choice (wasd): ";
        cin >> choice;
      } while (choice == "w");
    }
  } 
  if (choice == "s"){
    if(playerY == square_size-1){
      do {
        cout << "The cave ends here, you can't go down! Please enter a new move choice (wasd): ";
        cin >> choice;
      } while (choice == "s");
    }
  }
  if (choice == "a"){
    if(playerX == 0){
      do {
        cout << "The cave ends here, you can't go left! Please enter a new move choice (wasd): ";
        cin >> choice;
      } while (choice == "a");
    }
  }
  if (choice == "d"){
    if(playerX == square_size-1){
      do {
        cout << "The cave ends here, you can't go right! Please enter a new move choice (wasd): ";
        cin >> choice;
      } while (choice == "d");
    }
  }

  choice = is_valid_choice(choice);

  return choice;
}

string Game::is_valid_choice(string choice){

  if (choice != "w" && choice != "a" && choice != "s" && choice != "d" && choice != " w" && choice != " a" && choice != " s" && choice != " d"){
    do {
        cout << "INVALID INPUT! Please enter a new move choice (wasd only): ";
        string choice1;
        getline(cin, choice1, '\n');
        choice = choice1;
      } 
    while (choice != "w" && choice != "a" && choice != "s" && choice != "d" && choice != " w" && choice != " a" && choice != " s" && choice != " d");
  }
  return choice;
}

//[row][column]!!!
void Game::make_moove(){
  string choice = get_choice();

  if ( (shoot_right(choice) != 1) && (shoot_left(choice) != 1) && (shoot_up(choice) != 1) && (shoot_down(choice) != 1) ){

    if ( (shoot_right(choice) == 2) || (shoot_left(choice) == 2) || (shoot_up(choice) == 2) || (shoot_down(choice) == 2) ){
      cout << "You don't have arrows to shoot! " << endl;
      do{
      cout << "Please enter a new move choice, without a space! " << endl;
      choice = get_choice();
      }
      while (choice == " w" || choice == " a" || choice == " s" || choice == " d"); 
    }

    game_board[playerY][playerX].set_name(" ");
    make_moove1(choice);

  }
}

void Game::check_for_event(){
  meet_the_pits();
  meet_the_wumpus();
  meet_the_bats();
  meet_the_gold();
}

void Game::make_moove1(string choice){
    if (choice == "w"){ // up       
      playerY = playerY-1;
      check_for_event();
      game_board[playerY][playerX].set_name("*");
    }
  if (choice == "s"){ //down
      playerY = playerY+1;
      check_for_event();
      game_board[playerY][playerX].set_name("*");
    }
  if (choice == "a"){ //left
      playerX = playerX-1;
      check_for_event();

      game_board[playerY][playerX].set_name("*");
    }
  if (choice == "d"){ //right
    playerX = playerX+1;
    check_for_event();

      game_board[playerY][playerX].set_name("*");
    }
}

int Game::shoot_up(string choice){
  int flag = 0;
  arrowX = playerX;
  arrowY = playerY;

  if (choice == " w"){ // up
    if (arrow_num>0){

  flag = 1;
    for(int i = 0; i<3; i++){
  // check for border 
      if(arrowY == 0){
        cout << "Arrow hits the wall! " << endl;
        break;
      }

  arrowY = arrowY-1;
  if (game_board[arrowY][arrowX].get_name() == "W"){
    cout << "You killed the Wumpus! " << endl;
    if_w_killed = 1;
    game_board[arrowY][arrowX].set_name(" ");
    
    wumpusY = -1;
    wumpusX = -1;
      break;
      }
    }
    
// to test use this : \/
//  game_board[arrowY][arrowX].set_name(">");

  if (if_w_killed != 1){
    cout << "Arrow missed !" << endl;
    wumpus_teleport();
  }
  arrow_num--;
    }
    else{
      flag = 2;
    }
  }
  return flag;
}

int Game::shoot_down(string choice){
  int flag = 0;
  arrowX = playerX;
  arrowY = playerY;

  if (choice == " s"){ // down
    if (arrow_num>0){
    flag = 1;
    for(int i = 0; i<3; i++){
  // check for border 
      if(arrowY == square_size-1){
        cout << "Arrow hits the wall! " << endl;
        break;
      }

  arrowY = arrowY+1;
  if (game_board[arrowY][arrowX].get_name() == "W"){
    cout << "You killed the Wumpus!" << endl;
    if_w_killed = 1;
    game_board[arrowY][arrowX].set_name(" ");
    
    wumpusY = -1;
    wumpusX = -1;
    
      break;
      }
    }
// to test use this : \/
//  game_board[arrowY][arrowX].set_name(">");

  if (if_w_killed != 1){
    cout << "Arrow missed !" << endl;
    wumpus_teleport();
  }
  arrow_num--;
    }
    else{
      //cout << "You don't have arrows to shoot! " << endl;
      flag = 2;
    }
  }
  return flag;
}


int Game::shoot_left(string choice){
  int flag = 0;
  arrowX = playerX;
  arrowY = playerY;

  if (choice == " a"){ // left
    if (arrow_num>0){
    flag = 1;
    for(int i = 0; i<3; i++){
  // check for border 
      if(arrowX == 0){
        cout << "Arrow hits the wall! " << endl;
        break;
      }

  arrowX = arrowX-1;
  if (game_board[arrowY][arrowX].get_name() == "W"){
    cout << "You killed the Wumpus!" << endl;
    if_w_killed = 1;
    game_board[arrowY][arrowX].set_name(" ");
    
    wumpusY = -1;
    wumpusX = -1;
      break;
      }
    }
// to test use this : \/
//  game_board[arrowY][arrowX].set_name(">");

  if (if_w_killed != 1){
    cout << "Arrow missed !" << endl;
    wumpus_teleport();
  }
  arrow_num--;
    }
    else{
      //cout << "You don't have arrows to shoot! " << endl;
      flag = 2;
    }
  }
  return flag;
}


int Game::shoot_right(string choice){
  int flag = 0;
  arrowX = playerX;
  arrowY = playerY;

  if (choice == " d"){ // right
    if (arrow_num>0){
    flag = 1;
    for(int i = 0; i<3; i++){
  // check for border 
      if(arrowX == square_size-1){
        cout << "Arrow hits the wall! " << endl;
        break;
      }

  arrowX = arrowX+1;
  if (game_board[arrowY][arrowX].get_name() == "W"){
    cout << "You killed the Wumpus!" << endl;
    if_w_killed = 1;
    game_board[arrowY][arrowX].set_name(" ");
    
    wumpusY = -1;
    wumpusX = -1;

      break;
      }
    }
// to test use this : \/
//  game_board[arrowY][arrowX].set_name(">");
  if (if_w_killed != 1){
  cout << "Arrow missed !" << endl;
  wumpus_teleport();
  }
  arrow_num--;
    }
    else{
      //cout << "You don't have arrows to shoot! " << endl;
      flag = 2;
    }
  }

  return flag;
}


void Game::wumpus_teleport(){
if (if_w_killed == 0){

int chance = rand()%4; // 0 to 3: (1,2,3,4) 75/100 = 3/4
cout << "chance: " << chance << endl;
  if(chance !=0){ //1,2,3 = 75%
    do {
      game_board[wumpusY][wumpusX].set_name(" ");//erase the previous wumpus position
      wumpusX = rand()%square_size;
      wumpusY = rand()%square_size;
      }
    while ( game_board[wumpusY][wumpusX].get_name()!= " ");
  }
  if(chance !=0){
  cout << "Since you missed an arrow, the Wumpus had to move to a different room with 75% probability... 75% came true and Wumpus got teleported to a new random empty room." << endl;
  game_board[wumpusY][wumpusX].set_name("W");
  }
  if(chance == 0){
    cout <<"Since you missed an arrow, the Wumpus had to move to a different room with 75% probability, however a 25% chance has occurred, so nothing has happend. " << endl;
    }
  }
}

void Game::player_teleport(){
  //angry bat grabs the player and takes him to some other random room (which could be dangerous!).
  game_board[playerY][playerX].set_name(" ");//erase the previous wumpus position
  playerX = rand()%square_size;
  playerY = rand()%square_size;

  cout << "You got teleported to a new random room. " << endl;

  game_board[playerY][playerX].set_name("*");
  check_for_event();
}

void Game::meet_the_wumpus(){
  if ((playerY == wumpusY) && (playerX == wumpusX)){
    game_board[playerY][playerX].wumpus_event();

    game_over = 1;
    if_lost = 1;
  }
}

void Game::meet_the_pits(){
  if ((playerY == pit1Y) && (playerX == pit1X)){
    game_board[playerY][playerX].pit_event();

    game_over = 1;
    if_lost = 1;
  }

  if ((playerY == pit2Y) && (playerX == pit2X)){
    game_board[playerY][playerX].pit_event();

    game_over = 1;
    if_lost = 1;
  }
}

void Game::meet_the_bats(){
  
  if ((playerY == bat1Y) && (playerX == bat1X)){
    game_board[playerY][playerX].bat_event();
    player_teleport();
    bat1Y = -1; //erase event from the map, since it is used
    bat1X = -1; 
  }

  if ((playerY == bat2Y) && (playerX == bat2X)){
    game_board[playerY][playerX].bat_event();
    //game_board[playerY][playerX].erase_event();
    player_teleport();
    bat2Y = -1;
    bat2X = -1; 
  }
}

void Game::meet_the_gold(){
  if ((playerY == goldY) && (playerX == goldX)){
    game_board[playerY][playerX].gold_event();
    gold_found = 1;
    goldX = -1;
    goldY = -1;
  }
}

void Game::is_wumpus_close(){
  if ((playerY == wumpusY) && (playerX == wumpusX-1)){
    //cout << "Wumpus sleeps to your right! " << endl;
    game_board[playerY][playerX].wumpus_percept();
  }

  if ((playerY == wumpusY) && (playerX == wumpusX+1)){
    //cout << "Wumpus sleeps to your left! " << endl;
    game_board[playerY][playerX].wumpus_percept();
  }

  if ((playerY == wumpusY-1) && (playerX == wumpusX)){
    //cout << "Wumpus sleeps right under you! " << endl;
    game_board[playerY][playerX].wumpus_percept();
  }

  if ((playerY == wumpusY+1) && (playerX == wumpusX)){
    //cout << "Wumpus sleeps right above you! " << endl;
    game_board[playerY][playerX].wumpus_percept();
  }
}

void Game::is_gold_close(){
  if ((playerY == goldY) && (playerX == goldX-1)){
    //cout << "Gold is located to your right! " << endl;
    game_board[playerY][playerX].gold_percept();
  }

  if ((playerY == goldY) && (playerX == goldX+1)){
    //cout << "Gold is located to your left! " << endl;
    game_board[playerY][playerX].gold_percept();
  }

  if ((playerY == goldY-1) && (playerX == goldX)){
    //cout << "Gold is located right under you! " << endl;
    game_board[playerY][playerX].gold_percept();
  }

  if ((playerY == goldY+1) && (playerX == goldX)){
    //cout << "Gold is located right above you! " << endl;
    game_board[playerY][playerX].gold_percept();
  }
}

void Game::is_pit_close(){
  if (((playerY == pit1Y) && (playerX == pit1X-1)) || ((playerY == pit2Y) && (playerX == pit2X-1))) {
    //cout << "One of the pits is to your right! " << endl;
    game_board[playerY][playerX].pit_percept();
  }

  if (((playerY == pit1Y) && (playerX == pit1X+1)) || ((playerY == pit2Y) && (playerX == pit2X+1))) {
    //cout << "One of the pits is to your left! " << endl;
    game_board[playerY][playerX].pit_percept();
  }

  if (((playerY == pit1Y-1) && (playerX == pit1X)) || ((playerY == pit2Y-1) && (playerX == pit2X))) {
    //cout << "One of the pits is right under you! " << endl;
    game_board[playerY][playerX].pit_percept();
  }

  if (((playerY == pit1Y+1) && (playerX == pit1X)) || ((playerY == pit2Y+1) && (playerX == pit2X))) {
    //cout << "One of the pits is right above you! " << endl;
    game_board[playerY][playerX].pit_percept();
  }
}

void Game::is_bat_close(){
  if (((playerY == bat1Y) && (playerX == bat1X-1)) || ((playerY == bat2Y) && (playerX == bat2X-1))) {
    //cout << "One of the bats is to your right! " << endl;
    game_board[playerY][playerX].bat_percept();
  }

  if (((playerY == bat1Y) && (playerX == bat1X+1)) || ((playerY == bat2Y) && (playerX == bat2X+1))) {
    //cout << "One of the bats is to your left! " << endl;
    game_board[playerY][playerX].bat_percept();
  }

  if (((playerY == bat1Y-1) && (playerX == bat1X)) || ((playerY == bat2Y-1) && (playerX == bat2X))) {
    //cout << "One of the bats is right under you! " << endl;
    game_board[playerY][playerX].bat_percept();
  }

  if (((playerY == bat1Y+1) && (playerX == bat1X)) || ((playerY == bat2Y+1) && (playerX == bat2X))) {
    //cout << "One of the bats is right above you! " << endl;
    game_board[playerY][playerX].bat_percept();
  }
}


void Game::print_status(){
  cout << "Arrows left: " << arrow_num << endl;
  if (gold_found == 0){
    cout << "Is gold found: no " << endl;
  }
  if (gold_found == 1){
    cout << "Is gold found: yes " << endl;
  }
  if (if_w_killed == 1){
    cout << "Is Wumpus killed: yes " << endl;
  }
  if (if_w_killed == 0){
    cout << "Is Wumpus killed: no " << endl;
  }
}

void Game::check_for_win(){

  if ((playerX == escape_roomX) && (playerY == escape_roomY) && (gold_found == 1)){
    cout << "You successfully exited the cave and stole Wumpus's gold !" << endl;
    game_over = 1;
    if_won = 1;
  }
}

void Game::play_cheat_game(){
  print_cheat_board();

  do{
  make_moove();
  if (game_over == 0){
    print_cheat_board();

    print_status();
  }

  if (game_over == 0){
    is_wumpus_close();
    is_pit_close();
    is_bat_close();
    is_gold_close();
  }

  check_for_win();
  }
  while (game_over == 0);
}

int Game::get_if_lost(){
  return this->if_lost;
}

int Game::get_if_won(){
  return this->if_won;
}

void Game::play_normal_game(){

  print_normal_board();

  do{
  make_moove();
  if (game_over == 0){
    print_normal_board();
    print_status();
  }

  if (game_over == 0){
    is_wumpus_close();
    is_pit_close();
    is_bat_close();
    is_gold_close();
  }

  check_for_win();
  }
  while (game_over == 0);
}


//If the adventurer perishes while searching for the Wumpus, the player should be presented with the option to start the game over with the same cave configuration, start the game over with a new random cave configuration, or quit the game entirely.

Game::Game(const Game& old_game){
 //cout << "Invoked the copy constructor!" << endl;
  this-> square_size = old_game.square_size;
  this-> game_board = old_game.game_board;
  this-> arrow_num = old_game.arrow_num;

  this-> playerX = old_game.playerX;
  this-> playerY  = old_game.playerY;

  this->escape_roomX =  old_game.escape_roomX;
  this->escape_roomY =  old_game.escape_roomY;

  this-> arrowX = old_game.arrowX;
  this-> arrowY = old_game.arrowY;

  this-> wumpusX = old_game.wumpusX;
  this-> wumpusY = old_game.wumpusY;

  this-> pit1X = old_game.pit1X;
  this-> pit1Y = old_game.pit1Y;

  this-> pit2X = old_game.pit2X;
  this-> pit2Y = old_game.pit2Y;

  this-> bat1X = old_game.bat1X;
  this-> bat1Y = old_game.bat1Y;

  this-> bat2X = old_game.bat2X;
  this-> bat2Y = old_game.bat2Y;

  this-> goldX = old_game.goldX;
  this-> goldY = old_game.goldY;

  this-> game_over = old_game.game_over;
  this-> if_lost = old_game.if_lost;
  this-> if_won = old_game.if_won;
  this-> if_w_killed = old_game.if_w_killed;
  this-> gold_found = old_game.gold_found;
  this-> if_cheat_mode = old_game.if_cheat_mode;

}


Game& Game::operator=(const Game& old_game) {
  cout << "Invoked the overloaded assignment operator" << endl; 
  this-> square_size = old_game.square_size;
  this-> game_board = old_game.game_board;
  this-> arrow_num = old_game.arrow_num;

  this-> playerX = old_game.playerX;
  this-> playerY  = old_game.playerY;

  this->escape_roomX =  old_game.escape_roomX;
  this->escape_roomY =  old_game.escape_roomY;

  this-> arrowX = old_game.arrowX;
  this-> arrowY = old_game.arrowY;

  this-> wumpusX = old_game.wumpusX;
  this-> wumpusY = old_game.wumpusY;

  this-> pit1X = old_game.pit1X;
  this-> pit1Y = old_game.pit1Y;

  this-> pit2X = old_game.pit2X;
  this-> pit2Y = old_game.pit2Y;

  this-> bat1X = old_game.bat1X;
  this-> bat1Y = old_game.bat1Y;

  this-> bat2X = old_game.bat2X;
  this-> bat2Y = old_game.bat2Y;

  this-> goldX = old_game.goldX;
  this-> goldY = old_game.goldY;

  this-> game_over = old_game.game_over;
  this-> if_lost = old_game.if_lost;
  this-> if_won = old_game.if_won;
  this-> if_w_killed = old_game.if_w_killed;
  this-> gold_found = old_game.gold_found;
  this-> if_cheat_mode = old_game.if_cheat_mode;

  return *this;
}

void Game::set_if_cheat_mode(int if_cheat_mode){
  this->if_cheat_mode = if_cheat_mode;
}