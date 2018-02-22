#ifndef PORT_H
#define PORT_H

class Port {
private:
    bool active;
public:
    Port() { active = true; }
    Port(bool initial_status) { active = initial_status; }
    void activate() { active = true; }
    void deactivate() { active = false; }
    void toggle() { active = !active; }
	bool status() { return active; }
};

#endif
