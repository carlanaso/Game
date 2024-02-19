#include "room.h"

using namespace std;

//Room Implementation
/*********************************************************************
** Function: Room::Room()
** Description: Constructor for the Room class. Initializes a room without events or players.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: A Room object is created with no events and no players.
*********************************************************************/

Room::Room() {

	//initialize the room so it doesn's have events or player
	
    this->e = nullptr;
	this->has_player = false;
    
    
}


/*********************************************************************
** Function: ~Room
** Description: Destructor for the Room class.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Deallocates memory for the event object if it exists.
*********************************************************************/
Room::~Room(){
	//cout << "~Room()" << endl;
	// if (this->e != nullptr){
	// 	delete this->e;
	// 	this->e = nullptr;
	// }
    
}

/*********************************************************************
** Function: Room (Copy Constructor)
** Description: Creates a copy of a Room object from another Room object.
** Parameters: const Room& other - The Room object to be copied.
** Pre-Conditions: None
** Post-Conditions: The current Room object is a copy of 'other'.
*********************************************************************/

Room::Room(const Room& other) {
    if (other.e != nullptr) {
        this->e = other.e->clone(); // Assuming Event class has a clone method for deep copy
    } else {
        this->e = nullptr;
    }
    this->has_player = other.has_player;
}

/*********************************************************************
** Function: operator=
** Description: Assignment operator for the Room class.
** Parameters: const Room& other - The Room object to be assigned.
** Pre-Conditions: None
** Post-Conditions: The current Room object is assigned the values of 'other'.
*********************************************************************/
Room& Room::operator=(const Room& other) {
    if (this != &other) {
        delete e; // Delete current event
        if (other.e != nullptr) {
            this->e = other.e->clone(); // Deep copy
        } else {
            this->e = nullptr;
        }
        this->has_player = other.has_player;
    }
    return *this;
}
/*********************************************************************
** Function: is_empty
** Description: Checks if the room is empty (no event).
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Returns true if the room is empty, false otherwise.
*********************************************************************/
bool Room::is_empty() const {
    if (e == nullptr) 
        return true; // Empty room
    
    return false;
}

/*********************************************************************
** Function: assign
** Description: Assigns a new event to the room.
** Parameters: Event *new_e - Pointer to the new event to be assigned.
** Pre-Conditions: None
** Post-Conditions: The room is assigned the new event.
*********************************************************************/
void Room::assign(Event *new_e){
    this->e = new_e;
}

/*********************************************************************
** Function: place_event
** Description: Places an event in the room if it is empty.
** Parameters: Event* event - Pointer to the event to be placed in the room.
** Pre-Conditions: None
** Post-Conditions: If the room is empty, it is assigned the new event.
*********************************************************************/
void Room::place_event(Event* event) {
    if (is_empty()) {
        assign(event);
    }
}

/*********************************************************************
** Function: hasPlayer
** Description: Checks if the room has a player.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Returns true if the room has a player, false otherwise.
*********************************************************************/
bool Room::hasPlayer() const {
    return has_player;
}

/*********************************************************************
** Function: setPlayer
** Description: Sets the player status in the room.
** Parameters: bool status - The player status (true if the room has a player, false otherwise).
** Pre-Conditions: None
** Post-Conditions: The player status in the room is updated.
*********************************************************************/
void Room::setPlayer(bool status) {
    has_player = status;
}

/*********************************************************************
** Function: getEvent
** Description: Gets the event pointer in the room.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Returns the event pointer in the room.
*********************************************************************/
Event* Room::getEvent() const {
    return e;
}