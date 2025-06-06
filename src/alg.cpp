// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  <algorithm>
#include  <vector>
#include  "tree.h"
PMTree::Node::Node(char val) : value(val) {}

PMTree::PMTree(const std::vector<char>& elems) : root(std::make_unique<Node>('\0')) {
    if (elems.empty()) return;
    std::vector<std::vector<char>> path;
    std::vector<char> elems_copy = elems;
    generatePerms(root.get(), elems_copy, path);
}

PMTree::~PMTree() = default;

void PMTree::generatePerms(Node* node, std::vector<char>& elems,
                         std::vector<std::vector<char>>& path) const {
    if (elems.empty()) {
        std::vector<char> current;
        Node* n = node;
        while (n && n->value != '\0') {
            current.push_back(n->value);
            n = n->children.empty() ? nullptr : n->children[0].get();
        }
        if (!current.empty()) path.push_back(current);
        return;
    }
    for (size_t i = 0; i < elems.size(); ++i) {
        auto child = std::make_unique<Node>(elems[i]);
        Node* child_ptr = child.get();
        node->children.push_back(std::move(child));
        std::vector<char> remaining = elems;
        remaining.erase(remaining.begin() + i);
        generatePerms(child_ptr, remaining, path);
    }
}

std::vector<std::vector<char>> PMTree::getAllPerms() const {
    std::vector<std::vector<char>> path;
    if (!root) return path;
    std::vector<char> elems;
    for (const auto& child : root->children) {
        elems.push_back(child->value);
    }
    generatePerms(root.get(), elems, path);
    return path;
}

std::vector<char> PMTree::getPerm1(int num) const {
    std::vector<char> path;
    if (num <= 0 || !root) return path;
    int count = 0;
    getPermHelper(root.get(), count, num, path, true);
    return path;
}

std::vector<char> PMTree::getPerm2(int num) const {
    std::vector<char> path;
    if (num <= 0 || !root) return path;
    int count = 0;
    getPermHelper(root.get(), count, num, path, false);
    return path;
}

bool PMTree::getPermHelper(Node* node, int& count, int num,
                          std::vector<char>& path, bool usePerm1) const {
    if (count >= num) return true;
    if (node->children.empty()) {
        if (++count == num) {
            path.push_back(node->value);
            return true;
        }
        return false;
    }
    for (const auto& child : node->children) {
        path.push_back(child->value);
        if (getPermHelper(child.get(), count, num, path, usePerm1)) {
            return true;
        }
        path.pop_back();
    }
    return false;
}
