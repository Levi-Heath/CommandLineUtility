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
    Brief:  This file contains the main entry point for the command line utility program.
*/

#include "includes/utility.h"

// Function declarations
void displayMenu();
void pause();

// Main function
int main() {
    bool running = true;
    int primeFactorizationInput;
    // Main loop to handle menu choices
    while (running) {
        displayMenu();
        // Get and validate user choice
        // Call appropriate function based on choice
        int choice;
        std::cin >> choice;
        switch (choice) {
            case 1:
                // Call Prime Factorization Tool
                primeFactorizationTool();
                pause();
                break;
            case 2:
                // Call second utility function
                baseConverterTool();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the input buffer
                pause();
                break;
            case 3:
                // Call third utility function
                descriptiveStatisticsTool();
                pause();
                break;
            case 4:
                // Call fourth utility function
                std::cout << "Word Frequency Counter Tool is not yet implemented." << std::endl;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the input buffer
                pause();
                break;
            case 5:
                running = false; // Exit the loop
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
        std::cout << std::endl; // Add a newline for better readability
    }
    std::cout << "Exiting the program. Goodbye!" << std::endl << std::endl;
    return 0;
}

// Function prototypes
void displayMenu() {
    // Display menu options
    std::cout << "===== UTILITY PROGRAM MENU =====" << std::endl;
    std::cout << "1. Prime Factorization Tool" << std::endl;
    std::cout << "2. Base Converter" << std::endl;
    std::cout << "3. Descriptive Statistics Calculator" << std::endl;
    std::cout << "4. File Word Frequency Counter" << std::endl;
    std::cout << "5. Exit" << std::endl;
    std::cout << "Please enter your choice (1-5): ";
}

void pause() {
    std::cout << std::endl << "Press Enter to continue...";
    std::cin.get(); // Waits for user input (Enter key)
    std::cout << "Continuing..." << std::endl;
}