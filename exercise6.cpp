#include <forward_list>
#include <string>
#include <iostream>

int main()
{
    std::forward_list<int> fl = { 1, 2, 3, 4, 5, 6, 7 };
    auto it_b = begin(fl);
    auto it_e = end(fl);
    std::cout << "size: " << std::distance(it_b, it_e) << std::endl;
    auto it5 = fl.begin();
    std::advance(it5, 4);
    std::cout << *it5 << std::endl;
    std::cout << "distance: " << distance(it5, it_e) << std::endl;;
    return 0;
}
