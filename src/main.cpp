// Copyright 2022 NNTU-CS
#include <algorithm>
#include <chrono>
#include <vector>
#include "tree.h"

int main() {
  std::vector<char> elems = {'A', 'B', 'C'};
  PMTree pTree(elems);
  std::vector<std::vector<char>> res = pTree.getAllPerms();
  for (const auro& perm : res) {
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
  std::cout << "Permutation  2: ";
  for (char c : perm2) {
      std::cout << c;
  }
  std::cout << '\n';
  auto t1 = std::chrono::high_resolution_clock::now();
  auto t2 = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> elapsed = t2 - t1;
  std::cout << "Time: " << elapsed.count() << " s\n";
  return 0;
}
