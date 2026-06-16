#include "array_processor.hpp"

#include <iostream>

int main() {
    std::cout << "Lab 6, variant 4\n\n";

    std::cout << "Type: int\n";
    ArrayProcessor<int> intProcessor(8, 0, 15);
    intProcessor.runVariant4();

    std::cout << "Type: double\n";
    ArrayProcessor<double> doubleProcessor(8, 0.0, 15.0);
    doubleProcessor.runVariant4();

    std::cout << "Type: long long\n";
    ArrayProcessor<long long> longProcessor(8, 0, 15);
    longProcessor.runVariant4();

    std::cout << "Type: double from source data\n";
    ArrayProcessor<double> sourcedProcessor({1.0, 3.5, 7.0, 9.5, 12.0, 4.0, 6.5, 10.0});
    sourcedProcessor.runVariant4();

    return 0;
}
