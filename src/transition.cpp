#include <transition.h>

Transition::Transition(State _start, State _destination, Port _port, Condition _condition, Action _action) {
	start = _start;
	destination = _destination;
	port = _port;
	condition = _condition;
	action = _action;
}

State Transition::getStart() {
	return start;
}

State Transition::getDestination() {
	return destination;
}

Port Transition::getPort() {
	return port;
}

Condition Transition::getCondition() {
	return condition;
}

Action Transition::getAction() {
	return action;
}

void Transition::setStart(State _start) {
	start = _start;
}

void Transition::setDestination(State _destination) {
	destination = _destination;
}

void Transition::setPort(Port _port) {
	port = _port;
}

void Transition::setCondition(Condition _condition) {
	condition = _condition;
}

void Transition::setAction(Action _action) {
	action = _action;
}

bool Transition::evaluate_condition() {
	return condition.evaluate();
}

void Transition::execute_action() {
	action.execute();
}

bool Transition::valid() {
	return port.status() && condition.evaluate();
}

Transitions Transition::operator+(const Transition & rhs) {
	Transitions t;
	t.add(*this).add(rhs);
	return t;
}

Transitions Transition::operator+(Transitions ts) {
	ts.add(*this);
	return ts;
}


Transitions::Transitions(std::vector<Transition> _transition_vector) {
	transition_vector = _transition_vector;
}

std::vector<Transition> Transitions::get() {
	return transition_vector;
}

Transition Transitions::get(int index) const {
	return transition_vector.at(index);
}

Transitions & Transitions::add(const Transition &t) {
	transition_vector.emplace_back(t);
	return (*this);
}

Transitions Transitions::operator+(const Transition &t) {
	Transitions ts = *this;	
	ts.add(t);
	return ts;
}

Transitions & Transitions::operator+=(const Transition &t) {
	transition_vector.emplace_back(t);
	return (*this);
}

void Transitions::set(int index, const Transition &s) {
	//check index
	transition_vector[index] = s;
}

size_t Transitions::size() const {
	return transition_vector.size();
}

void Transitions::remove() {
	transition_vector.pop_back();
}

void Transitions::remove(int index) {
	transition_vector.erase(transition_vector.begin()+index);
}






