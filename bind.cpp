#include <functional>
#include <iostream>

int main()
{
    auto multiplyBy5 = [](int a) { return a * 5; };
    auto multiply5 = std::bind(multiplyBy5,11);


    std::cout << multiplyBy5(11);
    std::cout << multiply5();
    return 0;
}
