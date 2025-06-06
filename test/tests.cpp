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
    std::vector<char> perm1 = tree.getPerm1(1);
    ASSERT_EQ(perm1.size(), 3);
    std::vector<char> perm2 = tree.getPerm2(2);
    ASSERT_EQ(perm2.size(), 3);
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
