#include <iostream>
#include <sstream>
#include <string>

struct Person
{
    std::string name;
    std::string surname;
    Person(std::string n, std::string s)
    {
        name = n;
        surname = s;
//        std::stringstream ss;
//        ss << n << ' ' << s;
//        std::string name = ss.str();
    }

    std::string to_string(std::string x)
    {
        return (x);
    }

    std::string who_is_it(Person const&)
    {
        
    }
};

int main()
{
    Person Mieszko("Mieszko", "II");
    std::cout << Mieszko.name << ' ' << Mieszko.surname << '\n';
    return 0;
}
