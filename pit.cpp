#include "pit.h"
#include <iostream>

using namespace std;


Pit::Pit(){

}

Pit::~Pit(){

}

void Pit::percept(){
  cout << "You feel a breeze." << endl;
}

void Pit::encounter() {
  cout << "You got into the bottomless pit and died :( " << endl;
}
