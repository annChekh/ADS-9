// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <vector>
#include <memory>

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
        std::vector<std::unique_ptr<Node>> children;
        explicit Node(char val);
    };
    std::unique_ptr<Node> root;
    void generatePerms(Node* node, std::vector<char>& elems,
                     std::vector<std::vector<char>>& path) const;
    bool getPermHelper(Node* node, int& count, int num,
                     std::vector<char>& path, bool usePerm1) const;
};
#endif  // INCLUDE_TREE_H_
