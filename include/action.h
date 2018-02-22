#ifndef ACTION_H
#define ACTION_H

#include <functor.h>

class Action {
public:
	a_functor *f;
	Action(a_functor *_f = NULL) {
		f = _f;
	}
	void set(a_functor *_f) {
		f = _f;
	}
	void execute() { 
		//Call the functor through the
		//base class pointer
		(*f)(); 
	}
};

#endif
