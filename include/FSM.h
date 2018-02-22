#ifndef FSM_H
#define FSM_H

#include <transition.h>
#include <state.h>
#include <unordered_map>

class FSM {
private:
    States Q;
    Transitions T;
    State q0;
    State curr;
	std::unordered_map<State, std::vector<Transition>, State::state_hash> adj_list;

public:
	FSM(){}
    FSM(States _Q, State _q0, Transitions _T);
	void run(int max_steps);
};

#endif
