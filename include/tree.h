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
    void PMTree::generatePerms(Node* node, const std::vector<char>& elems,
                         std::vector<std::vector<char>>& path) const {
    if (elems.empty() || !node) return;
    for (char elem : elems) {
        Node* child = new Node(elem);
        if (!child) continue;
        node->children.push_back(child);
        std::vector<char> remaining = elems;
        remaining.erase(std::remove(remaining.begin(), remaining.end(), elem),
                      remaining.end());
        generatePerms(child, remaining, path);
    }
}
    bool getPerm1Helper(Node* node, int& count, int num,
                       std::vector<char>& path) const;
    bool getPerm2Helper(Node* node, int& count, int num,
                       std::vector<char>& path) const;
    void clear(Node* node);
};

std::vector<char> getPerm1(PMTree& tree, int num);
std::vector<char> getPerm2(PMTree& tree, int num);

#endif  // INCLUDE_TREE_H_
