#include <iostream>
#include <sstream>
#include <string>

struct Person
{
    std::string name;
    std::string surname;

    Person(std::string n, std::string s) : name(n), surname(s) {}

    virtual std::string to_string() = 0;

    std::string who_is_it(Person& x) { return x.to_string(); }
};

struct Mr : Person
{
    using Person::Person;

    std::string to_string() override
    {
        std::stringstream ss;
        ss << "Mr " << name << ' ' << surname;
        return(ss.str());
    }
};

struct Mrs : Person
{
    using Person::Person;

    std::string to_string() override
    {
        std::stringstream ss;
        ss << "Mrs " << name << ' ' << surname;
        return(ss.str());
    }
};

struct King : Person
{
    using Person::Person;

    std::string to_string() override
    {
        std::stringstream ss;
        ss << "King " << name << ' ' << surname;
        return(ss.str());
    }
};

struct Queen : Person
{
    using Person::Person;

    std::string to_string() override
    {
        std::stringstream ss;
        ss << "Queen " << name << ' ' << surname;
        return(ss.str());
    }
};

struct Greeting
{
    virtual std::string greet(Person&) = 0;
};

struct Hello : Greeting
{
    std::string greet(Person& x) override
    {
        std::stringstream ss;
        ss << "Hello, " << x.to_string() << '\n';
        return(ss.str());
    }
};

struct Good_evening : Greeting
{
    std::string greet(Person& x) override
    {
        std::stringstream ss;
        ss << "Good evening, " << x.to_string() << '\n';
        return(ss.str());
    }
};

struct Farewell : Greeting
{
    std::string greet(Person& x) override
    {
        std::stringstream ss;
        ss << "Farewell, " << x.to_string() << '\n';
        return(ss.str());
    }
};

int main()
{
    King Mieszko("Mieszko", "II");
    std::cout << Mieszko.to_string() << '\n';
    Queen Elizabeth("Elizabeth", "II");
    std::cout << Elizabeth.to_string() << '\n';
    Mr Bean("Rowan", "Atkinson");
    std::cout << Bean.to_string() << '\n';
    Mrs Popular("Mary", "Smith");
    std::cout << Popular.to_string() << "\n\n";

    std::cout << Mieszko.who_is_it(Mieszko) << "\n\n"; // but why?

    Hello hi;
    Good_evening goodbye;
    Farewell bye;

    std::cout << hi.greet(Mieszko);
    std::cout << goodbye.greet(Elizabeth);
    std::cout << bye.greet(Bean);
    return 0;
}