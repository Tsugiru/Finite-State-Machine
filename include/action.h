#ifndef ACTION_H
#define ACTION_H

#include <functor.h>

class Action {
public:
	a_functor *f;
	Action(a_functor *_f) {
		f = _f;
	}
	void execute() { 
		(*f)(); 
	}
};

#endif
