// Copyright 2020 Your Name <a.mark.2001@mail.ru>

#include <header.hpp>
#include <algorithm>
#include <iostream>
#include <vector>
#include <chrono>
#include <cmath>

int const &ret(int const &value) {
    return value;
}

std::vector<int> array_of_levels(const std::vector<int> &levels) {
    int min = *min_element(levels.begin(), levels.end());
    int max = *max_element(levels.begin(), levels.end());
    std::vector<int> sizes;
    sizes.push_back(min * 1024 / 2);
    int p;
    for (int i = 1; i < 99999999; ++i) {
        p = (min * 1024 / 2048) + i - 1;
        if (pow(2, p) < 3 * max * 1024 / 2048) {
            sizes.push_back(pow(2, p) * 1024);
        } else {
            break;
        }
    }
    sizes.push_back((3 * max * 1024) / 2);
    for (size_t i = 0; i < sizes.size(); ++i) {
        sizes[i] /= 4;
    }
    return sizes;
}

void forward(const std::vector<int> &sizes) {
    int counter = 0;
    std::cout << "forward: " << std::endl;
    for (auto &size : sizes) {
        int *arr = new int[size];
        srand(static_cast<unsigned int>(time(0)));
        for (int j = 0; j < size; ++j) {
            arr[j] = rand();
        }
        for (int j = 0; j < size; j += 16) {
            ret(arr[j]);
        }
        auto start = std::chrono::steady_clock::now();
        while (counter < 1000) {
            for (int j = 0; j < size; j += 16) {
                ret(arr[j]);
            }
            counter++;
        }
        auto finish = std::chrono::steady_clock::now();
        std::chrono::duration<double> duration = finish - start;
        std::cout << size * 4 << " kbaits - " << duration.count() * 1000000
                  << " ms" << std::endl;
        counter = 0;
        delete[]arr;
    }

}

void backward(const std::vector<int> &sizes) {
    int counter = 0;
    std::cout << "backward: " << std::endl;
    for (auto &size : sizes) {
        int *arr = new int[size];
        srand(static_cast<unsigned int>(time(0)));
        for (int j = 0; j < size; ++j) {
            arr[j] = rand();
        }
        for (int j = size; j > 0; j -= 16) {
            ret(arr[j]);
        }
        auto start1 = std::chrono::steady_clock::now();
        while (counter < 1000) {
            for (int j = size; j > 0; j -= 16) {
                ret(arr[j]);
            }
            counter++;
        }
        auto finish1 = std::chrono::steady_clock::now();
        std::chrono::duration<double> duration1 = finish1 - start1;
        std::cout << size * 4 << " kbaits - " << duration1.count() * 1000000
                  << " ms" << std::endl;
        counter = 0;
        delete[]arr;
    }

}

void random(const std::vector<int> &sizes) {
    int counter = 0;
    std::cout << "random: " << std::endl;
    for (auto &size : sizes) {
        int *arr = new int[size];
        srand(static_cast<unsigned int>(time(0)));
        srand(static_cast<unsigned int>(time(0)));
        for (int j = 0; j < size / 16; ++j) {
            ret(arr[rand() % (size) - 0]);
        }
        srand(static_cast<unsigned int>(time(0)));
        auto start2 = std::chrono::steady_clock::now();
        while (counter < 1000) {
            for (int j = 0; j < size / 16; ++j) {
                ret(arr[rand() % (size) - 0]);
            }
            counter++;
        }
        auto finish2 = std::chrono::steady_clock::now();
        std::chrono::duration<double> duration2 = finish2 - start2;
        std::cout << size * 4 << " kbaits - " << duration2.count() * 1000000
                  << " ms" << std::endl;
        counter = 0;
        delete[]arr;
    }
}