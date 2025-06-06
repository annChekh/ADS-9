// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <iostream>
#include <vector>
class PMTree {
 public:
    explicit PMTree(const std::vector<char>& elems);
    ~PMTree();
    std::vector<std::vector<char>> getAllPerms() const;
    std::vector<char> getPerm1(int num) const;
    std::vector<char> getPerm2(int num) const;

 private:
    struct Node {
        char value;
        std::vector<Node*> children;
        explicit Node(char val);
        ~Node();
    };
    Node* root;
    void generatePerms(Node* node, std::vector<char>& elems, 
                      std::vector<std::vector<char>>& path) const;
    bool getPerm1Helper(Node* node, int& count, int target,
                       std::vector<char>& path) const;
    bool getPerm2Helper(Node* node, int& count, int target,
                       std::vector<char>& path) const;
    void clear(Node* node);
};
#endif  // INCLUDE_TREE_H_
