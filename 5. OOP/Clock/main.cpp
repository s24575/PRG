#include "header.h"
#include <algorithm>
#include <iterator>
#include <stdexcept>
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
	Calculator calc();
	for (auto const each : args)
		std::cout << each << '\n';
	for (auto const each : args) {
		if (each == "p")
			std::cout << "print" << '\n';
		else if (each == "+")
			std::cout << "plus" << '\n';
		else {
			//stack.push(std::stod(each));
			std::cout << "stack.push " << each << '\n';
			//calc.stack = (std::stod(each));
			}
		}
	//calc.logic(calc);
    return 0;
}

/*
input: 2 2 + p
["2","2","+","p"]
2 + 2 print
output: 4

Calculator calc(args);
calc.print(calc);
1. make a calculator object (std::stack<double>) so the stack = 2 2 + p
2. stack.push stack.push Addition::evaluate Print::evaluate
2. make a std::queue (pointers to Element class) stack.pop stack.pop evaluate print
3. schedule evaluation std::stack<double> using an Element subclass?
4. calc.push(stack) 
*/
