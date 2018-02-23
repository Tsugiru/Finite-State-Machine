#include <state.h>

////////////////////////
///   State Class	 ///
////////////////////////

////
/// Default Constructor
/// Sets the state's name to an empty string
////
State::State() {
	state_name = "";
}

////
/// Parametrized Constructor
/// Sets the state's name to a given string
////
State::State(std::string _state_name) {
	state_name = _state_name;
}

////
/// Returns the state's name
////
std::string State::getName() const {
	return state_name;
}

////
/// Sets the state's name to a given string
////
void State::setName(std::string _state_name) {
	state_name = _state_name;	
}

////
/// Creates and returns an object "States" 
/// containing only two states
////
States State::operator+(const State & rhs) {
	States ss;
	ss.add(*this).add(rhs);
	return ss;
}

////
/// Returns an object "States" consisting
/// of the one on the rhs in addition to
/// the "State" object on the lhs
////
States State::operator+(States ss) {
	ss.add(*this);
	return ss;
}

////
/// Overloads the == operator to compare
/// two states by comparing their names
////
bool State::operator==(const State & rhs) const {
	return this->state_name == rhs.getName();
}

////
/// Hash function that allows 
/// the use of State objects in unordered maps
////
size_t State::state_hash::operator()(const State &s) const {
	return std::hash<std::string>()(s.getName());
}


////////////////////////
///   States Class	 ///
////////////////////////

////
/// Parametrized Constructor
////
States::States(std::vector<State> &_state_vector) {
	state_vector = _state_vector;
}

////
/// Returns the state at a given index of the vector
////
State States::get(int index) const {
	return state_vector.at(index);
}

////
/// Returns whether the vector contains a given State s
////
bool States::contains(State s) {
	for(auto st : state_vector){
		if(st == s){
			return true;		
		}	
	}
	return false;
}

////
/// Returns the size of the vector, i.e. the number of State objects
////
size_t States::size() const {
	return state_vector.size();
}

////
/// Sets the state at a given index of the vector 
////
void States::set(int index, const State &s) {
	state_vector.at(index) = s;	
}

////
/// Removes the last element of the vector
////
void States::remove() {
	state_vector.pop_back();
}

////
/// Appends a State object to the vector
////
States & States::add(const State &s) {
	if(!this->contains(s)){
		state_vector.push_back(s);
	}
	return (*this);
}

////
/// Overloads the += operator to append
/// a State object on the RHS
/// to a States object on the LHS
////
States & States::operator+=(const State & rhs) {
	this->add(rhs);
	return (*this);
}

////
/// Overloads the + operator to return a new
/// States object consisting of the one on
/// the LHS in addition to the State on the RHS
////
States States::operator+(const State & rhs) {
	States ss = *this;
	ss.add(rhs);
	return ss;
}

////
/// Prints the names of all of the states
////
void States::print() {
	for(int i = 0; i < state_vector.size(); i++) {
		std::cout << state_vector[i] << " ,"[i < state_vector.size() - 1] << " \n"[i == state_vector.size() - 1];
	}
}

////
/// Overloaded insertion operator to print States
////
std::ostream & operator<<(std::ostream & os, const State & rhs) {
	os << rhs.getName();
	return os;	
}
