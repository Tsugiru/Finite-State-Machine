#include <condition.h>
#include <state.h>
#include <action.h>
#include <iostream>
#include <functor.h>

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
	States ss = s1 + s2 + s3 + s4;

	//print like this
	for(size_t i = 0;
		i < ss.size();
		std::cout << ss.get(i) << std::endl,
		i++
		);	

	//or just like this
	ss.print();
}
