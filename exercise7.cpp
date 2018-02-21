#include <iostream>
#include <functional>

int main()
{
    int b = 1;
    std::function<int(int)> l =
        [&](int a){ return std::multiplies<int>()(a, b); };
    std::cout << l(11);
}
