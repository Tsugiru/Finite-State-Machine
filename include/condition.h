#ifndef CONDITION_H
#define CONDITION_H

template <class Functor>
class Condition {
public:
	Functor *f;
	Condition(Functor *_f) {
		f = _f;
	}
	bool evaluate() { 
		return (*f)(); 
	}
};

#endif
