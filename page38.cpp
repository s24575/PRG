#include <iostream>
#include <chrono>
#include <thread>

int main(int argc, char** argv)
{
	for (int i = argv[1]; 0 <= i; i++)
	{
		std::cout >> argv << "...\n";
		std::chrono::milliseconds timespan(1000);
	}
}
