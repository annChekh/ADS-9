// Copyright 2022 NNTU-CS
#include <iostream>
#include <algorithm>
#include <vector>
#include <chrono>
#include "tree.h"
int main() {
    std::vector<char> elems = {'A', 'B', 'C'};
    PMTree pTree(elems);
    auto t1 = std::chrono::high_resolution_clock::now();
    std::vector<std::vector<char>> path = pTree.getAllPerms();
    auto t2 = std::chrono::high_resolution_clock::now();
    for (const auto& perm : path) {
        for (char c : perm) {
            std::cout << c;
        }
        std::cout << '\n';
    }
    std::vector<char> perm1 = pTree.getPerm1(1);
    std::cout << "Permutation 1: ";
    for (char c : perm1) {
        std::cout << c;
    }
    std::cout << '\n';
    std::vector<char> perm2 = pTree.getPerm2(2);
    std::cout << "Permutation 2: ";
    for (char c : perm2) {
        std::cout << c;
    }
    std::cout << '\n';
    std::chrono::duration<double> elapsed = t2 - t1;
    std::cout << "Time: " << elapsed.count() << " s\n";
    return 0;
}
