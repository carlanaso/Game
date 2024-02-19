
/******************************************************
** Program: game.cpp
** Author: Carlana So
** Date: 11/20/2023
** Description:Implementation of the game class
** Input:None
** Output:None
******************************************************/
#include "game.h"
#include "gold.h"
#include "wumpus.h"
#include "bats.h"
#include "stalactites.h"
#include "room.h"
#include "armor.h"
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

//Game Implementation
/*********************************************************************
** Function: Game::Game()
** Description: Constructor for the Game class. Initializes game state.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: A new game object is created with default settings.
*********************************************************************/
Game::Game(){
	this->length = 0;
	this->width = 0;
	this->num_arrows = 3;
	this->debug_view = false;
	this->player_row = 0;
    this->player_col = 0;
    this->escape_row = 0;
    this->escape_col = 0;
	this->fell_into_pit = false;
    this->foundgold = false;
    this->confused_by_bats = nullptr;
    this->has_armor = false;
    this->armor_protection = 2;
    this->number_of_bats = 2;
    
	this->board = vector<vector<Room>>(length, vector<Room>(width));
}
/*********************************************************************
** Function: Game::~Game()
** Description: Destructor for the Game class. Cleans up memory and resources.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: All dynamically allocated event objects are deleted, and the board is cleared.
*********************************************************************/
Game::~Game() {
         for (auto &row : board) {
        for (auto &room : row) {
            delete room.getEvent(); // Deletes the event if it exists
        }
    }
}
    



/*********************************************************************
** Function: void Game::set_up(int l, int w)
** Description: Set up the game board with the specified dimensions and place events.
** Parameters: l - length of the board, w - width of the board
** Pre-Conditions: None
** Post-Conditions: The game board is initialized with events placed on it.
*********************************************************************/
void Game::set_up(int l, int w) {
    this->length = l;
    this->width = w;
    this->num_arrows = 3;
    for (auto &row : board) {
        for (auto &room : row) {
            delete room.getEvent(); // Deletes the event if it exists
        }
    }

    this->board.clear(); // Clear the existing board
    this->board.resize(l, std::vector<Room>(w));

    player_row = escape_row = rand() % length;
    player_col = escape_col = rand() % width;

    for (int i = 0; i < 7; ++i) {
        int row_idx, col_idx;
        do {
            row_idx = rand() % this->length;
            col_idx = rand() % this->width;
        } while (!board[row_idx][col_idx].is_empty());

        Event* newEvent = nullptr;
        switch(i) {
            case 0: newEvent = new Gold(); break;
            case 1: newEvent = new Wumpus(); break;
            case 2: case 3: newEvent = new Bats(); break;
            case 4: case 5: newEvent = new Stalactites(); break;
            case 6: newEvent = new Armor(); break;
        }

        if (!board[row_idx][col_idx].is_empty()) {
            delete board[row_idx][col_idx].getEvent();  // Delete the old event if it exists
        }
        board[row_idx][col_idx].assign(newEvent);
    }
}

/*********************************************************************
** Function: void Game::display_game() const
** Description: Display the current state of the game board.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: The current game board is displayed with player and event positions.
*********************************************************************/
void Game::display_game() const {
    cout << endl << "Arrows remaining: " << this->num_arrows << endl;
    string horizontalLine = "+";
    for (int i = 0; i < this->width; ++i) {
        horizontalLine += "---+";
    }
    cout << horizontalLine << endl;

    for (int i = 0; i < this->length; ++i) {
        for (int j = 0; j < this->width; ++j) {
            cout << "|";  // Left border of each cell

            if (i == player_row && j == player_col) {
                cout << " * ";  // Player's position
            } else if (i == escape_row && j == escape_col) {
                cout << " E ";  // Escape rope position
            } else if (debug_view && !board[i][j].is_empty()) {
                char eventChar = board[i][j].getEvent()->get_event_char();
                cout << eventChar << "  ";
            } else {
                cout << "   ";  // Empty cell
            }
        }
        cout << "|\n"; 
        cout << horizontalLine << endl;
    }
}
			//The next two chars indicate the event in the room
			//if the room does not have an event, print "  ||" (2 spaces + ||)
			
			//else, 
				//if debug is true
					//print the corresponding char of the event
				//else
					//print " " (1 space)
				// print " ||" (1 space + ||)

			//Fix the following...
		
// 		}
// 		cout << endl;
// 	}
// 	cout << line << endl;

