#include <iostream>
#include <condition.h>
#include <action.h>
#include <functor.h>
#include <state.h>
#include <transition.h>
#include <FSM.h>

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
	m.printStates();
	m.run(3);
	m.drawFSM("smallTestFSM");
	std::cout << m.getCurrentState() << std::endl;
}
