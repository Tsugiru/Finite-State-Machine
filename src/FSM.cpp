#include <FSM.h>

FSM::FSM(){
	Q = States();
	q0 = State();
	curr = q0;
	T = Transitions();
}

FSM::FSM(States _Q, State _q0, Transitions _T) {
	Q = _Q;
	q0 = _q0;
	curr = q0;
	T = _T;
}

void set

void FSM::reset() {
	curr = q0;
} 

void FSM::reset(State s) {
	if(Q.contains(s)){
		curr = s;
	}
	//else output error or warning and reset to q0
}

void FSM::printPorts() {
	
}

void FSM::drawFSM() {

}
