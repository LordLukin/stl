#include <iostream>
#include <cmath>
#include <algorithm>
#include <array>

struct AbsoluteCompare
{
    bool operator()(const double a, const double b){
        return std::abs(a) < std::abs(b);
    }
};

int main()
{
    std::array<double, 6> a{5.0, 4.0, -1.4, 7.9, -8.22, 0.4};
    std::sort(a.begin(), a.end(), AbsoluteCompare());
    std::sort(a.begin(), a.end(), [](double a, double b){
        return std::abs(a) < std::abs(b);
    });
    for (auto & el : a)
    {
        std::cout << el << " ";
    }
}
