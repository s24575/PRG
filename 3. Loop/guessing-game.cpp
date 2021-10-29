#include <iostream>
#include <random>

int main()
{
	int min = 0;
	int max = 100;
	std::random_device seed;
	std::mt19937 rng(seed());
	std::uniform_int_distribution<int> gen(min, max);
	int r = gen(rng);
	std::cout << r << "\n";
	int x;
	std::cin >> x;
	while (x != r)
	{
		if (x < r)
			std::cout << "more" << "\n";
		else
			std::cout << "less" << "\n";
		std::cin >> x;
	}
	std::cout << "well done!";
	return 0;
}