#include <iostream>
#include <string>

struct Student
{
    std::string name;
    std::string surname;
    std::string index_nr;
    int semester{};
    double grades_avg{};
    void print()
    {
        std::cout << name << ' ' << surname << " (" << index_nr << "), semester " << semester << ": " << grades_avg;
    }
};

int main()
{
	Student s1;
    s1.name = "Student";
    s1.surname = "Studencki";
    s1.index_nr = "12345";
    s1.semester = 1;
    s1.grades_avg = 4.268;
    s1.print();
    return 0;
}