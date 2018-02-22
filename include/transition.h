#ifndef TRANSITION_H
#define TRANSITION_H

#include <state.h>
#include <condition.h>
#include <action.h>
#include <port.h>
#include <vector>

class Transitions; //Class Prototype

class Transition {
private:
	State start;
	State destination;
	Port port;
	Condition condition;
	Action action;

public:
	Transition(){};
	Transition(State _start, State _destination, Port _port, Condition _condition, Action _action);

	State getStart();
	State getDestination();
	Port getPort();
	Condition getCondition();
	Action getAction();
        
	void setStart(State _start);
	void setDestination(State _destination);
	void setPort(Port _port);
	void setCondition(Condition _condition);
	void setAction(Action _action);

	bool evaluate_condition();
	void execute_action();
	bool valid();

    Transitions operator+(const Transition & rhs);
    Transitions operator+(Transitions ts);
};

class Transitions {
private:
	std::vector<Transition> transition_vector;
public:
	Transitions(){}
	Transitions(std::vector<Transition> _transition_vector);
	size_t size() const;
	std::vector<Transition> get();
	Transition get(int index) const;
	Transitions & add(const Transition &t);
	Transitions & operator+=(const Transition &t);
	void set(int index, const Transition &s);
	Transitions operator+(const Transition &t);
	void remove();
};

#endif
