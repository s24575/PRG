#include <iostream>

struct This
{
    void pointer()
    {
        std::cout << this* << '\n';
    }
};

int main()
{
    This a;
    a.pointer();
    std::cout << a& << '\n';
    return 0;
}
