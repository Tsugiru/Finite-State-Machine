#ifndef PORT_H
#define PORT_H

#include <iostream>
#include <string>
#include <functional>

class Port {
private:
	std::string name;
	bool active;
public:
	Port(std::string _name = "", bool initial_status = true);

	std::string getName() const;
	void activate();
	void deactivate();
	void toggle();
	bool status();

	void print() const;

	bool operator==(const Port & rhs) const;

	struct portHash {
		size_t operator()(const Port &p) const;
	};
};

#endif