// 	//example output (when finished): 
// 	// --------------------
// 	//  B || G || B ||   ||
// 	// --------------------
// 	//    || W ||   || S ||
// 	// --------------------   
// 	//    ||   ||   || S ||
// 	// --------------------   
// 	// *  ||   ||   ||   ||
// 	// --------------------
// }
// }
/*********************************************************************
** Function: bool Game::check_win() const
** Description: Check if the game has reached a win or lose condition.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Returns true if the player has won or lost, otherwise returns false.
*********************************************************************/
bool Game::check_win() const {
    // Check if Wumpus is killed - Player wins
    for (int i = 0; i < length; ++i) {
        for (int j = 0; j < width; ++j) {
            Event* event = board[i][j].getEvent();
            Wumpus* wumpus = dynamic_cast<Wumpus*>(event);
            if (wumpus != nullptr && wumpus->isKilled()) {
                cout << "Congratulations! You have killed the Wumpus!" << endl;
                return true;
            }
        }
    }

    // Check if player walks into Wumpus - Player loses
    Event* currentEvent = board[player_row][player_col].getEvent();
    if (dynamic_cast<Wumpus*>(currentEvent) != nullptr) {
        cout << "You walked into the Wumpus! Game over." << endl;
        return true;
    }

    // Check if player escapes with gold - Player wins
    if (foundgold && player_row == escape_row && player_col == escape_col) {
        cout << "You have successfully escaped with the gold! You win!" << endl;
        return true;
    }

    return false; // Game continues
}

/*********************************************************************
** Function: void Game::move_up()
** Description: Move the player character up (north) on the game board.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: The player's position is updated, and confusion state is handled if applicable.
*********************************************************************/
void Game::move_up(bool fromConfusion = false) {
    if (confused_by_bats && confused_by_bats->is_confused() && !fromConfusion) {
        move_down(true); // Inverted movement due to confusion, passing true to avoid further recursion
        confused_by_bats->update_confusion(); // Update confusion state
    } else if (player_row > 0) {
        player_row--;
    } else {
        cout << "You cannot move further up. You are at the edge of the cave." << endl;
    }

    if (confused_by_bats && !fromConfusion) {
        confused_by_bats->decrease_confusion_turns();
    }
}
/*********************************************************************
** Function: void Game::move_down()
** Description: Move the player character down (south) on the game board.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: The player's position is updated, and confusion state is handled if applicable.
*********************************************************************/
void Game::move_down(bool fromConfusion = false) {
    if (confused_by_bats && confused_by_bats->is_confused()) {
        move_up(true); // Inverted movement due to confusion
        confused_by_bats->update_confusion(); // Update confusion state
    } else if (player_row < length - 1) { // Check if player is not at the bottom edge
        player_row++; // Increase to move down
    } else {
        cout << "You cannot move further up. You are at the edge of the cave." << endl;
    }
    
    if (confused_by_bats && !fromConfusion) {
        confused_by_bats->decrease_confusion_turns();
    }
}

/*********************************************************************
** Function: void Game::move_left()
** Description: Move the player character left (west) on the game board.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: The player's position is updated, and confusion state is handled if applicable.
*********************************************************************/
void Game::move_left(bool fromConfusion = false) {
    if (confused_by_bats && confused_by_bats->is_confused() && !fromConfusion) {
        move_right(true); // Inverted movement due to confusion, passing true to avoid further recursion
        confused_by_bats->update_confusion(); // Update confusion state
    } else if (player_col > 0) {
        player_col--; // Move left
    } else {
        cout << "You cannot move further left. You are at the edge of the cave." << endl;
    }

    if (confused_by_bats && !fromConfusion) {
        confused_by_bats->decrease_confusion_turns();
    }
}
/*********************************************************************
** Function: void Game::move_right()
** Description: Move the player character right (east) on the game board.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: The player's position is updated, and confusion state is handled if applicable.
*********************************************************************/
void Game::move_right(bool fromConfusion = false) {
    if (confused_by_bats && confused_by_bats->is_confused() && !fromConfusion) {
        move_left(true); // Inverted movement due to confusion
        confused_by_bats->update_confusion(); // Update confusion state
    } else if (player_col < width - 1) {
        player_col++; // Move right
    } else {
        cout << "You cannot move further right. You are at the edge of the cave." << endl;
    }

    if (confused_by_bats && !fromConfusion) {
        confused_by_bats->decrease_confusion_turns();
    }
}

