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

    File:   descriptiveStatistics.cpp
    Author: Levi Heath
    Brief:  This file contains the implementation of the descriptiveStatistics function, 
            which calculates and displays descriptive statistics for a given dataset.
*/

#include "includes/utility.h"

class Data {
     public:
          std::vector<double> values;
          Data(const std::vector<double>& vals) : values(vals) {}
          
          // Function to get the values
          std::vector<double> getValues() const {
               return values;
          }

          // mean
               double mean() const {
                    double sum = 0.0;
                    for (double num : values) {
                         sum += num;
                    }
                    return sum / values.size();
               }

               // median
               double median() const {
                    std::vector<double> sortedValues = values;
                    std::sort(sortedValues.begin(), sortedValues.end());
                    size_t size = sortedValues.size();
                    if (size % 2 == 0) {
                         return (sortedValues[size / 2 - 1] + sortedValues[size / 2]) / 2.0;
                    } else {
                         return sortedValues[size / 2];
                    }
               }

               // mode
               double mode() const {
                    std::map<double, int> frequencyMap;
                    for (double num : values) {
                         frequencyMap[num]++;
                    }
                    int maxFrequency = 0;
                    double modeValue = values[0];
                    for (const auto& pair : frequencyMap) {
                         if (pair.second > maxFrequency) {
                              maxFrequency = pair.second;
                              modeValue = pair.first;
                              if (maxFrequency == 1) {
                                   modeValue = NAN; // No mode if all values are unique
                              }
                         }
                    }
                    return modeValue;
               }

               // variance
               double variance() const {
                    double meanValue = mean();
                    double varianceValue = 0.0;
                    for (double num : values) {
                         varianceValue += (num - meanValue) * (num - meanValue);
                    }
                    return varianceValue / values.size();
               }

               // standard deviation
               double standardDeviation() const {
                    return std::sqrt(variance());
               }
};

void descriptiveStatisticsTool() {
    std::cout << std::endl; // Add a newline for better readability
    std::cout << "===== DESCRIPTIVE STATISTICS TOOL =====" << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // flush leftover newline
    Data dataInput = getDataInput();

    std::cout << "Mean: " << dataInput.mean() << std::endl;
    std::cout << "Median: " << dataInput.median() << std::endl;
    if (dataInput.mode() != dataInput.mode()) { // Check for NaN
        std::cout << "Mode: No mode; each value is unique." << std::endl;
    } else {
        std::cout << "Mode: " << dataInput.mode() << std::endl;
    }
    std::cout << "Variance: " << dataInput.variance() << std::endl;
    std::cout << "Standard Deviation: " << dataInput.standardDeviation() << std::endl;
}

Data getDataInput() {
     std::vector<double> inputVector;
     std::string inputString;
     std::cout << "Enter numbers separated by spaces: ";

     std::getline(std::cin, inputString);
     std::istringstream iss(inputString);
     double number;
     while (iss >> number) {
          inputVector.push_back(number);
     }

     return Data(inputVector);
}
