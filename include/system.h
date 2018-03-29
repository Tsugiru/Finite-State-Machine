#include <thread>
#include <vector>
#include <interaction.h>

class System {
private:
	std::vector<FSM*> fsm_vector;
	std::vector<int> run_time;
	std::vector<Interaction*> interaction_vector;	
	std::vector<std::thread> thread_vector;
public:
	System(std::vector<FSM*> _fsm_vector, std::vector<Interaction*> interaction_vector, std::vector<int> _run_time);
	void run();
};
