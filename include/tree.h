// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <vector>
class PMTree {
 public:
    explicit PMTree(const std::vector<char>& elems);
    ~PMTree();
    std::vector<std::vector<char>> getAllPerms() const;
    std::vector<char> getPerm1(int n) const;
    std::vector<char> getPerm2(int n) const;

 private:
    struct Node {
      char value;
      std::vector<Node*> children;
      explicit Node(char val);
    };

    Node* root;
    void generatePerms(Node* node,
std::vector<char>& curr,
std::vector<std::vector<char>>& res) const;
    bool getPerm1Helper(const Node* node,
int& cnt, int n,
std::vector<char>& res) const;
    bool getPerm2Helper(const Node* node,
int& cnt, int n,
std::vector<char>& res) const;
    void clear(Node* node);
};
#endif  // INCLUDE_TREE_H_
