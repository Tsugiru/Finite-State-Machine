#include <port.h>

////
/// Default constructor
////
Port::Port(std::string _name, bool initial_status) {
	name = _name; 
	active = initial_status; 
}

////
/// Returns the port's name
////
std::string Port::getName() const {
	return name;
}

////
/// Sets the boolean value to True
////
void Port::activate() {
	active = true;
}

////
/// Sets the boolean value to False
////
void Port::deactivate() {
	active = false;
}

////
/// Switches the boolean's value to its opposite
////
void Port::toggle() {
	active = !active;
}

////
/// Returns whether the port is active or not
////
bool Port::status() {
	return active;
}

////
/// Prints the name of the port and its status
/// Format: { Name : Status }
////
void Port::print() const {
	std::cout << "{ " << name << " : " << (active ? "Active" : "Not Active") << " }" << std::endl;
}

////
/// Overloads the == operator to
/// compare two ports by comparing
/// their names
////
bool Port::operator==(const Port & rhs) const {
	return this->name == rhs.getName();
}

////
/// Hash function that allows the use of
/// ports in an unordered map
////
size_t Port::portHash::operator()(const Port &p) const {
	return std::hash<std::string>()(p.name);	
}

