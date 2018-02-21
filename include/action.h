template <class Functor>
class Action {
public:
	Functor *f;
	Action(Functor *_f) {
		f = _f;
	}
	void execute() { 
		(*f)(); 
	}
};
