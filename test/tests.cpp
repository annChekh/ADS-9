// Copyright 2025 NNTU-CS
#include <gtest/gtest.h>
#include <string>
#include <vector>

#include "tree.h"

TEST(ads9_test1, basic) {
    std::vector<char> elements = {'1', '2', '3'};
    PMTree tree(elements);
    
    std::vector<char> result = tree.getPerm1(1);
    ASSERT_FALSE(result.empty());
    ASSERT_EQ(result.size(), 3);
}

TEST(ads9_test2, basic) {
    std::vector<char> elements = {'1', '2', '3'};
    PMTree tree(elements);
    
    std::vector<char> result = tree.getPerm2(2);
    ASSERT_FALSE(result.empty());
    ASSERT_EQ(result.size(), 3);
}

TEST(ads9_test3, basic) {
    std::vector<char> elements = {'1', '2', '3'};
    PMTree tree(elements);
    
    std::vector<char> result = tree.getPerm1(6);
    ASSERT_TRUE(result.empty());  // Для несуществующей перестановки
}

TEST(ads9_test4, basic) {
    std::vector<char> elements = {'1', '2', '3'};
    PMTree tree(elements);
    
    std::vector<char> result = tree.getPerm2(8);
    ASSERT_TRUE(result.empty());  // Для несуществующей перестановки
}
