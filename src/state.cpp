#include <state.h>

State::State() {
	state_name = "";
}

State::State(std::string _state_name) {
	state_name = _state_name;
}

std::string State::get_name() const {
	return state_name;
}

void State::set_name(std::string _state_name) {
	state_name = _state_name;	
}

States State::operator+(const State & rhs) {
	States ss;
	ss.add(*this).add(rhs);
	return ss;
}

States State::operator+(States ss){
	ss.add(*this);
	return ss;
}

States::States(std::vector<State> &_state_vector) {
	state_vector = _state_vector;
}

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

void States::set(int index, const State &s) {
	//check for index	
	state_vector[index] = s;	
}

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
		std::cout << state_vector[i] << std::endl;
	}
}

std::ostream & operator<<(std::ostream & os, const State & rhs) {
	os << rhs.get_name();
	return os;	
}
