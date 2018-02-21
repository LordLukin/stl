#include <list>
#include <vector>
#include <iostream>
#include <numeric>


int main()
{
 /*   std::list<int> l;
    l.resize(1'000'000);
    std::iota(l.begin(), l.end(), 1);

    auto it = l.begin();
    std::advance(it, 500'000);

    std::cout << *it << std::endl;
*/
    std::vector<int> v;
    v.reserve(1'000'000);
    std::iota(v.begin(), v.end(), 1);
    std::cout << v[500'000] << std::endl;


    return 0;
}
