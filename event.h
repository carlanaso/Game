#ifndef EVENT_H
#define EVENT_H 

using namespace std;

//Event Interface
//Note: this must be an abstract class!

class Event
{

protected:
	//option 1: declare a member varible
	char event_char;

public:
	//option 2: use pure virtual to return the event char
	//virtual char event_char() = 0; 
	
	Event();

	virtual Event* clone() const = 0;
	char get_event_char() const; 

    virtual void percept() const = 0;
    virtual bool encounter() = 0;
	
};
#endif