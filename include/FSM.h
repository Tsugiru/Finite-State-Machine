#ifndef FSM_H
#define FSM_H

#include <iostream>
#include <fstream>
#include <transition.h>
#include <string>
#include <unordered_map>

class FSM {
private:
	States Q;	//! Set of all states
	Transitions T;	//! Set of all transitions
	State q0;	//! Initial state
	State curr;	//! Current position in the FSM after n iterations
	std::unordered_map<State, std::vector<Transition>, State::state_hash> adj_list;	//! Maps states to the transitions to which they are the starting state

public:
	FSM();	//! Default Constructor
	FSM(States _Q, State _q0, Transitions _T);	//! Sets Q, q0, curr and T and fills the adjacency list

	void run(int max_steps);	//! Runs the FSM for n steps where n <= max_steps
	
	States getStates() const;	//! Returns Q
	State getInitialState() const;	//! Returns q0
	State getCurrentState()	const;	//! Returns curr
	Transitions getTransitions() const; //! Returns T

	void setStates(States _Q);	//! Sets Q and fills the adjacency list anew
	void setInitialState(State _q0);	//! Sets q0
	void setTransitions(Transitions _T);	//! Sets T and fills the adjacency list anew

	void fillAdjList();	//! Fills the adjacency list by mapping states to the corresponding transitions.
	void reset();	//! Resets curr to q0
	void reset(State s);	//! Resets curr to s	
	void printPorts();	//! Prints the names of all ports and their status
	void printStates(); //! Prints the names of all of the states in Q
	void drawFSM(std::string filename); //! Generates a DOT graph represention of the FSM which can be used for visualization 
};

#endif
