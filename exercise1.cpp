#include <iostream>
#include <array>

int main()
{
    std::array<int, 10> a{};
    a.fill(5);
    a[3] = 3;
    std::array<int, 10> b{};
    a.swap(b);

    for (auto element : a)
    {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    for (auto element : b)
    {
        std::cout << element << " ";
    }
    std::cout << std::endl;


    std::cout << "Hello world!" << std::endl;
    return 0;
}
