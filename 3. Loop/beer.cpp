#include <iostream>
#include <string>

int main()
{
	int x;
	std::cin >> x;
	for (int i = x; i > 0; i--)
	{
		if (i > 2)
		{
			std::cout << i << " bottles of beer on the wall, " << i << " bottles of beer.\n";
			std::cout << "Take one down, pass it around, " << i - 1 << " bottles of beer on the wall...\n";
		}
		else
		{
			if (i == 2)
			{
				std::cout << "2 bottles of beer on the wall, 2 bottles of beer.\n";
				std::cout << "Take one down, pass it around, 1 bottle of beer on the wall...\n";
			}
			if (i == 1)
			{
				std::cout << "1 bottle of beer on the wall, 1 bottle of beer.\n";
				std::cout << "No more bottles of beer on the wall, no more bottles of beer.\n";
				std::cout << "Go to the store and buy some more, 99 bottles of beer on the wall...\n";
			}
		}
	}
	return 0;
}