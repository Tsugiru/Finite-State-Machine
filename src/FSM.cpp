#include <FSM.h>

FSM::FSM(States _Q, State _q0, Transitions _T) {
	Q = _Q;
	q0 = _q0;
	curr = q0;
	T = _T;

	for(size_t i = 0; i < Q.size(); i++) {
		adj_list[Q.get(i)] = std::vector<Transition>();
	}
	for(size_t i = 0; i < T.size(); i++) {
		adj_list[T.get(i).getStart()].push_back(T.get(i));
	}	
}

void FSM::run(int max_steps) {
	for(int steps = 0; steps < max_steps; steps++) {
		std::vector<Transition> neighbors = adj_list[curr];	
		for(auto it = neighbors.begin(); it != neighbors.end(); ++it) {
			if(it->valid()) {
				it->execute_action();
				curr = it->getDestination();
			}	
		}
	}
}

