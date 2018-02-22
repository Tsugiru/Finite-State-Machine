#ifndef CONDITION_H
#define CONDITION_H

#include <functor.h>

class Condition {
public:
	c_functor *f;
	Condition(c_functor *_f) {
		f = _f;
	}
	bool evaluate() { 
		return (*f)(); 
	}
};

#endif
