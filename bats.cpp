/******************************************************
** Program: bats.cpp
** Author: Carlana So
** Date: 11/20/2023
** Description:Implementation of the Bats class
** Input:None
** Output:None
******************************************************/
#include "bats.h"

#include <iostream>

using namespace std;

//Bats Implementation
/*********************************************************************
** Function: Bats::Bats()
** Description: Constructor for the Bats class. Sets the event character for Bats.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Event character for Bats is set to 'B'.
*********************************************************************/
Bats::Bats() {
    this->event_char = 'B';
}


/*********************************************************************
** Function: void Bats::percept() const
** Description: Provides a percept message when encountering Bats. Prints "You hear wings flapping."
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: None
*********************************************************************/
void Bats::percept() const {
    cout << "You hear wings flapping." << endl;
}

/*********************************************************************
** Function: bool Bats::encounter()
** Description: Handles the encounter with Bats. Prints a message, sets the confusion state, and initializes the confusion turns.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Bats may confuse the player's sense of direction.
*********************************************************************/
bool Bats::encounter() {
    cout << "A bat grabs you and confuses your sense of direction!" << endl;
    isConfused = true;
    confusion_turns = 5;
    return false;
}

/*********************************************************************
** Function: void Bats::update_confusion()
** Description: Updates the confusion state of Bats. If the confusion turns have expired, the confusion state is set to false.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: The confusion state of Bats may be updated.
*********************************************************************/
void Bats::update_confusion() {
    if (isConfused && --confusion_turns <= 0) {
        isConfused = false;
    }
}

/*********************************************************************
** Function: bool Bats::is_confused() const
** Description: Checks if Bats have confused the player's sense of direction.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Returns true if the player is confused by Bats, false otherwise.
*********************************************************************/
bool Bats::is_confused() const {
    return isConfused; // Use the renamed member variable
}

void Bats::decrease_confusion_turns() {
    if (confusion_turns > 0) {
        confusion_turns--;
        if (confusion_turns == 0) {
            isConfused = false;
        }
    }
}

Event* Bats::clone() const {
    return new Bats(*this);
}