/*********************************************************************
** Function: char Game::get_dir()
** Description: Get the direction for firing an arrow from the player.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Returns the direction chosen by the player (w, a, s, d).
*********************************************************************/
char Game::get_dir() {
    char dir;
    cout << "Fire an arrow...." << endl;
    cout << "W-up" << endl;
    cout << "A-left" << endl;
    cout << "S-down" << endl;
    cout << "D-right" << endl;
    cout << "Enter direction (w, a, s, d): " << endl;

    cin >> dir;

    if (cin.fail() || dir != 'w' || dir != 'a' || dir != 's' || dir != 'd') {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Please enter a valid direction (w, a, s, d): " << endl;
            
        }

    return dir;
}

/*********************************************************************
** Function: void Game::wumpus_move()
** Description: Move the Wumpus to an adjacent empty room.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Updates the Wumpus's position.
*********************************************************************/
void Game::wumpus_move() {
    // Find current Wumpus position
    int currentRow = -1, currentCol = -1;
    bool wumpusFound = false;

    for (int i = 0; i < length; ++i) {
        for (int j = 0; j < width; ++j) {
            if (dynamic_cast<Wumpus*>(board[i][j].getEvent()) != nullptr) {
                currentRow = i;
                currentCol = j;
                wumpusFound = true;
                break; // Break the inner loop
            }
        }
        if (wumpusFound) break; // Break the outer loop if Wumpus is found
    }

    // If Wumpus not found or is at the edge, return
    if (!wumpusFound) return;

    vector<pair<int, int>> possibleMoves;
    // Add coordinates of empty adjacent rooms to possibleMoves
    if (currentRow > 0 && board[currentRow - 1][currentCol].is_empty()) possibleMoves.push_back(make_pair(currentRow - 1, currentCol));
    if (currentRow < length - 1 && board[currentRow + 1][currentCol].is_empty()) possibleMoves.push_back(make_pair(currentRow + 1, currentCol));
    if (currentCol > 0 && board[currentRow][currentCol - 1].is_empty()) possibleMoves.push_back(make_pair(currentRow, currentCol - 1));
    if (currentCol < width - 1 && board[currentRow][currentCol + 1].is_empty()) possibleMoves.push_back(make_pair(currentRow, currentCol + 1));

    // If there are empty adjacent rooms, move the Wumpus to one of them
    if (!possibleMoves.empty()) {
        int randomIndex = rand() % possibleMoves.size();
        pair<int, int> newLocation = possibleMoves[randomIndex];

        // Move Wumpus to the new room
        Event* wumpus = board[currentRow][currentCol].getEvent();
        board[currentRow][currentCol].assign(nullptr); // Remove from current room
        board[newLocation.first][newLocation.second].assign(wumpus); // Place in new room

        // Optional: Update Wumpus's internal position if it has row/col attributes
        dynamic_cast<Wumpus*>(wumpus)->setPosition(newLocation.first, newLocation.second);
    }
}

/*********************************************************************
** Function: void Game::fire_arrow()
** Description: Fire an arrow in a specified direction and check for a hit.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Decrements the number of arrows and may kill the Wumpus.
*********************************************************************/
void Game::fire_arrow() {
    if (num_arrows <= 0) {
        cout << "No arrows left." << endl;
        return;
    }
    num_arrows--;

    char dir = get_dir();
    int arrowRow = player_row;
    int arrowCol = player_col;
    if (num_arrows == 0) {
        cout << "You've run out of arrows!" << endl;
    }
    for (int i = 0; i < 3; ++i) {
        // Arrow movement logic
        switch (dir) {
            case 'w': arrowRow--; break;
            case 's': arrowRow++; break;
            case 'a': arrowCol--; break;
            case 'd': arrowCol++; break;
        }

        if (arrowRow < 0 || arrowRow >= length || arrowCol < 0 || arrowCol >= width) {
            break;  // Arrow out of bounds
        }
        
        Event* event = board[arrowRow][arrowCol].getEvent();
        if (event != nullptr) {
            Wumpus* wumpus = dynamic_cast<Wumpus*>(event);
            if (wumpus != nullptr) {
                wumpus->kill();
                cout << "You've killed the Wumpus!" << endl;
                return;
            }
        }
    }
}

/*********************************************************************
** Function: void Game::move(char c)
** Description: Move the player character in the specified direction or fire an arrow.
** Parameters: c - The character representing the action ('w', 'a', 's', 'd', or 'f').
** Pre-Conditions: None
** Post-Conditions: The player's position is updated, and confusion state is handled if applicable.
*********************************************************************/
void Game::move(char c) {
    // Handle player's action: move or fire an arrow
    if (c == 'f') {
        fire_arrow();
    } else {
        // Actual movement logic
        switch(c) {
            case 'w':
                move_up();
                break;
            case 'a':
                move_left();
                break;
            case 's':
                move_down();
                break;
            case 'd':
                move_right();
                break;
        }
    }
    process_encounter();
}

