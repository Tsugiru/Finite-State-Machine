#ifndef STATE_H
#define STATE_H 

#include <string>
#include <iostream>
#include <vector>

class States; //class prototype 

class State {
private:
	std::string state_name;
public:
	State();
	State(std::string _state_name);
	std::string getName() const;
	void setName(std::string);
	bool isEqual(State s);
	bool operator==(State s);
	States operator+(const State & rhs); //Creates and returns an object "States" containing only two states
	States operator+(States ss); //Returns an object "States" consisting of the one on the rhs + the current one
};

//overloaded insertion operator to print States
std::ostream & operator<<(std::ostream &os, const State & rhs);

class States {
private:
	std::vector<State> state_vector;
public:
	States() {}
	States(std::vector<State> &_state_vector);
	State get(int index) const;
	bool contains(State s);
	size_t size() const;
	void set(int index, const State &s);
	void remove();

	//The below is similar to the overloaded += operator
	States & add(const State &s);

	//The below adds the state on the right hand side to the
	//States object on the left hand side
	States & operator+=(const State & rhs);

	States operator+(const State & rhs);
	void print();
};

#endif
