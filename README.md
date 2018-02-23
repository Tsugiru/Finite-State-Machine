# Finite-State-Machine

This was an assignment for our "Software Architecture and Design Fundamentals" course (aka EECE437). This course covers fundamental principles of software design and architecture from construction, analysis, and practice perspectives. The course details the design and construction of software products for better utility. It details software abstractions of process, data, transactions, and interaction. It discusses design methods such as structural, object, aspect, and feature oriented design. It then discusses deployment, interoperability, reuse, patterns, anti-patterns, and refactoring. The concepts will be illustrated in the context of course projects and with open source supporting tools. Some projects will be built from scratch and some will be built based on existing legacy code.

The goal of this assignment was to build a clear API that could allow the user to construct his Finite State Machine declaratively. The FSM has the following components:

1 - States (quite self explanatory).

2 - A set of user-defined variables.

3 - Actions, they act on the variables in a user defined manner.

4 - Condition, boolean function of the variables, user defined.

5 - Transitions, the link between two states, takes a Condition, a port, and an action. The transition will move from the first state to the second while executing the action if: The condition is true and port is active.


The user can also output to a .gv file the shape of the FSM, which can then be rendered using graphviz.

A small example:
```c++
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
```
To run this project, you could write your own test and place it in the ./tests directory, then from command line you can build the project as such:
```
make TEST=your_test_file_name
./bin/you_test_file_name
```
Or you could just do
```
make run TEST=your_test_file_name
```
