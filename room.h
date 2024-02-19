#ifndef ROOM_H
#define ROOM_H 

#include "event.h"


#include <iostream>

using namespace std;

//Room Interface
//Note: Each room may be empty or has an event (bat, gold, pit, or wumpus);
//		Use event polymorphically

class Room
{
private:
	Event* e; //an event pointer, use it polymorphically
	bool has_player;
	
public:
	Room();
	~Room();
    Room(const Room& other);
	Room& operator=(const Room& other);
	//return true if the room is empty, false otherwise
	bool is_empty() const;

	//assign an event to the room
	void assign(Event*);
    void place_event(Event*);
    bool hasPlayer() const;
    void setPlayer(bool status);
    Event* getEvent() const;

};

#endif