#include <iostream>
#include <string>
#include <sstream>

struct Student
{
    std::string name;
    std::string surname;
    std::string index_nr;
    int semester{};
    double grades_avg{};
    Student (std::string a, std::string b, std::string c, int d, double e) {name = a; surname = b; index_nr = c; semester = d; grades_avg = e;}
    std::string to_string()
    {
	std::stringstream print;
	print << name << ' ' << surname << " (" << index_nr << "), semester " << semester << ": " << grades_avg;
	return(print.str());
    }
};

int main()
{
    Student s1 = Student("Student", "Studencki", "12345", 1, 4.268);
    std::cout << s1.to_string() << '\n';
    return 0;
}
