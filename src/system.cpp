#include <system.h>

System::System(std::vector<FSM*> _fsm_vector, std::vector<Interaction*> _interaction_vector, std::vector<int> _run_time) {
	fsm_vector = _fsm_vector;
	run_time = _run_time;
	interaction_vector = _interaction_vector;
}

void System::run() {

	for(auto interaction : interaction_vector) {
		thread_vector.emplace_back(std::thread(&Interaction::run, interaction));
	}

	for(size_t i = 0; i < fsm_vector.size(); i++) {
		thread_vector.emplace_back(std::thread(&FSM::run, fsm_vector[i], run_time[i]));
	}
}
