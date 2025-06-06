// Copyright 2022 NNTU-CS
#include <iostream>
#include <vector>
#include "tree.h"
int main() {
    std::vector<char> elems = {'A', 'B', 'C'};
    PMTree pTree(elems);
    std::vector<std::vector<char>> allPerms = getAllPerms(pTree);
    std::cout << "All permutations:" << std::endl;
    for (const auto& perm : allPerms) {
        for (char c : perm) {
            std::cout << c << " ";
        }
        std::cout << std::endl;
    }
   std::vector<char> perm1 = getPerm1(pTree, 1);
    std::cout << "\nPermutation 1:" << std::endl;
    for (char c : perm1) {
        std::cout << c << " ";
    }
    std::cout << std::endl;
    std::vector<char> perm2 = getPerm2(pTree, 2);
    std::cout << "\nPermutation 2:" << std::endl;
    for (char c : perm2) {
        std::cout << c << " ";
    }
    std::cout << std::endl;
    return 0;
}
