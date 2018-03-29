#ifndef INTERACTION_H
#define INTERACTION_H

#include <FSM.h>
#include <condition_variable>
#include <vector>
#include <semaphore.h>

class Interaction {
private:
	Semaphore *sem;
	std::mutex lock;
	unsigned int count;
	Action A;
	std::vector<FSM*> C;			

public:
	Interaction(std::vector<FSM*> &_C);
	Semaphore * get_semaphore();
	void run();
};

#endif
