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
	T = _T;

	if(!Q.contains(q0)){
		std::cout<<"Warning: the initial state specified for the FSM does not exist in Q. q0 has been set arbitrarily." <<std::endl;
		q0 = Q.get(0);
	}

	curr = q0;


}

void FSM::run(int max_steps) {
	for(int steps = 0; steps < max_steps; steps++) {
		std::vector<Transition> neighbors = adj_list[curr];	
		for(auto it = neighbors.begin(); it != neighbors.end(); ++it) {
			if(it->valid()) {
				it->execute_action();
				curr = it->getDestination();
				break; //First valid transition is executed
			}
			return; //If no transitions are valid, then the run is done	
		}
	}
}

States FSM::getStates() const {
	return Q;
}

State FSM::getInitialState() const {
	return q0;
}

State FSM::getCurrentState() const {
	return curr;
}

Transitions FSM::getTransitions() const {
	return T;
}

void FSM::setStates(States _Q) {
	Q = _Q;
	fillAdjList();
}

void FSM::setInitialState(State _q0) {
	if(Q.contains(_q0)){
		q0 = _q0;	
	}
	else{
		q0 = Q.get(0);
		std::cout<<"Warning: the initial state specified for the FSM does not exist in Q. q0 has been set arbitrarily." <<std::endl;
	}
}

void FSM::setTransitions(Transitions _T) {
	T = _T;
	fillAdjList();
}

void FSM::fillAdjList() {
	adj_list.clear();
	for(size_t i = 0; i < Q.size(); i++) {
		adj_list[Q.get(i)] = std::vector<Transition>();
	}
	for(size_t i = 0; i < T.size(); i++) {
		if(Q.contains(T.get(i).getStart()) && Q.contains(T.get(i).getDestination())) { //Both the start and destination states of each transition should be present in Q
			adj_list[T.get(i).getStart()].push_back(T.get(i));
		}
		else { //Invalid transitions are removed from T
			T.remove(i);
			i--;
		}
	}	
}


void FSM::reset() {
	curr = q0;
} 

void FSM::reset(State s) {
	if(Q.contains(s)){
		curr = s;
	}
	else{
		std::cout<<"Warning: Could not reset FSM to State " << s.getName() <<"; it is not present in Q. FSM has been reset to q0." <<std::endl;
		curr = q0;	
	}
}

void FSM::printPorts() {
	std::cout << "FSM Ports" << std::endl;
	for(size_t i = 0; i < T.size(); i++) {
		T.get(i).getPort().print();
	}
	std::cout << std::endl;
}

void FSM::printStates() {
	std::cout << "FSM States" << std::endl;
	Q.print();
	std::cout << std::endl;
}

void FSM::drawFSM() {

}
