#include <FSM.h>
#include <random>
#include <unordered_set>

FSM::FSM(){
	Q = States();
	q0 = State();
	curr = q0;
	T = Transitions();
}

FSM::FSM(States _Q, State _q0, Transitions _T) {
	std::default_random_engine generator;
	std::uniform_int_distribution<int> distribution(0, _Q.size() - 1);

	Q = _Q;
	q0 = _q0;
	T = _T;

	if(!Q.contains(q0)){
		std::cout << "Warning: the initial state specified for the FSM does\
			not exist in Q. q0 has been set arbitrarily." << std::endl;
		q0 = Q.get(distribution(generator));
	}

	curr = q0;
	fillAdjList();
}

void FSM::run(int max_steps) {
	for(int steps = 0; steps < max_steps; steps++) {
		std::vector<Transition> neighbors = adj_list[curr];	
		bool ok = false;
		for(auto it = neighbors.begin(); it != neighbors.end(); ++it) {
			if(it->valid()) {
				ok = true;
				it->execute_action();
				curr = it->getDestination();
				break; //First valid transition is executed
			}
		}
		if(!ok) {
			return; //No transition is valid, return
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
	fillAdjList(); //called to make sure the states and transitions match
}

void FSM::setInitialState(State _q0) {
	if(Q.contains(_q0)){
		q0 = _q0;	
	}
	else{
		q0 = Q.get(0);
		std::cout << "Warning: the initial state specified for the FSM does\
		   	not exist in Q. q0 has been set arbitrarily." << std::endl;
	}
}

void FSM::setTransitions(Transitions _T) {
	T = _T;
	fillAdjList(); //called to make sure the states and transitions match
}

void FSM::fillAdjList() {
	adj_list.clear();
	for(size_t i = 0; i < Q.size(); i++) {
		adj_list[Q.get(i)] = std::vector<Transition>();
	}
	for(size_t i = 0; i < T.size(); i++) { 
		//Both the start and destination states of 
		//each transition should be present in Q
		if(Q.contains(T.get(i).getStart()) && Q.contains(T.get(i).getDestination())) {
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
	if(Q.contains(s)) {
		curr = s;
	}
	else {
		std::cout << "Warning: Could not reset FSM to State " 
					<< s.getName() 
					<< "; it is not present in Q. FSM has been reset to q0." 
					<< std::endl;
		curr = q0;	
	}
}

void FSM::printPorts() {
	std::cout << "The ports of the FSM are: " << std::endl;
	std::unordered_set<Port, Port::portHash> ports;
	for(size_t i = 0; i < T.size(); i++) {
		Port currentPort = T.get(i).getPort();
		if(!ports.count(currentPort)) {
			ports.insert(currentPort);
		}
	}
	for(auto &u : ports) {
		u.print();
	}
}

void FSM::printStates() {
	std::cout << "The states of the FSM are: " << std::endl;
	Q.print();
	std::cout << std::endl;
}

void FSM::drawFSM(std::string filename) {
	std::ofstream output;
	output.open("./graphs/" + filename + ".gv");
	if (!output) throw std::runtime_error("File did not open successfully. Could not write DOT graph file.\n");

	output << "digraph finite_state_machine {\n";
	output << "rankdir=LR;\n";
	output << "size=\"8,5\"\n";
	output << "node [shape = doublecircle]; " << q0 << ';' << std::endl;
	output << "node [shape = square]; " << curr << ';' << std::endl;
	output << "node [shape = circle];\n";
	for(size_t i = 0; i < T.size(); i++) {
		output << T.get(i).getStart() << " -> " << T.get(i).getDestination() << ";\n";	
	}
	output << "}";

	output.close();
	std::cout << filename + ".gv DOT graph file generated.\n";
}
