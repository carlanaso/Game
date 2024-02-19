/******************************************************
** Program: gold.cpp
** Author: Carlana So
** Date: 11/20/2023
** Description:Implementation of the gold class
** Input:None
** Output:None
******************************************************/
#include "gold.h"

#include <iostream>

using namespace std;

//Gold Implementation

/*********************************************************************
** Function: Gold::Gold()
** Description: Default constructor for the Gold class. Initializes the event character to 'G'.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: A Gold object is created with the event character set to 'G'.
*********************************************************************/
Gold::Gold() {
    this->event_char = 'G';
}

/*********************************************************************
** Function: void Gold::percept() const
** Description: Displays a percept message when the player is near the gold.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Prints a message to the console indicating that the player sees a glimmer nearby.
*********************************************************************/
void Gold::percept() const {
    cout << "You see a glimmer nearby." << endl;
}

/*********************************************************************
** Function: bool Gold::encounter()
** Description: Handles the encounter with the gold event.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Prints a message to the console indicating that the player has found gold and returns true.
*********************************************************************/
bool Gold::encounter() {
    cout << "You've found gold!" << endl;
    return true;
}

/*********************************************************************
** Function: Event* Gold::clone() const
** Description: Creates a dynamically allocated clone of the Gold object.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Returns a pointer to a new Gold object that is a copy of the current object.
*********************************************************************/

Event* Gold::clone() const {
    return new Gold(*this);
}