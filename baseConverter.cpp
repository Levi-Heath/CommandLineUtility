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

    File:   baseConverter.cpp
    Author: Levi Heath
    Brief:  This file contains the implementation of the base conversion tool,
            converts a positive integer from base 10 to a specified base between 2 and 16.
*/

#include "includes/utility.h"

void baseConverterTool() {
    std::cout << std::endl; // Add a newline for better readability
    std::cout << "===== BASE CONVERTER =====" << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // flush leftover newline
    uint64_t number = positiveIntegerInput(); // positiveIntegerInput() is defined in primeFactorization.cpp
    uint base = baseInput();
    std::string result = convertToBase(number, base);
    std::cout << "The number " << number << " in base " << base << " is: " << result << std::endl;
}

std::string convertToBase(uint64_t number, uint base) {
    const char* digits = "0123456789ABCDEF";
    std::string result;

    if (base < 2 || base > 16) {
        return "Invalid base";
    }

    do {
        result = digits[number % base] + result;
        number /= base;
    } while (number > 0);

    return result;
}

uint baseInput() {
    
    int base;
        
        while (true) {

            std::cout << "Enter a positive integer base between 2 and 16: ";

            // Attempt to read an integer
            if (std::cin >> base) {
                // Check for trailing characters (e.g., the '.' in "2.5")
                char nextChar = std::cin.peek();
                if (nextChar == '\n' || nextChar == ' ' || nextChar == std::char_traits<char>::eof()) {
                    // No trailing garbage, now check the value range
                    if (base > 2 && base <= 16) {
                        return static_cast<uint>(base); // Valid input
                    } else {
                        std::cout << "Invalid input. Base must be an integer between 2 and 16.\n";
                    }
                } else {
                    // Trailing characters exist (e.g., user entered "2.5")
                    std::cout << "Invalid input. Decimals are not allowed.\n";
                }
            } else {
                // Extraction failed completely (e.g., user entered "abc")
                std::cout << "Invalid input. Not an integer.\n";
            }

            // Clear error flags and discard the rest of the line
            std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
}