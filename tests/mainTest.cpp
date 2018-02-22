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
	void reset() {
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

class equalsN : public c_functor {
public:
	Variables *vars;
	int N;
	equalsN(Variables *_vars, int _N = 10) {
		vars = _vars;
		N = _N;
	}
	virtual bool operator()() {
		std::cout << "ping " << vars->t << std::endl;
		return vars->t == N;	
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

class resetNum : public a_functor {
public:
	Variables *vars;
	resetNum(Variables *_vars) {
		vars = _vars;
	}
	virtual void operator()() {
		vars->t = 0;	
	}
};

int main() {
	Variables *vars = new Variables();
	Condition C(new lessThanN(vars,10));
	Action A(new incrementByOne(vars));

	for(int counter = 0; 
		C.evaluate(); 
		std::cout << counter << std::endl, 
		A.execute(), 
		counter++
		);

	State s1("happy");
	State s2("sad");
	State s3("angry");
	State s4("carlos");
	State s5("connect");
	States ss = s1 + s2 + s3;
	ss += s4;
	ss = ss + s5;

	//print like this
	for(size_t i = 0;
		i < ss.size();
		std::cout << ss.get(i) << std::endl,
		i++
		);	

	//or just like this
	ss.print();

	//Test from assignment document	
	State red("Red");
	State green("Green");
	State yellow("Yellow");

	Port reset("Reset Port", true);
	Port increment("Increment Port", true);
	Port idle("Idle Port", true);
	
	vars->reset();
	Condition lessThan10(new lessThanN(vars, 10));
	Condition lessThan5(new lessThanN(vars, 5));
	Condition equals10(new equalsN(vars, 10));
	Condition equals5(new equalsN(vars, 5));
	
	Action incrementT(new incrementByOne(vars));
	Action resetT(new resetNum(vars));

	Transition t1(red, red, increment, lessThan10, incrementT);
	Transition t2(red, green, reset, equals10, incrementT);

	Transition t3(green, green, increment, lessThan10, incrementT);
	Transition t4(green, yellow, reset, equals10, incrementT);

	Transition t5(yellow, yellow, increment, lessThan5, incrementT);
	Transition t6(yellow, red, reset, equals5, resetT);

	States Q = red + green + yellow;
	Transitions T = t1 + t2 + t3 + t4 + t5 + t6;

	FSM m(Q, red, T);

	m.printPorts();
	m.printStates();
	m.drawFSM("assignmentFSM_before_run");
	m.run(12);
	m.drawFSM("assignmentFSM_after_run");
	
//	m.drawFSM("initialstate");
	
//	m.run(15);
//	m.drawFSM("15iterations");

//	m.run(60);
//	m.drawFSM("60iterations");	

//	m.reset(red);
//	m.run(45);
//	m.drawFSM("45iterations");

	return 0;
}
