#include <iostream>
#include <cstdlib>
#include <ctime>
#include "game.h"
#include <string>
using namespace std;


int main() {
    srand(time(NULL));

    int wid = 5, len = 5;
    string debugInput;
    bool debug = false;

    while (true) {
        cout << "Enter the width of the cave (min 4, max 50): ";
        cin >> wid;
        if (cin.fail() || wid < 4 || wid > 50) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Please enter a valid width (4 to 50)." << endl;
            continue;
        }

        cout << "Enter the length of the cave (min 4, max 50): ";
        cin >> len;
        if (cin.fail() || len < 4 || len > 50) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Please enter a valid length (4 to 50)." << endl;
            continue;
        }

        cout << "Do you want to enable debug mode? (T/F): ";
        cin >> debugInput;
        if (debugInput != "T" && debugInput != "F") {
            cout << "Invalid input. Please enter 'T' or 'F'." << endl;
            continue;
        }

        debug = (debugInput == "T");
        break; // Break the loop if all inputs are valid
    }

    Game g;
    g.play_game(wid, len, debug);

    return 0;
}