#ifndef FSM_H
#define FSM_H

#include "transition.h"
#include "state.h"

class FSM {
private:
 	States Q;
	Transitions T;
	State q0;
	State curr;

public:
	FSM();
	FSM(States _Q, State _q0, Transitions _T);
	
	States getStates() const;
	State getInitialState() const;
	State getCurrentState()	

	void setStates(States _Q);
	void setInitialState(State _q0);
	void setTransitions(Transitions _T);
	
	void reset();	
	void reset(State s);	
	void printPorts();
	void printStates();
	void drawFSM();
};

#endif
