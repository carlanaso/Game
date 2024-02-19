#ifndef BATS_H
#define BATS_H 

#include "event.h"
#include "event.h"

using namespace std;

class Bats : public Event {
    private:
    bool isConfused;
    int confusion_turns;
public:

    Bats();

    ~Bats();

    void percept() const override;
    bool encounter() override;
    bool is_confused() const;
    void update_confusion();
    void decrease_confusion_turns();
    Event* clone() const override;
};
#endif