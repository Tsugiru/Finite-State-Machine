#ifndef STATE_H
#define STATE_H 

#include <string>
#include <iostream>
#include <vector>
#include <functional>

class Interaction; //! forward declaration 
class States; //! class prototype 

class State {
private:
	std::string state_name;	//! Name of the state
	Interaction * interaction; //! interaction this state belongs to
public:
	State();	//! Default Constructor
	State(std::string _state_name);	//! Parametrize Constructor
	std::string getName() const;	//! Returns state_name
	void set_interaction(Interaction * interaction);
	bool part_of_interaction();		//! Returns true if this State is part of an interaction

	void interaction_ready(); 

	void setName(std::string);	//! Sets state_name
	States operator+(const State & rhs);	//! Creates and returns an object "States" 
											//! containing only two states
	States operator+(States ss);	//! Returns an object "States" consisting
									//! of the one on the rhs in addition to
									//! the "State" object on the lhs
	bool operator==(const State & rhs) const;	//! Overloads the == operator to compare
												//! two states by comparing their names

	struct state_hash { //! Hash function that allows the use of State objects in unordered maps
		size_t operator()(const State & s) const;
	};

};

std::ostream & operator<<(std::ostream &os, const State & rhs);	//! Overloaded insertion operator to print States

class States {
private:
	std::vector<State> state_vector; //! Stores multiple "State" objects
public:
	States() {} //! Default Constructor
	States(std::vector<State> &_state_vector); //! Parametrized Constructor
	State get(int index) const; //! Returns the state at a given index of the vector
	bool contains(State s); //! Returns whether the vector contains a given State s
	size_t size() const; //! Returns the size of the vector, i.e. the number of State objects
	void set(int index, const State &s); //! Sets the state at a given index of the vector
	void remove(); //! Removes the last element of the vector

	States & add(const State &s); //! Appends a State object to the vector
	States & operator+=(const State & rhs);	//! Overloads the += operator to append
											//! a State object on the RHS
											//! to a States object on the LHS

	States operator+(const State & rhs);	//! Overloads the + operator to return a new
											//! States object consisting of the one on
											//! the LHS in addition to the State on the RHS
	void print(); //! Prints the names of all of the states
};

#endif
