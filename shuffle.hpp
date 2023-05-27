
/*

    Copyright (C) <2023> <Argo>
    
    This program is free software: 
    you can redistribute it and/or modify it under the terms of the GNU General Public License 
    as published by the Free Software Foundation, either version 3 of the License, 
    or (at your option) any later version.
    This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; 
    without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
    See the GNU General Public License for more details.
    You should have received a copy of the GNU General Public License along with this program. 
    If not, see <https://www.gnu.org/licenses/>. 

*/

#pragma once
#include <vector>
#include <cstdint>

class XorShift64 {
public:
    XorShift64(uint64_t seed) : state_(seed) {}

    uint64_t operator()() {
        state_ ^= state_ >> 12;
        state_ ^= state_ << 25;
        state_ ^= state_ >> 27;
        return state_ * 0xE242F577B17B2FA5;
    }

private:
    uint64_t state_;
};

template <typename T>
void shuffle(std::vector<T>& array, const uint64_t& seed) {
    XorShift64 rand(seed);
    
    for (std::size_t i = 0; i < array.size(); i++) {
        auto tmp = array[i];
        auto rnd = rand() % array.size();

        array[i] = array[rnd];
        array[rnd] = tmp;
    }
}

template <typename T>
void deshuffle(std::vector<T>& array, const uint64_t& seed) {
    XorShift64 rand(seed);
    std::vector<std::size_t> reserved_indices(array.size());

    for (auto& index : reserved_indices) {
        index = rand() % array.size();
    }
    
    for (int i = array.size() - 1; i >= 0; i--) {
        auto tmp = array[i];
        array[i] = array[reserved_indices[i]];
        array[reserved_indices[i]] = tmp;
    }
}