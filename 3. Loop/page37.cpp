#include <iostream>
#include <string>

int main(int argc, char** argv)
{
	std::string x;
	std::cin >> x;
	while (x != argv[1])
	{
		std::cout << "password: " << x << "\n";
		std::cin >> x;
	}
	std::cout << "ok!\n";
	return 0;
}
