// Copyright 2020 Your Name <a.mark.2001@mail.ru>

#include <chrono>
#include <gtest/gtest.h>
#include <header.hpp>
#include <vector>

TEST(Example, EmptyTest) {
EXPECT_TRUE(true);
std::vector<int> levels = {2, 4, 8};
std::vector<int> sizes = array_of_levels(levels);
forward(sizes);
backward(sizes);
random(sizes);
}
