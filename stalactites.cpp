/******************************************************
** Program: stalactites.cpp
** Author: Carlana So
** Date: 11/20/2023
** Description:Implementation of the Stalactites class
** Input:None
** Output:None
******************************************************/

#include "stalactites.h"

#include <iostream>

using namespace std;

/*********************************************************************
** Function: Stalactites (Constructor)
** Description: Initializes a Stalactites event.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: A Stalactites event is created.
*********************************************************************/
Stalactites::Stalactites() {
    this->event_char = 'S';
}

/*********************************************************************
** Function: percept
** Description: Prints a percept message for encountering Stalactites.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: A percept message is printed to the console.
*********************************************************************/
void Stalactites::percept() const {
    cout << "You hear water dripping." << endl;
}

/*********************************************************************
** Function: encounter
** Description: Handles the encounter with Stalactites.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Returns true if the game should end, false otherwise.
*********************************************************************/
bool Stalactites::encounter() {
    int chance = rand() % 2; // 50% chance
    if (chance == 0) {
        cout << "A stalactite falls and hits you. Game over!" << endl;
        return true; // Game should end
    } else {
        cout << "You narrowly avoid a falling stalactite." << endl;
        return false; // Game continues
    }
}

/*********************************************************************
** Function: Event* Wumpus::clone() const
** Description: Creates a dynamically allocated clone of the Wumpus object.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Returns a pointer to a new Wumpus object that is a copy of the current object.
*********************************************************************/

Event* Stalactites::clone() const {
    return new Stalactites(*this);
}