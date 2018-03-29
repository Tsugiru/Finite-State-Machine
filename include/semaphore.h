#include <mutex>
#include <condition_variable>

class Semaphore {
private:
    std::mutex mtx;
    std::condition_variable condition;
    int count, intial_count;

public:
	Semaphore(int _count);
	void notify();
	void wait();
	void reset();
};
