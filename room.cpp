/*
	Room Class
*/
#include <iostream>
#include "room.h"


using namespace std;

Room::Room() {
	
  name = " ";
  events = nullptr;

}

Room::~Room(){
  if (events != nullptr){
    delete events;  
  }
}

Room::Room(string name){
  this-> name = name;
}

string Room::get_name() {
	return name;
}

void Room::set_name(string name) {
  this->name = name;
}

void Room::wumpus_event(){
  if (events != nullptr){
    delete events;  
  }

  events = new Wumpus;
  events->encounter();
}

void Room::pit_event(){
  if (events != nullptr){
    delete events;  
  }

  events = new Pit;
  events->encounter();
}

void Room::bat_event(){
  if (events != nullptr){
    delete events;  
  }

  events = new Bats;
  events->encounter();
}

void Room::gold_event(){
  if (events != nullptr){
    delete events;  
  }

  events = new Gold;
  events->encounter();
}

void Room::wumpus_percept(){
  if (events != nullptr){
    delete events;  
  }

  events = new Wumpus;
  events->percept();
}

void Room::pit_percept(){
  if (events != nullptr){
    delete events;  
  }

  events = new Pit;
  events->percept();
}

void Room::bat_percept(){
  if (events != nullptr){
    delete events;  
  }

  events = new Bats;
  events->percept();
}

void Room::gold_percept(){
  if (events != nullptr){
    delete events;  
  }

  events = new Gold;
  events->percept();
}
