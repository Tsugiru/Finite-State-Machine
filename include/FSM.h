#ifndef FSM_H
#define FSM_H

#include <iostream>
#include <transition.h>
#include <state.h>
#include <unordered_map>

class FSM {
private:
    	States Q;
    	Transitions T;
    	State q0;
    	State curr;
	std::unordered_map<State, std::vector<Transition>, State::state_hash> adj_list;

public:
	FSM();
	FSM(States _Q, State _q0, Transitions _T);

	void run(int max_steps);
	
	States getStates() const;
	State getInitialState() const;
	State getCurrentState()	const;
	State getTransitions() const;

	void setStates(States _Q);
	void setInitialState(State _q0);
	void setTransitions(Transitions _T);

	void fillAdjList();	
	void reset();	
	void reset(State s);	
	void printPorts();
	void printStates();
	void drawFSM();
};

#endif
