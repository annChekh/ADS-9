// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  <algorithm>
#include  <vector>
#include  "tree.h"
PMTree::PMTree(const std::vector<char>& elements) : root(new Node('\0')) {
    std::vector<std::vector<char>> temp;
    generatePerms(root, const_cast<std::vector<char>&>(elements), temp);
}

PMTree::~PMTree() {
    clear(root);
}

PMTree::Node::Node(char val) : value(val) {}

PMTree::Node::~Node() {
    for (Node* child : children) {
        delete child;
    }
}

std::vector<std::vector<char>> PMTree::getAllPerms() const {
    std::vector<std::vector<char>> result;
    std::vector<char> current;
    generatePerms(root, current, result);
    return result;
}

void PMTree::generatePerms(Node* node, std::vector<char>& current,
                         std::vector<std::vector<char>>& result) const {
    if (current.empty()) {
        return;
    }
    for (char elem : current) {
        Node* child = new Node(elem);
        node->children.push_back(child);
        std::vector<char> remaining = current;
        remaining.erase(std::remove(remaining.begin(), remaining.end(), elem),
                       remaining.end());
        generatePerms(child, remaining, result);
    }
}

std::vector<char> PMTree::getPerm1(int num) const {
    std::vector<char> path;
    int count = 0;
    getPerm1Helper(root, count, num, path);
    return path;
}

bool PMTree::getPerm1Helper(const Node* node, int& count, int target,
                          std::vector<char>& path) const {
    if (count >= target) return true;
    if (node->children.empty()) {
        if (++count == target) {
            path.push_back(node->value);
            return true;
        }
        return false;
    }
    for (const Node* child : node->children) {
        path.push_back(child->value);
        if (getPerm1Helper(child, count, target, path)) {
            return true;
        }
        path.pop_back();
    }
    return false;
}

std::vector<char> PMTree::getPerm2(int num) const {
    std::vector<char> path;
    int count = 0;
    getPerm2Helper(root, count, num, path);
    return path;
}

bool PMTree::getPerm2Helper(const Node* node, int& count, int target,
                          std::vector<char>& path) const {
    if (count >= target) return true;
    if (node->children.empty()) {
        if (++count == target) {
            path.push_back(node->value);
            return true;
        }
        return false;
    }
    for (const Node* child : node->children) {
        path.push_back(child->value);
        if (getPerm2Helper(child, count, target, path)) {
            return true;
        }
        path.pop_back();
    }
    return false;
}

void PMTree::clear(Node* node) {
    for (Node* child : node->children) {
        clear(child);
    }
    delete node;
}

std::vector<char> getPerm1(PMTree& tree, int n) {
    return tree.getPerm1(n);
}

std::vector<char> getPerm2(PMTree& tree, int n) {
    return tree.getPerm2(n);
}
