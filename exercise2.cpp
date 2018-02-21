#include <vector>
#include <iostream>

int main()
{
    std::vector<int> v {1, 2, 4, 5, 6};
    std::cout << v.capacity();
    v.erase(v.begin());
    v.emplace_back(5);
    v.emplace(v.begin(), 12);

    std::cout << v.size() << " " << v.max_size() << std::endl;

    for (auto& element : v)
    {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    v.clear();

    for (auto& element : v)
    {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    return 0;
}
