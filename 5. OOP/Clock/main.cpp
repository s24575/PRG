#include "header.h"
#include <algorithm>
#include <iterator>
#include <vector>
#include <cmath>

std::vector<std::string> make_args(int argc, char* argv[])
{
	auto args = std::vector<std::string>{};
	std::copy_n(argv, argc, std::back_inserter(args));
	return args;
}

int main(int argc, char* argv[])
{
	auto const args = make_args(argc - 1, argv + 1);
	std::unique_ptr<Calculator> calculator = std::make_unique<Calculator>();
	for (auto const each : args)
	{
		calculator->push(each);
	}
	calculator->evaluate();
	return 0;
}