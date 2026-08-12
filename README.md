# C++ CLI Utility Tools
## Project Scope
CLI Utility created with C++. The program includes four tools:

1. **Prime Factorization Tool**: Takes a large integer and outputs its prime factorization.

2. **Base Converter**: Converts base 10 positive integers to bases 2 through 16.

3. **Descriptive Statistics Calculator**: Computes mean, median, mode, variance, and standard deviation from CLI-provided values.

4. **File Word Frequency Counter**: Reads a text file and outputs the top N most frequent words. **[NOT IMPLEMENTED YET]**

## Execution Instructions
- Clone and download the repository.
- Navigate to `CommandLineUtility` directory from your terminal.
- **Windows:**
    - Run the following command to create an execution file: 
        `g++ -std=c++17 main.cpp primeFactorization.cpp baseConverter.cpp descriptiveStatistics.cpp wordFrequencyCounter.cpp -o CommandLineUtility.exe`
    - Run execution file with: `CommandLineUtility.exe`
- **Linux/Mac:**
    - Run the following command to create an execution file: 
        `clang++ -std=c++17 main.cpp primeFactorization.cpp baseConverter.cpp descriptiveStatistics.cpp wordFrequencyCounter.cpp -o CommandLineUtility`
    - Run execution file with: `./CommandLineUtility`

## Note on file `CommandLineUtility`

The file `CommandLineUtility` was created wid -std=c++17 on macOS 26.5.2 (25F84).
