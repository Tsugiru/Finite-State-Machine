#include <state.h>

State::State() {
	state_name = "";
}

State::State(std::string _state_name) {
	state_name = _state_name;
}

std::string State::getName() const {
	return state_name;
}

void State::setName(std::string _state_name) {
	state_name = _state_name;	
}

bool State::isEqual(State s) {
	return state_name == s.getName();
}

bool State::operator==(State s) {
	return state_name == s.getName();
}


//The below creates and returns an object "States" containing only two states
States State::operator+(const State & rhs) {
	States ss;
	ss.add(*this).add(rhs);
	return ss;
}

States State::operator+(States ss) {
	ss.add(*this);
	return ss;
}

States::States(std::vector<State> &_state_vector) {
	state_vector = _state_vector;
}

//The below is similar to the overloaded += operator
States & States::add(const State &s) {
	state_vector.push_back(s);
	return (*this);
}

size_t States::size() const {
	return state_vector.size();
}

void States::remove() {
	state_vector.pop_back();
}

State States::get(int index) const {
	//check for index
	return state_vector[index];
}

bool States::contains(State s) {
	for(auto st : state_vector){
		if(st == s){
			return true;		
		}	
	}
	return false;
}

void States::set(int index, const State &s) {
	//check for index	
	state_vector[index] = s;	
}

//The below adds the state on the right hand side to the
//States object on the left hand side
States & States::operator+=(const State & rhs) {
	this->add(rhs);
	return (*this);
}

States States::operator+(const State & rhs) {
	States ss = *this;
	ss.add(rhs);
	return ss;
}

void States::print() {
	for(int i = 0; i < state_vector.size(); i++) {
		std::cout << state_vector[i] << " ,"[i < state_vector.size() - 1] << " \n"[i == state_vector.size() - 1];
	}
}

//overloaded insertion operator to print States
std::ostream & operator<<(std::ostream & os, const State & rhs) {
	os << rhs.get_name();
	return os;	
}
