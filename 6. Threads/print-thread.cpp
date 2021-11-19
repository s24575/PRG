#include <iostream>
#include <thread>
#include <vector>

void PrintThread(int x)
{
	std::cout << "Hello, " << x << "!\n";
}

int main()
{
	std::vector<std::thread> ThreadVector;

	for (int i = 0; i < 42; ++i)
	{
		ThreadVector.emplace_back([&]() {PrintThread(i + 1); });
		ThreadVector[i].join();
	}
	std::cin.get();
	return 0;
}