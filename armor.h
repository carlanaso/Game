#ifndef ARMOR_H
#define ARMOR_H 

#include "event.h"


using namespace std;

class Armor : public Event {

public:

    Armor();

    ~Armor();
    
    void percept() const override;
    bool encounter() override;
    Event* clone() const override;
};
#endif