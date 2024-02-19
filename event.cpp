/******************************************************
** Program: event.cpp
** Author: Carlana So
** Date: 11/20/2023
** Description:Implementation of the Event class
** Input:None
** Output:None
******************************************************/
#include "event.h"

#include <iostream>

using namespace std;

/*********************************************************************
** Function: Event::Event()
** Description: Default constructor for the Event class. Initializes the event character to a space ' '.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: An Event object is created with the event character set to ' '.
*********************************************************************/
Event::Event() {
    this->event_char = ' ';
}

/*********************************************************************
** Function: char Event::get_event_char() const
** Description: Returns the event character associated with this event.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Returns the event character (char) associated with this event.
*********************************************************************/
char Event::get_event_char() const {
    return this->event_char;
}