# include <iostream>
# include <string>
int main (int argc , char * argv [])
{
	auto const a = std::stof (argv [1]);
	auto const b = std::stof (argv [2]);
	std::cout << (a / b) << "\n";
	return 0;
}
