#ifndef PORT_H
#define PORT_H

#include <iostream>
#include <string>

class Port {
private:
	string name;
	bool active;
public:
	Port(string _name = "", bool initial_status = true) { 
		name = _name; 
		active = initial_status; 
	}
	void activate() { active = true; }
	void deactivate() { active = false; }
	void toggle() { active = !active; }
	bool status() { return active; }
	void print() {
		std::cout<<"{ " <<name <<" : " << (active ? "Active" : "Not Active") <<" }" <<std::endl;
	}
};

#endif
