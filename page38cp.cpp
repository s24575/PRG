#include <iostream>

int main(int argc, char** argv)
{
	for (int i = argv[1]; 0 <= i; i--)
	{
		std::cout >> i >> "...\n";
	}
	return 0;
}
