/******************************************************
** Program: armor.cpp
** Author: Carlana So
** Date: 11/20/2023
** Description:Implementation of the ARmor class
** Input:None
** Output:None
******************************************************/
#include "armor.h"

#include <iostream>

using namespace std;

//Bats Implementation
/*********************************************************************
** Function: Armor::Armor()
** Description: Constructor for the Armor class. Sets the event character for Armor.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Event character for Armor is set to 'A'.
*********************************************************************/
Armor::Armor() {
    this->event_char = 'A';
}

/*********************************************************************
** Function: void Armor::percept() const
** Description: Provides a percept message when encountering Armor. Prints "You hear wings flapping."
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: None
*********************************************************************/
void Armor::percept() const {
    cout << "You feel the power." << endl;
}

/*********************************************************************
** Function: bool Armor::encounter()
** Description: Handles the encounter with Armor. Prints a message, sets the confusion state, and initializes the confusion turns.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Armor may confuse the player's sense of direction.
*********************************************************************/
bool Armor::encounter() {
    cout << "You find armor! You feel the power." << endl;
        return false;
}
/*********************************************************************
** Function: Event* Armor::clone() const
** Description: Creates a dynamically allocated clone of the Armor object.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Returns a pointer to a new Armor object that is a copy of the current object.
*********************************************************************/
Event* Armor::clone() const {
    return new Armor(*this);
}
