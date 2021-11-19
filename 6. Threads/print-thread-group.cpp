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

	for (int i = 0; i < 7; ++i)
	{
		std::cout << "batch nr: " << i + 1 << '\n';
		for (int j = 0; j < 6; ++j)
		{
			ThreadVector.emplace_back([&]() {PrintThread(j + 1); });
			ThreadVector[(i+1)*(j+1)-1].detach();
		}
		for (auto const e : ThreadVector)
			e.join();
	}
	std::cin.get();
	return 0;
}