/*********************************************************************
** Function: char Game::get_input()
** Description: Get the player's input for their next move.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Returns the player's input character ('w', 'a', 's', 'd', or 'f').
*********************************************************************/
char Game::get_input() {
    char c;
    do {
        cout << "Player move..." << endl;
        cout << "W-up" << endl;
        cout << "A-left" << endl;
        cout << "S-down" << endl;
        cout << "D-right" << endl;
        cout << "F-fire an arrow" << endl;
        cout << "Enter input: " << endl;
        cin >> c;
        if(cin.fail()) {
            cin.clear(); // Clears error flags
            cin.ignore(1000, '\n'); // Discards invalid input
            cout << "Invalid input. Please enter a valid number." << endl;
        } 
    } while (c != 'w' && c != 'a' && c != 's' && c != 'd' && c != 'f');

    return c;
}/*********************************************************************
** Function: void Game::play_game(int w, int l, bool d)
** Description: Play the game by setting up the initial state, taking player and Wumpus turns, and checking for a win condition.
** Parameters: 
**    w (int): The width of the game board.
**    l (int): The length of the game board.
**    d (bool): Debug mode flag.
** Pre-Conditions: None
** Post-Conditions: The game is played until a win condition is met.
*********************************************************************/
void Game::play_game(int w, int l, bool d) {
    set_up(w, l);
    debug_view = d;

    char input;

    while (!check_win()) {
        display_game();
        
        // Player's turn
        input = get_input();
        if (input == 'f' || input == 'F') {
            fire_arrow();
        } else {
            move(input); // Player moves
        }

        // Wumpus's turn to move
        wumpus_move();

        // Check if the game has ended (e.g., player has won, or other end conditions)
        if (check_win()) {
            break; // Exit the loop immediately if the game ends
        }
    }
}

/*********************************************************************
** Function: void Game::display_percepts_at()
** Description: Display percepts for adjacent rooms to the player's current position.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Percepts are displayed for adjacent rooms with events.
*********************************************************************/
void Game::display_percepts_at() {
    // Check North
    if (player_row > 0 && !board[player_row - 1][player_col].is_empty()) {
        board[player_row - 1][player_col].getEvent()->percept();
    }
    
    // Check South
    if (player_row + 1 < length && !board[player_row + 1][player_col].is_empty()) {
        board[player_row + 1][player_col].getEvent()->percept();
    }
    
    // Check East
    if (player_col + 1 < width && !board[player_row][player_col + 1].is_empty()) {
        board[player_row][player_col + 1].getEvent()->percept();
    }

    // Check West
    if (player_col - 1 >= 0 && !board[player_row][player_col - 1].is_empty()) {
        board[player_row][player_col - 1].getEvent()->percept();
    }
}

/*********************************************************************
** Function: void Game::process_encounter()
** Description: Process an encounter with an event in the current room.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: The encounter is processed, and events are removed or effects applied.
*********************************************************************/
void Game::process_encounter() {
    Room& currentRoom = board[player_row][player_col];
    if (!currentRoom.is_empty()) {
        Event* event = currentRoom.getEvent();
        if (auto* wumpus = dynamic_cast<Wumpus*>(event)) {
            if (has_armor) {
                has_armor = false; // Armor is used up
            } else {
                return;
            }
        }
        // Check if the encountered event is Bats
        if (auto* bats = dynamic_cast<Bats*>(event)) {
            confused_by_bats = bats;
            bats->encounter(); // Call encounter for bats
        }
        // Handle armor and gold pickups
        else if (auto* armor = dynamic_cast<Armor*>(event)) {
            if (!has_armor) { // Only pick up armor if the player doesn't already have it
                has_armor = true;
                armor_protection = 2;
                cout << "You've found armor! It will protect you from two fatal encounters." << endl;
                currentRoom.assign(nullptr); // Remove armor from room
            }
        } else if (auto* gold = dynamic_cast<Gold*>(event)) {
            foundgold = true;
            cout << "You've found the gold! Now find the escape rope to win!" << endl;
            currentRoom.assign(nullptr); // Remove gold from room
        } else {
            // Other encounters
            bool encountered = event->encounter();
            if (encountered && has_armor) {
                armor_protection--;
                cout << "Your armor protected you! Remaining protection: " << armor_protection << endl;
                if (armor_protection <= 0) {
                    has_armor = false;
                    cout << "Your armor is destroyed!" << endl;
                }
            }

            // Remove the event if it's a one-time encounter (not armor or gold)
            if (encountered) {
                currentRoom.assign(nullptr);
            }
        }
    }
    display_percepts_at();
}