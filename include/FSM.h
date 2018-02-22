#ifndef FSM_H
#define FSM_H

#include <transition.h>
#include <state.h>
#include <unordered_map>

class FSM {
private:
<<<<<<< HEAD
    States Q;
    Transitions T;
    State q0;
    State curr;
	std::unordered_map<State, std::vector<Transition>, State::state_hash> adj_list;

public:
	FSM(){}
    FSM(States _Q, State _q0, Transitions _T);
	void run(int max_steps);
=======
 	States Q;
	Transitions T;
	State q0;
	State curr;

public:
	FSM(){}
	FSM(States _Q, State _q0, Transitions _T);
>>>>>>> 2ea02381f12fb9aa7f45951dd3296204837b1934
};

#endif
