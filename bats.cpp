#include "bats.h"
#include <iostream>

using namespace std;

Bats::Bats(){

}

Bats::~Bats(){

}

void Bats::percept(){
  cout << "You hear wings flapping." << endl;
}

void Bats::encounter() {
  cout << "You met a bat! Angry bat grabs you and takes you to some other room (which can be dangerous!)." << endl;
}