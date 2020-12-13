#include <thread>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

void foo(int id, int target) {
	int random;
	while(random != target) {
		random = rand()%9999;
	}
	std::cout << "Thread " << id << " completed" << std::endl;
}

int main(int argc, char* argv[]) {
	srand(time(0));
	std::vector<std::thread> store;
	int target = atoi(argv[1]);
	for(int i = 0; i < 10; i++) {
		int id = i;
		std::thread th1(foo, id, target);
		store.push_back(std::move(th1));
	}
	for (auto&& a : store)
		a.join();
	std::cout << "All threads have finished finding numbers." << std::endl;
	return 0;
}
