#include <map>
#include <string>
#include <iostream>

int main()
{
    std::map<int, std::string> m = {{1, "one"},
                                    {2, "two"},
                                    {3, "thr"},
                                    {4, "four"},
                                    {5, "five"}};

    m[3] = "three";
    //auto it = m.find(5);
    m.erase(5);

    for (auto & el : m)
    {
        std::cout << el.first << ": " << m.count(el.first) << std::endl;
    }
    for(int i = 1; i <= 5; i++)
    {
        std::cout << i << ": " << m.count(i) << std::endl;
    }

    auto it4 = m.find(4);
    std::cout << it4->first << ": " << it4->second << std::endl;
    return 0;
}
