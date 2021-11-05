#include <iostream>
#include <sstream>
#include <string>

struct Person
{
    std::string name;
    std::string surname;
    Person(std::string n, std::string s) { name = n; surname = s; }

    virtual std::string to_string(std::string x) = 0;
    {
	std::stringstream ss;
	ss << name << ' ' << surname;
        return(ss.str());
    }

    std::string who_is_it(Person const&)
    {
        std::cout << Person.to_string() << '\n';
    }
};

struct Mr : Person {};
{
    std::string to_string(std::string x) override;
    {
	std::stringstream ss;
	ss << "Mr" << name << ' ' << surname;
        return(ss.str());
    }
};

struct Mrs : Person {};
{
    std::string to_string(std::string x) override;
    {
	std::stringstream ss;
	ss << "Mrs" << name << ' ' << surname;
        return(ss.str());
    }
};

struct King : Person {};
{
    std::string to_string(std::string x) override;
    {
	std::stringstream ss;
	ss << "King" << name << ' ' << surname;
        return(ss.str());
    }
};

struct Queen : Person {};
{
    std::string to_string(std::string x) override;
    {
	std::stringstream ss;
	ss << "Queen" << name << ' ' << surname;
        return(ss.str());
    }
};

int main()
{
    King Mieszko = King("Mieszko", "II");
    Mieszko.to_string();
    return 0;
}

//struct Person
//virtual std::string to_string(std::string x) = 0;
//Person(std::string n, std::string s) { name = n; surname = s; }
//types? Mr, Mrs, King, Queen -> override function to_string()
//to_string() return(type, name, surname)
//who_is_it() std::cout << someone.to_string() << '\n'

//        std::stringstream ss;
//        ss << n << ' ' << s;
//        std::string name = ss.str();
