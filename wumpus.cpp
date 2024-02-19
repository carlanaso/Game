/******************************************************
** Program: wumpus.cpp
** Author: Carlana So
** Date: 11/20/2023
** Description:Implementation of the Wumpus class
** Input:None
** Output:None
******************************************************/
#include "wumpus.h"

#include <iostream>

using namespace std;

//Wumpus Implementation
/*********************************************************************
** Function: Wumpus (Constructor)
** Description: Initializes a Wumpus event.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: A Wumpus event is created.
*********************************************************************/

Wumpus::Wumpus() {
    this->row = -1;
    this->col = -1;
    this->is_killed = false;
    this->event_char = 'W';
}
/*********************************************************************
** Function: setPosition
** Description: Sets the position of the Wumpus on the game board.
** Parameters: newRow - the new row position, newCol - the new column position
** Pre-Conditions: None
** Post-Conditions: The Wumpus's position is updated.
*********************************************************************/

void Wumpus::setPosition(int newRow, int newCol) {
    row = newRow;
    col = newCol;
}
/*********************************************************************
** Function: getRow
** Description: Gets the row position of the Wumpus.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Returns the row position of the Wumpus.
*********************************************************************/

int Wumpus::getRow() const {
    return row;
}

/*********************************************************************
** Function: getCol
** Description: Gets the column position of the Wumpus.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Returns the column position of the Wumpus.
*********************************************************************/
int Wumpus::getCol() const {
    return col;
}

/*********************************************************************
** Function: kill
** Description: Marks the Wumpus as killed.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: The Wumpus is marked as killed.
*********************************************************************/
void Wumpus::kill() {
    is_killed = true;
}

/*********************************************************************
** Function: isKilled
** Description: Checks if the Wumpus is killed.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Returns true if the Wumpus is killed, false otherwise.
*********************************************************************/
bool Wumpus::isKilled() const {
    return is_killed;
}

/*********************************************************************
** Function: percept
** Description: Prints a percept message for encountering the Wumpus.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: A percept message is printed to the console.
*********************************************************************/
void Wumpus::percept() const {
    cout << "You smell a terrible stench." << endl;
}

/*********************************************************************
** Function: encounter
** Description: Handles the encounter with the Wumpus.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Returns true if the game should end, false otherwise.
*********************************************************************/
bool Wumpus::encounter() {
    cout << "You've encountered the Wumpus!" << endl;
    return true;
}

/*********************************************************************
** Function: Event* Wumpus::clone() const
** Description: Creates a dynamically allocated clone of the Wumpus object.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Returns a pointer to a new Wumpus object that is a copy of the current object.
*********************************************************************/

Event* Wumpus::clone() const {
    return new Wumpus(*this);
}