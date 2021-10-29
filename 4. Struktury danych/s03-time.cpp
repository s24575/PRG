#include <iostream>
#include <string>
#include <iomanip>
#define fill std::setw(2) << std::setfill('0') <<

struct Time
{
    int s{};
    int m{};
    int h{};

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

    void count_seconds()
    {
        int x = 3600 * h + 60 * m + s;
        std::cout << x << '\n';
    }
    
    void count_minutes()
    {
        int x = 60 * h + m;
        std::cout << x << '\n';
    }

    void time_to_midnight()
    {
        s = 60 - s;
        m = 59 - m;
        h = 23 - h;
    }

    void set_time(int a, int b, int c)
    {
        h = a;
        m = b;
        s = c;
    }

    void fix_time()
    {
        if (s >= 60)
        {
            s = s - 60;
            m++;
        }
        if (m >= 60)
        {
            m = m - 60;
            h++;
        }
        if (h >= 24)
            h = h - 24;
    }

    void print()
    {
        fix_time();
        std::cout << fill h << ':' << fill m << ':' << fill s << '\n';
    }
};

int main()
{
    Time clock;
    clock.set_time(23, 59, 59);
    clock.print();
    clock.next_minute();
    clock.time_to_midnight();
    clock.print();
    return 0;
}