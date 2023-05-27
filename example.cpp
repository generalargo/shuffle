#include "shuffle.hpp"
#include <iostream>
#include <vector>

int main() {

    std::vector<std::string> vec = { "a1", "a2", "a3", "a4", "a5", "a6", "a7", "a8", "a9", "a10" };
    std::uint64_t seed = 1234;
    
    std::cout << "Оригинальный массив: " << "\n";
    for (auto &&i : vec)
    {
        std::cout << i << " ";
    } std::cout << std::endl;
    
    shuffle(vec, seed);
    
    std::cout << "Перемешанный массив: " << "\n";
    for (auto &&i : vec)
    {
        std::cout << i << " ";
    } std::cout << std::endl;
    
    deshuffle(vec, seed);
    
    std::cout << "Восстановленный в исходном порядке массив: " << "\n";
    for (auto &&i : vec)
    {
        std::cout << i << " ";
    } std::cout << std::endl;

    return 0;
}