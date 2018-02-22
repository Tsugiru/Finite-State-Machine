#ifndef FUNCTOR_H
#define FUNCTOR_H

//Abstract base class for any functor which 
//wishes to implement a condition
class c_functor {
public:
	virtual ~c_functor() {}
	virtual bool operator()() = 0;
};

//Abstract base class for any functor which
//wishes to implement an action
class a_functor {
public:
	virtual ~a_functor() {}
	virtual void operator()() = 0;
};

#endif
