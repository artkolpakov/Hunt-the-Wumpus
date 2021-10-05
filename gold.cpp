#include "gold.h"
#include <iostream>

using namespace std;


Gold::Gold(){

}

Gold::~Gold(){

}

void Gold::percept(){
  cout << "You see a glimmer nearby." << endl;
}

void Gold::encounter() {
  cout << "You found the gold !!!" << endl;
}

