#ifndef STALACTITES_H
#define STALACTITES_H 

#include "event.h"

class Stalactites : public Event {
public:
    
    Stalactites();

    ~Stalactites();

    void percept() const override;
    bool encounter() override;
    Event* clone() const override;
};

#endif