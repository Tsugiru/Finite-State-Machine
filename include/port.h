#ifndef PORT_H
#define PORT_H

class Port {
<<<<<<< HEAD
private:
    bool active;
public:
    Port() { active = true; }
    Port(bool initial_status) { active = initial_status; }
    void activate() { active = true; }
    void deactivate() { active = false; }
    void toggle() { active = !active; }
	bool status() { return active; }
=======
public:
	bool active;
	Port() { active = true; }
	Port(bool initial_status) { active = initial_status; }
	void activate() { active = true; }
	void deactivate() { active = false; }
	void toggle() { active = !active; }

>>>>>>> 2ea02381f12fb9aa7f45951dd3296204837b1934
};

#endif
