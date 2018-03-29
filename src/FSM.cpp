#include <FSM.h>
#include <random>
#include <unordered_set>

////
/// Default constructor
////
FSM::FSM(){
	Q = States();
	q0 = State();
	curr = q0;
	T = Transitions();
}

////
/// Parametrized constructor
/// Sets Q, q0, curr and T and fills the adjacency list
/// If the user assigned q0 isn't present in Q, an arbitrary state present in Q is assigned to q0
////
FSM::FSM(States _Q, State _q0, Transitions _T) {
	std::default_random_engine generator;

	Q = _Q;
	q0 = _q0;
	T = _T;

	std::uniform_int_distribution<int> distribution(0, Q.size() - 1);

	if(!Q.contains(q0)){
		std::cout << "Warning: the initial state specified for the FSM does\
			not exist in Q. q0 has been set arbitrarily." << std::endl;
		q0 = Q.get(distribution(generator));
	}

	curr = q0;
	fillAdjList();
}

std::condition_variable * FSM::get_cv() {
	return &cv;
}

////
/// Runs the FSM for n iterations where n <= max_steps
/// The first transition that is valid is executed along with the action associated with it
/// In case there are no valid transitions, the run is done and the function returns
////
void FSM::run(int max_steps) {
	for(int steps = 0; steps < max_steps; steps++) {
		std::vector<Transition> neighbors = adj_list[curr];	
		bool ok = false;
		if(curr.part_of_interaction()) {
			curr.interaction_ready();					
			set_ready_flag();
			std::unique_lock<decltype(lock)> u_lock(lock);
			while(ready_flag) {
				cv.wait(u_lock);
			}
		}
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

void FSM::set_ready_flag() {
	ready_flag = 1;
}

void FSM::clear_ready_flag() {
	ready_flag = 0;
}

////
///Getters
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
////

////
/// Sets Q and fills the adjacency list anew to make sure the states and transitions match
////
void FSM::setStates(States _Q) {
	Q = _Q;
	fillAdjList();
}

////
/// Sets q0
/// If the user assigned q0 isn't present in Q, an arbitrary state present in Q is assigned to q0
////
void FSM::setInitialState(State _q0) {
	std::default_random_engine generator;
	std::uniform_int_distribution<int> distribution(0, Q.size() - 1);
	if(Q.contains(_q0)){
		q0 = _q0;	
	}
	else{
		q0 = Q.get(distribution(generator));
		std::cout << "Warning: the initial state specified for the FSM does\
		   	not exist in Q. q0 has been set arbitrarily." << std::endl;
	}
}

////
/// Sets T and fills the adjacency list anew to make sure the states and transitions match
////
void FSM::setTransitions(Transitions _T) {
	T = _T;
	fillAdjList();
}

////
/// Fills the adjacency list by mapping states to the transitions of which they are the starting state
/// A transition is only considered valid if both its starting state and destination are present in Q
/// Any invalid transition is removed from T
////
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

////
/// Resets curr to q0
////
void FSM::reset() {
	curr = q0;
} 

////
/// Resets curr to a user picked State s
/// If s isn't present in Q, curr is set to q0
////
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

////
/// Prints the names of all the ports of the FSM along with their status
/// Each individual port is printed once
////
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

////
/// Prints the names of all the states in Q
////
void FSM::printStates() {
	std::cout << "The states of the FSM are: " << std::endl;
	Q.print();
	std::cout << std::endl;
}

////
/// Generates a DOT graph representation of the FSM.
/// The contents of the file can be used for visualization purposes.
/// The file is named by the user and is stored by default in the "graphs" directory
////
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
