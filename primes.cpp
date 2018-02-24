#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <random>
#include <map>


template<class Type>
struct ConsecutiveNumbersGenerator
{
    ConsecutiveNumbersGenerator(Type startNumber)
        : m_startNumber(startNumber)
    {}

    Type operator()()
    {
        return m_startNumber++;
    }

private:
    Type m_startNumber;
};


auto getPrimes(int numOfValues)
{
    std::vector<int> values;
    values.reserve(numOfValues);

    std::generate_n(std::back_inserter(values), numOfValues, ConsecutiveNumbersGenerator<int>(2));

    std::vector<int> primes;
    std::copy_if(std::begin(values), std::end(values), std::back_inserter(primes), [&primes](auto v)
    {
        return std::all_of(std::begin(primes), std::end(primes), [v](auto k)
        {
            return (v % k) != 0;
        });
    });
    return primes;
}

template<class Type>
auto & operator<<(std::ostream & out, std::vector<Type> const& container)
{
    std::copy(std::begin(container), std::end(container), std::ostream_iterator<Type>(out, " "));
    return out;
}

int main()
{
    constexpr int RANGE_OF_VALUES = 1000;

    auto primes = getPrimes(RANGE_OF_VALUES);

    std::cout << "Primes:\n" << primes << std::endl;

    constexpr int NUM_OF_VALUES = 100;

    std::vector<int> values;
    values.reserve(NUM_OF_VALUES);

    std::random_device rd;
    std::uniform_int_distribution<int> dist(1, 1000);
    std::generate_n(std::back_inserter(values), NUM_OF_VALUES, [&](){ return dist(rd); });

    std::map<int, std::vector<int>> dividers;
    std::transform(std::begin(primes), std::end(primes), std::inserter(dividers, std::begin(dividers)), [&values](auto prime)
    {
        std::vector<int> v;
        std::copy_if(std::begin(values), std::end(values), std::back_inserter(v), [prime](auto v)
        {
            return (v % prime) == 0;
        });
        return std::make_pair(prime, v);
    });


    std::cout << "\nValues:\n" << values << std::endl;

    for(auto const& kv : dividers)
    {
        std::cout << "Dividers[" << kv.first << "]: " << kv.second << std::endl;
    }

    return 0;
}
