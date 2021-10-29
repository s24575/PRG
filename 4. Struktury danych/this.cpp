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
    cout << a& << '\n';
    return 0;
}
