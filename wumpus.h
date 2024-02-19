#ifndef WUMPUS_H
#define WUMPUS_H 

//Wumpus Interface
#include "event.h"

using namespace std;

class Wumpus : public Event {
    private:
        int row;          
        int col;          
        bool is_killed;
    public:
        Wumpus();

        ~Wumpus();

        void setPosition(int row, int col);
        int getRow() const;
        int getCol() const;
        void kill();
        bool isKilled() const;

        void percept() const override;
        bool encounter() override;
        Event* clone() const override;
};
#endif