#ifndef FUNCTOR_H
#define FUNCTOR_H

class c_functor {
public:
	virtual ~c_functor() {}
	virtual bool operator()() = 0;
};

class a_functor {
public:
	virtual ~a_functor() {}
	virtual void operator()() = 0;
};

#endif
