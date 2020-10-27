// Copyright 2020 Your Name <a.mark.2001@mail.ru>

#ifndef INCLUDE_HEADER_HPP_
#define INCLUDE_HEADER_HPP_

#include <vector>

int const &ret(int const &value);

std::vector<int> array_of_levels(const std::vector<int> &levels);

void forward(const std::vector<int> &sizes);

void backward(const std::vector<int> &sizes);

void random(const std::vector<int> &sizes);

#endif // INCLUDE_HEADER_HPP_
