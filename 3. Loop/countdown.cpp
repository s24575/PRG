#include <iostream>
#include <chrono>
#include <thread>

int main()
{
	int x;
	std::cin >> x;
	for (int i = x; 0 <= i; i--)
	{
		std::cout << i << "...\n";
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	}
}