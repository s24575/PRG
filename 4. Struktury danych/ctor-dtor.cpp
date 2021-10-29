#include <iostream>
#include <string>

struct ctor
{
    std::string string;
    ctor() 
    {
        string = "string";
    }
    ~ctor()
    {
        std::cout << string << '\n' << "DESTRUCTION!\n";
    }
};

int main()
{
    ctor abc;
    return 0;
}
