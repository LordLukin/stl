#include <iostream>

bool is_palindrome(std::string a)
{
    auto iterators = std::mismatch(a.begin(), a.end(), a.rbegin(), a.rend());
    return iterators.first == a.end() and iterators.second == a.rend();
}

int main()
{
    std::cout << "kayak " << is_palindrome("kayak") << std::endl;
    std::cout << "ala ma kota " << is_palindrome("ala ma kota") << std::endl;
    std::cout << "bakajakab " << is_palindrome("bakajakab") << std::endl;
}
