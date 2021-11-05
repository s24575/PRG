#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#define fill std::setw(2) << std::setfill('0') <<

struct Time
{
    int s{};
    int m{};
    int h{};

    Time(int a, int b, int c) { h = a; m = b; s = c; }

    void next_second() {
        s++;
        fix_time();
    }
    void next_minute() {
        m++;
        fix_time();
    }
    void next_hour() {
        h++;
        fix_time();
    }

    Time Add(const Time& other) const
    {
        return Time(h + other.h, m + other.m, s + other.s);
    }

    Time operator+ (const Time& other) const
    {
        return Add(other);
    }

    Time Subtract(const Time& other) const
    {
        return Time(h - other.h, m - other.m, s - other.s);
    }

    Time operator- (const Time& other) const
    {
        return Subtract(other);
    }

    bool Smaller_than(const Time& other) const
    {
        if (h < other.h)
            return true;
        if (h > other.h)
            return false;
        if (m < other.m)
                return true;
        if (m > other.m)
            return false;
        if (s < other.s)
                return true;
        if (s > other.s)
            return false;
        else
            return false;
    }

    bool operator< (const Time& other) const
    {
        return Smaller_than(other);
    }

    bool Bigger_than(const Time& other) const
    {
        if (h < other.h)
            return false;
        if (h > other.h)
            return true;
        if (m < other.m)
            return false;
        if (m > other.m)
            return true;
        if (s < other.s)
            return false;
        if (s > other.s)
            return true;
        else
            return false;
    }

    bool operator> (const Time& other) const
    {
        return Bigger_than(other);
    }

    bool Equal(const Time& other) const
    {
        if (h == other.h)
        {
            if (m == other.m)
            {
                if (s == other.s)
                    return true;
            }
        }
        return false;
    }

    bool operator== (const Time& other) const
    {
        return Equal(other);
    }

    void time_of_day()
    {
        if (0 <= h && h < 6)
            std::cout << "night" << '\n';
        else if (6 <= h && h < 12)
            std::cout << "morning" << '\n';
        else if (12 <= h && h < 18)
            std::cout << "afternoon" << '\n';
        else if (18 <= h && h < 24)
            std::cout << "evening" << '\n';
    }

    int count_seconds()
    {
        int x = 3600 * h + 60 * m + s;
        return(x);
    }

    int count_minutes()
    {
        int x = 60 * h + m;
        return(x);
    }

    Time time_to_midnight()
    {
        s = 60 - s;
        m = 59 - m;
        h = 23 - h;
        return(Time(h, m, s));
    }

    void fix_time()
    {
        while (s >= 60)
        {
            s -= 60;
            m++;
        }
        while (s < 0)
        {
            s += 60;
            m--;
        }
        while (m >= 60)
        {
            m -= 60;
            h++;
        }
        while (m < 0)
        {
            m += 60;
            h--;
        }
        while (h >= 24)
            h -= 24;
        while (h < 0)
            h += 24;
    }

    std::string to_string()
    {
        fix_time();
        std::stringstream string;
        string << fill h << ':' << fill m << ':' << fill s;
        return(string.str());
    }
};

int main()
{
    Time time = Time{ 23, 59, 59 };
    std::cout << time.to_string() << '\n';

    Time time1 = Time{ 23, 59, 59 };
    time1.next_hour();
    std::cout << time1.to_string() << '\n';

    Time time2 = Time{ 23, 59, 59 };
    time2.next_minute();
    std::cout << time2.to_string() << '\n';

    Time time3 = Time{ 23, 59, 59 };
    time3.next_second();
    std::cout << time3.to_string() << '\n';

    Time time4 = Time{ 23, 59, 59 };
    time4.time_of_day();

    Time a = Time{ 23, 59, 59 };
    Time b = Time{ 0,  0,  1 };
    Time c = a + b;
    std::cout << c.to_string() << '\n';

    Time a1 = Time{ 3, 59, 59 };
    Time b1 = Time{ 4,  0,  0 };
    Time c1 = a1 - b1;
    std::cout << c1.to_string() << '\n';

    Time a2 = Time{ 23, 59, 59 };
    Time b2 = Time{ 0,  0,  1 };
    if (a2 > b2) {
        std::cout << a2.to_string() << " > " << b2.to_string() << "\n";
    }
    else {
        std::cout << a2.to_string() << " ? " << b2.to_string() << "\n";;
    }

    Time a3 = Time{ 23, 59, 59 };
    Time b3 = Time{ 0,  0,  1 };
    if (a3 == b3) {
        std::cout << a3.to_string() << " == " << b3.to_string() << "\n";;
    }
    else {
        std::cout << a3.to_string() << " != " << b3.to_string() << "\n";
    }

    Time time5 = Time{ 23, 59, 59 };
    time5.count_seconds();

    Time time6 = Time{ 23, 59, 59 };
    time6.count_minutes();

    Time time7 = Time{ 23, 59, 59 };
    time7.time_to_midnight();
    std::cout << time7.to_string() << '\n';
    
    return 0;
}