/* Copyright 2026 Levi Heath

    Licensed under the MIT License (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

         https://opensource.org/licenses/MIT

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.

    File:   utility.h
    Author: Levi Heath
    Brief:  This file contains utility function declarations for the command line utility program.
*/

#ifndef UTILITY_H
#define UTILITY_H

#include <iostream>     // std::cout, std::cin
#include <string>       // std::string, std::getline
#include <charconv>     // std::from_chars, std::errc
#include <cstdint>      // uint64_t, UINT64_MAX
#include <limits>       // std::numeric_limits (used at call site for cin.ignore)
#include <climits>      // For UINT64_MAX
#include <vector>       // std::vector
#include <algorithm>    // std::sort, std::max_element
#include <sstream>      // std::istringstream iss
#include <map>          // std::map

// Function declarations
// Functions for prime factorization
void primeFactorizationTool();
void primeFactorization(uint64_t n);
uint64_t positiveIntegerInput();

// Functions for base conversion
void baseConverterTool();
std::string convertToBase(uint64_t number, uint base);
uint baseInput();

// Functions for descriptive statistics
class Data; // Forward declaration of Data class
void descriptiveStatisticsTool();
Data getDataInput();

#endif // UTILITY_H
