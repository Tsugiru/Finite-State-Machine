#include <FSM.h>

FSM::FSM(States _Q, State _q0, Transitions _T) {
	Q = _Q;
	q0 = _q0;
	curr = q0;
	T = _T;
}
