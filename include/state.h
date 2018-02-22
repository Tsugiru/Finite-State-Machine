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
	std::string get_name() const;
	void set_name(std::string);
	States operator+(const State & rhs);
	
};

std::ostream & operator<<(std::ostream &os, const State & rhs);

class States {
private:
	std::vector<State> state_vector;
public:
	States() {}
	States(std::vector<State> &_state_vector);
	State get(int index) const;
	size_t size() const;
	void set(int index, const State &s);
	void remove();
	States & add(const State &s);
	States & operator+(const State & rhs);
	void print();
};

#endif
