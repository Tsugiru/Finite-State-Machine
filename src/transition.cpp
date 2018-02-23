#include <transition.h>


////////////////////////
/// Transition Class ///
////////////////////////


////
/// Parametrized Constructor
/// Sets start, destination, port, condition and action
////
Transition::Transition(State _start, State _destination, Port _port, Condition _condition, Action _action) {
	start = _start;
	destination = _destination;
	port = _port;
	condition = _condition;
	action = _action;
}

////
/// Getters
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
////

////
/// Setters
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
////

////
///	Returns whether the condition is met or not
////
bool Transition::evaluate_condition() {
	return condition.evaluate();
}

////
/// Executes the action when the transition is taken
////
void Transition::execute_action() {
	action.execute();
}

////
/// Returns whether both the port is activated 
/// and the condition is met
////
bool Transition::valid() {
	return port.status() && condition.evaluate();
}

////
/// Overloads the + operator to add two
/// transitions to a new "Transitions" object
////
Transitions Transition::operator+(const Transition & rhs) {
	Transitions t;
	t.add(*this).add(rhs);
	return t;
}
////
/// Overloads the + operator to append
/// a transition to a "Transtions" object
////
Transitions Transition::operator+(Transitions ts) {
	ts.add(*this);
	return ts;
}

/////////////////////////
/// Transitions Class ///
/////////////////////////

////
/// Parametrized Constructor
////
Transitions::Transitions(std::vector<Transition> _transition_vector) {
	transition_vector = _transition_vector;
}

////
/// Returns the size of the vector, i.e. the number of transitions
////
size_t Transitions::size() const {
	return transition_vector.size();
}

////
/// Returns the vector of transitions
////
std::vector<Transition> Transitions::get() {
	return transition_vector;
}

////
/// Returns the transition at
/// a given index of the vector
////
Transition Transitions::get(int index) const {
	return transition_vector.at(index);
}

////
/// Appends a Transition object to the vector
////
Transitions & Transitions::add(const Transition &t) {
	transition_vector.emplace_back(t);
	return (*this);
}

////
/// Overloads the += operator to append
/// a Transition object to the vector
////
Transitions & Transitions::operator+=(const Transition &t) {
	transition_vector.emplace_back(t);
	return (*this);
}

////
/// Overloads the + operator to return a new
/// Transitions object consisting of the one on
/// the LHS in addition to the Transition on the RHS
////
Transitions Transitions::operator+(const Transition &t) {
	Transitions ts = *this;	
	ts.add(t);
	return ts;
}

////
/// Sets the element at a given index of the vector
////
void Transitions::set(int index, const Transition &s) {
	transition_vector.at(index) = s;
}

////
/// Removes the last element of the vector
////
void Transitions::remove() {
	transition_vector.pop_back();
}

////
/// Remove the element at a given index from the vector
////
void Transitions::remove(int index) {
	transition_vector.erase(transition_vector.begin()+index);
}






