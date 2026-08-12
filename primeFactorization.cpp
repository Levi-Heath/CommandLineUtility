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

    File:   primeFactorization.cpp
    Author: Levi Heath
    Brief:  This file contains the implementation of the prime factorization tool,
            which computes the prime factorization of a given positive integer greater than 1 and less than 2^64 (UINT64_MAX+1).
*/

#include "includes/utility.h"


void primeFactorizationTool() {
    std::cout << std::endl; // Add a newline for better readability
    std::cout << "===== PRIME FACTORIZATION TOOL =====" << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // flush leftover newline
    uint64_t n = positiveIntegerInput();
    primeFactorization(n);
}

void primeFactorization(uint64_t n) {

    std::cout << "Prime factorization of " << n << " is: ";
    
    for (uint64_t i = 2; i <= n; i++) {
        while (n % i == 0) {
            std::cout << i << " ";
            n /= i;
        }
    }
    
    std::cout << std::endl;
}

uint64_t positiveIntegerInput() {
    
    std::string input;

    while (true) {

        std::cout << "Enter a positive integer greater than 1 and less than or equal to " << UINT64_MAX << ": ";

        // Read entire line to prevent cin stream corruption on bad input
        if (!std::getline(std::cin, input)) {
            std::cout << "Input stream error.\n";
            std::cin.clear();
            continue;
        }

        // Trim leading and trailing whitespace
        auto start = input.find_first_not_of(" \t\r\n");
        auto end   = input.find_last_not_of(" \t\r\n");

        if (start == std::string::npos) {
            std::cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        input = input.substr(start, end - start + 1);

        // Reject negative numbers explicitly (from_chars UB on some implementations)
        if (input[0] == '-') {
            std::cout << "Invalid input. Number must be greater than 1.\n";
            continue;
        }

        // Reject leading zeros (e.g. "007")
        if (input.size() > 1 && input[0] == '0') {
            std::cout << "Invalid input. Leading zeros are not allowed.\n";
            continue;
        }

        // Parse with from_chars
        uint64_t n;
        auto [ptr, ec] = std::from_chars(
            input.data(),
            input.data() + input.size(),
            n
        );

        // Check for parse errors
        if (ec == std::errc::invalid_argument) {
            std::cout << "Invalid input. Not an integer.\n";
            continue;
        }

        if (ec == std::errc::result_out_of_range) {
            std::cout << "Invalid input. Number exceeds uint64_t maximum ("
                      << UINT64_MAX << ").\n";
            continue;
        }

        // Ensure entire string was consumed (catches "123abc", "2.5", etc.)
        if (ptr != input.data() + input.size()) {
            std::cout << "Invalid input. Unexpected characters detected.\n";
            continue;
        }

        // Range check: must be greater than 1
        if (n <= 1) {
            std::cout << "Invalid input. Number must be greater than 1.\n";
            continue;
        }

        return n; // Valid input
    }
}