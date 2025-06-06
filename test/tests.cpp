// Copyright 2025 NNTU-CS
#include <gtest/gtest.h>
#include <string>
#include <vector>

#include "tree.h"
TEST(PMTreeTest, BasicFunctionality) {
    std::vector<char> elems = {'A', 'B', 'C'};
    PMTree tree(elems);
    auto permutations = tree.getAllPerms();
    ASSERT_EQ(permutations.size(), 6) <<;
    std::set<std::vector<char>> unique_perms(permutations.begin(), permutations.end());
    ASSERT_EQ(unique_perms.size(), 6) <<;
    for (const auto& perm : permutations) {
        ASSERT_EQ(perm.size(), 3);
        ASSERT_NE(std::find(perm.begin(), perm.end(), 'A'), perm.end());
        ASSERT_NE(std::find(perm.begin(), perm.end(), 'B'), perm.end());
        ASSERT_NE(std::find(perm.begin(), perm.end(), 'C'), perm.end());
    }
}
TEST(PMTreeTest, EdgeCases) {
    PMTree empty_tree({});
    ASSERT_TRUE(empty_tree.getAllPerms().empty());
    PMTree single_tree({'X'});
    auto single_paths = single_tree.getAllPerms();
    ASSERT_EQ(single_paths.size(), 1);
    ASSERT_EQ(single_paths[0].size(), 1);
}

TEST(PMTreeTest, InvalidRequests) {
    PMTree tree({'A', 'B'});
    ASSERT_TRUE(tree.getPerm1(0).empty());
    ASSERT_TRUE(tree.getPerm1(3).empty());
    ASSERT_TRUE(tree.getPerm2(0).empty());
    ASSERT_TRUE(tree.getPerm2(3).empty());
}
