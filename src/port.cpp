#include <port.h>

Port::Port(std::string _name, bool initial_status) {
	name = _name; 
	active = initial_status; 
}

std::string Port::getName() const {
	return name;
}

void Port::activate() {
	active = true;
}

void Port::deactivate() {
	active = false;
}

void Port::toggle() {
	active = !active;
}

bool Port::status() {
	return active;
}

void Port::print() const {
	std::cout << "{ " << name << " : " << (active ? "Active" : "Not Active") << " }" << std::endl;
}

bool Port::operator==(const Port & rhs) const {
	return this->name == rhs.getName();
}

size_t Port::portHash::operator()(const Port &p) const {
	return std::hash<std::string>()(p.name);	
}

