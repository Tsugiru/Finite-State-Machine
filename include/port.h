#ifndef PORT_H
#define PORT_H

#include <iostream>
#include <string>
#include <functional>

class Port {
private:
	std::string name;	//! Name of the port
	bool active;	//! Status of the port
public:
	Port(std::string _name = "", bool initial_status = true);	//! Default constructor
		
	std::string getName() const;	//! Returns the port's name
	void activate();	//! Sets the boolean value to True
	void deactivate();	//! Sets the boolean value to False
	void toggle();	//! Switches the boolean's value to its opposite
	bool status();	//! Returns the whether the port is active or not

	void print() const;	//! Prints the port's name and its status

	bool operator==(const Port & rhs) const;	//! Overloads the == operator to
												//! compare two ports by comparing
												//! their names

	struct portHash {	//! Hash function that allows the use of ports in an unordered map
		size_t operator()(const Port &p) const;
	};
};

#endif
