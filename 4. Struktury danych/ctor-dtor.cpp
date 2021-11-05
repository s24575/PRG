#include <iostream>
#include <string>

struct ctor
{
    std::string string;
    ctor(std::string a) { string = a; }
    ~ctor()
    {
        std::cout << string << ' ' << "DESTRUCTION!\n";
    }
};

int main()
{
    ctor test = ctor("something");
    return 0;
}
