#include <iostream>
#include <iterator>
#include <algorithm>
#include <deque>

void print(std::deque<int> & d)
{
    for (auto & element : d)
    {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::deque<int> d;
    std::generate_n(std::back_inserter(d), 14, [](){ return std::modulus<int>()(rand(), 7); });
    std::sort(d.begin(), d.end());
    print(d);

    auto last = std::unique(d.begin(), d.end());
    d.erase(last, d.end());
    print(d);

    std::rotate(d.begin(), d.begin() + (std::distance(d.begin(), d.end()) / 2), d.end());
    print(d);
}
