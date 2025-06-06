// Copyright 2025 NNTU-CS
#include <gtest/gtest.h>
#include <string>
#include <vector>

#include "tree.h"
TEST(PMTreeTest, BasicFunctionality) {
    std::vector<char> elems = {'A', 'B', 'C'};
    PMTree tree(elems);
    auto all_paths = tree.getAllPerms();
    ASSERT_EQ(all_paths.size(), 6);
    std::set<std::vector<char>> unique_paths(all_paths.begin(), all_paths.end());
    ASSERT_EQ(unique_paths.size(), 6);
    for (const auto& p : all_paths) {
        ASSERT_EQ(p.size(), 3);
    }
    std::vector<char> path1 = tree.getPerm1(1);
    ASSERT_EQ(path1.size(), 3);
    std::vector<char> path2 = tree.getPerm2(2);
    ASSERT_EQ(path2.size(), 3);
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
