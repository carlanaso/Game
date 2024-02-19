#ifndef GOLD_H
#define GOLD_H 

#include "event.h"


using namespace std;


//Gold Interface
class Gold : public Event
{
public:
	Gold();
	~Gold();

	// char get_event_char() const;

	void percept() const override;
    bool encounter() override;
	Event* clone() const override;
};

#endif