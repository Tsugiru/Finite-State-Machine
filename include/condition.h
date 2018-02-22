#ifndef CONDITION_H
#define CONDITION_H

#include <functor.h>

class Condition {
public:
	c_functor *f;
	Condition(c_functor *_f = NULL) {
		f = _f;
	}
    void set(c_functor *_f) {
        f = _f;
    }
	bool evaluate() { 
		//Call the functor through the
		//base class pointer
		return (*f)(); 
	}
};

#endif
