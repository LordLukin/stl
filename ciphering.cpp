#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <random>
#include <map>
#include <iterator>
#include <unistd.h>


std::map<char,char> generate_key(){
    std::vector<char> keys(26);
    std::iota(keys.begin(), keys.end(), 'a');
    std::vector<char> keys_to_upper;

    std::transform(keys.begin(), keys.end(), std::back_inserter(keys_to_upper),[](char e){return e-'a'+'A';});

    keys.insert(keys.end(),keys_to_upper.begin(),keys_to_upper.end());

    for(auto elem:{' ', '!', '?', '.', ','}){
        keys.push_back(elem);
    }

    std::vector<char> values (keys);

    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(values.begin(), values.end(), g);

    std::map<char,char> key;

    for (int i=0; i<keys.size(); ++i){
        key[keys[i]] = values[i];
    }

    return key;
}

std::string cipher(std::string  &input, std::map<char, char> & cipher){
    std::string output;
    for(auto c: input){
        if (cipher.find(c) != cipher.end()) // this char uis
        {
            output += cipher[c];
        }else{
            output += c;
        }
    }
    return output;

}

std::string decipher(std::string &input,  std::map<char, char> & cipher){
    std::string output;
    for(auto c: input){
        if (cipher.find(c) != cipher.end()) // this char is in map
        {
            auto f = std::find_if(cipher.begin(), cipher.end(), [c](auto a){ return c == a.second; });
            output += (*f).first;
        }
        else
        {
            output += c;
        }
    }
    return output;
}



int main(int argc, char *argv[])
{
    std::map<char,char> key = generate_key();

    std::cin >> std::noskipws;
    std::istream_iterator<char> it(std::cin);
    std::istream_iterator<char> end;
    std::string input(it, end);

    //std::cout << "[" << results << "]\n";
    std::cout << "\nENCRYPTING... [";

    std::cout.flush();
    for(int i=0;i<52;i++)
    {
        std::cout << "=";
        std::cout.flush();
        usleep(100000);
    }

    std::cout << "]\t[ OK ]\n";

    std::cout << "\n\n=== ENCRYPTED MSG: ===\n\n";
    std::string result = cipher(input, key);
    std::cout << result << std::endl;

    std::cout << "\nDECRYPTING... [";

    std::cout.flush();
    for(int i=0;i<52;i++)
    {
        std::cout << "=";
        std::cout.flush();
        usleep(100000);
    }

    std::cout << "]\t[ OK ]\n";

    std::cout << "\n\n=== DECRYPTED MSG: ===\n\n";
    std::cout << decipher(result, key) << std::endl;

    return 0;
}
