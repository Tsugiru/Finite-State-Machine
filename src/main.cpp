#include <iostream>
#include <condition.h>
#include <action.h>
#include <functor.h>
#include <state.h>
#include <transition.h>

class Variables {
public:
	int t;
	Variables() {
		t = 0;
	}
};

//checks if t less than 10
class condiFunc : public c_functor {
public:
	Variables *vars;
	condiFunc(Variables *_vars) {
		vars = _vars;
	}
	virtual bool operator()() {
		return vars->t < 10;
	}
};

//increments t by 1
class actionFunc : public a_functor {
public:
	Variables *vars;
	actionFunc(Variables *_vars) {
		vars = _vars;
	}
	virtual void operator()() {
		vars->t++;
	}
};

int main() {
	Variables *vars = new Variables();
	Condition C(new condiFunc(vars));
	Action A(new actionFunc(vars));

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

	Port reset;

	Transition t1(s1, s1, reset, C, A);
	Transition t2(s1, s2, reset, C, A);
	Transition t3(s2, s3, reset, C, A);
	Transition t4(s3, s4, reset, C, A);
	Transition t5(s4, s3, reset, C, A);
	Transition t6(s4, s4, reset, C, A);

	Transitions ts = t1 + t2 + t3 + t4;
	ts += t5;
	ts = ts + t6;

	std::cout<<ts.get(4).getStart() << std::endl;

	return 0;
}
