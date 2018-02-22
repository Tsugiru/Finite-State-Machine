#ifndef PORT_H
#define PORT_H

class Port {
public:
    bool active;
    Port() { active = true; }
    Port(bool initial_status) { active = initial_status; }
    void activate() { active = true; }
    void deactivate() { active = false; }
    void toggle() { active = !active; }

};

#endif
