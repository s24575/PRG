#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main(int argc, char* argv[])
{
	bool no_new_line = false;
	bool reversed_order = false;
	bool one_arg_per_line = false;
	auto args = std::vector<std::string>{};
	std::copy_n(argv + 1, argc - 1, std::back_inserter(args));
	for (auto const& each : args) {
		if (each == "-n")
			no_new_line = true;
		if (each == "-r")
			reversed_order = true;
		if (each == "-l")
			one_arg_per_line = true;
	}
	std::string x;
	if (one_arg_per_line == false)
		x = " ";
	else if (one_arg_per_line == true)
		x = "\n";
	if (reversed_order == true)
		std::reverse(args.begin(), args.end());
	for (auto const& each : args) {
	std::cout << each << x;
	}
	if (no_new_line == true)
		std::cout << "\n";
	return 0;
}
