#include "wumpus.h"
#include <iostream>

using namespace std;


Wumpus::Wumpus(){

}

Wumpus::~Wumpus(){

}

void Wumpus::percept(){
  cout <<"You smell a terrible stench." << endl;
}

void Wumpus::encounter() {
  cout << "You see the Wumpus and die :( " << endl;
}