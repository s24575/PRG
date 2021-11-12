#include <iostream>

struct This
{
    void pointer()
    {
        This* e = this;
        std::cout << e << '\n';
    }
};

int main()
{
    This a;
    a.pointer();
    std::cout << &a << '\n';
    return 0;
}