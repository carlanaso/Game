#ifndef GAME_H
#define GAME_H 

#include <vector>
#include <iostream> 
#include "room.h"
#include "bats.h"

using namespace std;

//Game interface 
class Game
{
private:
	
	//declare a 2D vector of Room objects:
	vector<vector<Room>> board;
	
	//other member variables:
	int length; 			//length of the board
	int width;  			//width of the board
	int num_arrows; 		//keep track of number of errors remaining
	bool debug_view;		//debug mode or not
	bool fell_into_pit;
	int player_row;
	int player_col;
	int escape_row;
    int escape_col;
	bool foundgold;
	Bats* confused_by_bats;
	int number_of_bats;
	bool has_armor;
    int armor_protection;
	//feel free to add more variables...

public:

	//suggested functions:
	Game();
	~Game();
	
	void set_up(int, int);

	void display_game() const;

	bool check_win() const;

	char get_dir();
	void wumpus_move();
	void fire_arrow();

	void move_up(bool);
	void move_down(bool);
	void move_left(bool);
	void move_right(bool);
	void move(char);

	char get_input();

	void play_game(int, int, bool);
	void display_percepts_around_player();
	
	//feel free (and you will need) to add more functions...
	
	void display_percepts_at();
	void process_encounter();
};
#endif