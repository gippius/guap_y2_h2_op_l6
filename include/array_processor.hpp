#pragma once

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <random>
#include <string>
#include <type_traits>
#include <vector>

template <typename T>
struct SquareFunctor {
    T operator()(const T& value) const {
        return value * value;
    }
};

template <typename T>
struct InRangePredicate {
    T minValue;
    T maxValue;

    bool operator()(const T& value) const {
        return value >= minValue && value <= maxValue;
    }
};

template <typename T>
class ArrayProcessor {
public:
    ArrayProcessor(std::size_t size, T minValue, T maxValue) : generator_(42) {
        data_.resize(size);
        std::generate(data_.begin(), data_.end(), [this, minValue, maxValue]() {
            return randomValue(minValue, maxValue);
        });
    }

    explicit ArrayProcessor(const std::vector<T>& sourceData)
        : data_(sourceData), generator_(42) {}

    void setData(const std::vector<T>& sourceData) {
        data_ = sourceData;
    }

    void runVariant4() {
        print("Original array", data_);

        const bool allValuesInRange = std::all_of(
            data_.begin(),
            data_.end(),
            InRangePredicate<T>{static_cast<T>(0), static_cast<T>(15)}
        );
        std::cout << "All values are inside [0, 15]: " << (allValuesInRange ? "true" : "false") << '\n';

        copy_ = data_;
        print("Copied array", copy_);

        std::shuffle(copy_.begin(), copy_.end(), generator_);
        print("Shuffled copy", copy_);

        const double average = std::accumulate(data_.begin(), data_.end(), 0.0) / static_cast<double>(data_.size());
        std::cout << "Average value: " << std::fixed << std::setprecision(2) << average << '\n';

        std::vector<T> multiplied(data_.size());
        std::transform(data_.begin(), data_.end(), copy_.begin(), multiplied.begin(), std::multiplies<T>());
        print("Element-wise multiplication", multiplied);

        std::transform(multiplied.begin(), multiplied.end(), multiplied.begin(), SquareFunctor<T>{});
        print("Squared result", multiplied);
        std::cout << '\n';
    }

private:
    T randomValue(T minValue, T maxValue) {
        if constexpr (std::is_integral_v<T>) {
            std::uniform_int_distribution<long long> distribution(
                static_cast<long long>(minValue),
                static_cast<long long>(maxValue)
            );
            return static_cast<T>(distribution(generator_));
        }

        std::uniform_real_distribution<double> distribution(
            static_cast<double>(minValue),
            static_cast<double>(maxValue)
        );
        return static_cast<T>(distribution(generator_));
    }

    void print(const std::string& title, const std::vector<T>& values) const {
        std::cout << title << ": ";
        for (const T& value : values) {
            std::cout << std::fixed << std::setprecision(2) << value << ' ';
        }
        std::cout << '\n';
    }

    std::vector<T> data_;
    std::vector<T> copy_;
    std::mt19937 generator_;
};

