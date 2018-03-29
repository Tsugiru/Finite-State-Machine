#include <iostream>
#include <system.h>

class Variables {
public:
	int t;
	Variables() {
		t = 0;
	}
};

//checks if t less than N
class lessThanN : public c_functor {
public:
	Variables *vars;
	int N;
	lessThanN(Variables *_vars, int _N = 10) {
		vars = _vars;
		N = _N;
	}
	virtual bool operator()() {
		return vars->t < N;
	}
};

//increments t by 1
class incrementByOne : public a_functor {
public:
	Variables *vars;
	incrementByOne(Variables *_vars) {
		vars = _vars;
	}
	virtual void operator()() {
		vars->t++;
	}
};

int main() {
	Variables *vars = new Variables();
	Condition C(new lessThanN(vars, 10));
	Action A(new incrementByOne(vars));

	State s1("one");
	State s2("two");
	State s3("three");
	States ss = s1 + s2 + s3;
	
	Port thisPortIsAlwaysTrue("always true port", true);

	Transition t1(s1, s2, thisPortIsAlwaysTrue, C, A);
	Transition t2(s2, s3, thisPortIsAlwaysTrue, C, A);
	Transition t3(s3, s1, thisPortIsAlwaysTrue, C, A);
	Transitions ts = t1 + t2 + t3;
	
	FSM m(ss, s1, ts);
	FSM m1(ss, s1, ts);
	std::vector<FSM*> fsm_vector;					
	fsm_vector.push_back(&m);
	fsm_vector.push_back(&m1);

	Interaction interaction(fsm_vector);
	m.getStates().get(1).set_interaction(&interaction);
	m1.getStates().get(1).set_interaction(&interaction);

	std::vector<Interaction*> interaction_vector;
	interaction_vector.push_back(&interaction);

	System S(fsm_vector, interaction_vector, {60, 60});
	S.run();
}
