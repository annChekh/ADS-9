// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  <algorithm>
#include  <vector>
#include  "tree.h"
PMTree::Node::Node(char val) : value(val) {}

PMTree::Node::~Node() {
    for (Node* child : children) {
        delete child;
    }
}

PMTree::PMTree(const std::vector<char>& elems) : root(new Node('\0')) {
    std::vector<std::vector<char>> path;
    generatePerms(root, const_cast<std::vector<char>&>(elems), path);
}

PMTree::~PMTree() {
    clear(root);
}

void PMTree::clear(Node* node) {
    if (!node) return;
    for (Node* child : node->children) {
        clear(child);
    }
    delete node;
}

void PMTree::generatePerms(Node* node, std::vector<char>& elems,
                          std::vector<std::vector<char>>& path) const {
    if (elems.empty()) return;
    for (char elem : elems) {
        Node* child = new Node(elem);
        node->children.push_back(child);
        std::vector<char> remaining = elems;
        remaining.erase(std::remove(remaining.begin(), remaining.end(), elem),
                       remaining.end());
        generatePerms(child, remaining, path);
    }
}

std::vector<std::vector<char>> PMTree::getAllPerms() const {
    std::vector<std::vector<char>> path;
    std::vector<char> current;
    generatePerms(root, current, path);
    return path;
}

std::vector<char> PMTree::getPerm1(int num) const {
    std::vector<char> path;
    int count = 0;
    getPerm1Helper(root, count, num, path);
    return path;
}

bool PMTree::getPerm1Helper(Node* node, int& count, int target,
                           std::vector<char>& path) const {
    if (count >= num) return true;
    if (node->children.empty()) {
        if (++count == target) {
            path.push_back(node->value);
            return true;
        }
        return false;
    }
    for (Node* child : node->children) {
        path.push_back(child->value);
        if (getPerm1Helper(child, count, target, path)) return true;
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

bool PMTree::getPerm2Helper(Node* node, int& count, int target,
                           std::vector<char>& path) const {
    if (count >= num) return true;
    if (node->children.empty()) {
        if (++count == target) {
            path.push_back(node->value);
            return true;
        }
        return false;
    }
    for (Node* child : node->children) {
        path.push_back(child->value);
        if (getPerm2Helper(child, count, target, path)) return true;
        path.pop_back();
    }
    return false;
}

std::vector<char> getPerm1(PMTree& tree, int num) {
    return tree.getPerm1(num);
}

std::vector<char> getPerm2(PMTree& tree, int num) {
    return tree.getPerm2(num);
}
