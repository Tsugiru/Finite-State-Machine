#ifndef TRANSITION_H
#define TRANSITION_H

#include <state.h>
#include <condition.h>
#include <action.h>
#include <port.h>
#include <vector>

class Transitions; //! Class Prototype

class Transition {
private:
	State start; //! Starting state 
	State destination; //! Destination state
	Port port; //! Port whose boolean value decides the validity of the transition
	Condition condition; //! Condition which should be met for the transition to be valid
	Action action; //! Action taken when the transition is executed

public:
	Transition(){};	//! Default constructor
	Transition(State _start, State _destination, Port _port, Condition _condition, Action _action);	//! Parametrized Constructor

	State getStart();	//! Returns the starting state
	State getDestination();	//! Returns the destination state
	Port getPort();	//! Returns the port
	Condition getCondition();	//! Returns the Condition
	Action getAction();	//! Returns the Action
        
	void setStart(State _start);	//! Sets the starting state
	void setDestination(State _destination);	//! Sets the destination state
	void setPort(Port _port);	//! Sets the port
	void setCondition(Condition _condition);	//! Sets the Condition
	void setAction(Action _action);	//! Sets the Action

	bool evaluate_condition();	//! Evaluates the condition and returns the result
	void execute_action();	//! Executes the action when the transition is taken
	bool valid();	//! Returns true if both the port is activated and the condition is met

	Transitions operator+(const Transition & rhs);  //! Overloads the + operator to add two
													//! transitions to a new "Transitions" object
	Transitions operator+(Transitions ts);	//! Overloads the + operator to append a Transition to a "Transitions" object
};

class Transitions {
private:
	std::vector<Transition> transition_vector; //! Stores multiple "Transition" objects
public:
	Transitions(){}	//! Default Constructor
	Transitions(std::vector<Transition> _transition_vector);	//! Parametrized Constructor
	size_t size() const;	//! Returns the size of the vector, i.e. the number of transitions
	std::vector<Transition> get();	//! Returns transition_vector
	Transition get(int index) const;	//! Returns the transition at a given index of the vector
	Transitions & add(const Transition &t);	//! Appends a Transition object to the vector
	Transitions & operator+=(const Transition &t);	//! Overloads the += operator to append
													//! a Transition object to the vector
	Transitions operator+(const Transition &t); //! Overloads the + operator to return a new
												//! Transitions object consisting of the one on
												//! the LHS in addition to the Transition on the RHS
	void set(int index, const Transition &s);	//! Sets the element at a given index of the vector
	void remove(); //! Removes the last element of the vector
	void remove(int index); //! Remove the element at a given index from the vector
};

#endif
