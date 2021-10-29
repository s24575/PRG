#include <iostream>

int main()
{
	int x;
	std::cin >> x;
	std::cout << "Start\n";
	for (int i = 1; i <= x; i++)
	{
		std::cout << i;
		if(i % 3 == 0)
			if (i % 5 == 0)
			{
				std::cout << " FizzBuzz\n";
				continue;
			}
			else
				std::cout << " Fizz";
		if (i % 5 == 0)
			std::cout << " Buzz";
		std::cout << "\n";
	}
	return 0;
}