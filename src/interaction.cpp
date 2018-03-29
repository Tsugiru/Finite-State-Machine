#include <interaction.h>

Interaction::Interaction(std::vector<FSM*> &_C) {
	C = _C;
	count = C.size();
	sem = new Semaphore(-1*count);
}

Semaphore * Interaction::get_semaphore() {
	return sem;
}

void Interaction::run() {
	while(true) {
		sem->wait();	
		A.execute();
		for(auto fsm : C) {
			fsm->clear_ready_flag();
			fsm->get_cv()->notify_one();
		}
		sem->reset();
	}		
}
