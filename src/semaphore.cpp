#include <semaphore.h>

Semaphore::Semaphore(int _count) {
	intial_count = count = _count;
}

void Semaphore::notify() {
    std::unique_lock<decltype(mtx)> lock(mtx);
    ++count;
    condition.notify_one();
}

void Semaphore::wait() {
    std::unique_lock<decltype(mtx)> lock(mtx);
    while(count <= 0) // Handle spurious wake-ups.
        condition.wait(lock);
    --count;
}

void Semaphore::reset() {
	std::unique_lock<decltype(mtx)> lock(mtx);
	count = intial_count;	
}

