#ifndef FSM_H
#define FSM_H

#include "transition.h"
#include "state.h"

class FSM {
private:
    States Q;
    Transitions T;
    State q0;
    State curr;

public:
	FSM(){}
    FSM(States _Q, State _q0, Transitions _T);
};

#endif
