#include <vector>
#include <iostream>

int main()
{
    std::vector<int> v;
    std::cout << "Size: " << v.size() << ", capacity: " << v.capacity() << std::endl;
    v.resize(10, 5);
    std::cout << "Size: " << v.size() << ", capacity: " << v.capacity() << std::endl;
    v.reserve(20);
    std::cout << "Size: " << v.size() << ", capacity: " << v.capacity() << std::endl;
    v.shrink_to_fit();
    std::cout << "Size: " << v.size() << ", capacity: " << v.capacity() << std::endl;
    return 0;
}
