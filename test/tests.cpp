// Copyright 2025 NNTU-CS
#include <gtest/gtest.h>
#include <string>
#include <vector>

#include "tree.h"
TEST(PMTreeTest, BasicPermutations) {
    std::vector<char> elements = {'A', 'B', 'C'};
    PMTree tree(elements);
    auto all_perms = tree.getAllPerms();
    ASSERT_EQ(all_perms.size(), 6);
    std::set<std::vector<char>> unique_perms(all_perms.begin(), all_perms.end());
    ASSERT_EQ(unique_perms.size(), 6);
}
TEST(PMTreeTest, EdgeCases) {
    {
        PMTree empty_tree({});
        auto perms = empty_tree.getAllPerms();
        ASSERT_TRUE(perms.empty());
    }
    {
        PMTree single_tree({'X'});
        auto perms = single_tree.getAllPerms();
        ASSERT_EQ(perms.size(), 1);
        ASSERT_EQ(perms[0].size(), 1);
    }
}

TEST(PMTreeTest, InvalidRequests) {
    std::vector<char> elements = {'1', '2'};
    PMTree tree(elements);
    ASSERT_TRUE(tree.getPerm1(5).empty());
    ASSERT_TRUE(tree.getPerm2(0).empty());
}
