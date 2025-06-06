// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  <algorithm>
#include <stdexcept>
#include  <vector>
#include  "tree.h"
PMTree::Node::Node(char val) : value(val) {}

PMTree::PMTree(const std::vector<char>& elems) : root(std::make_unique<Node>('\0')) {
    if (elems.empty()) return;
    std::vector<char> remaining = elems;
    generatePerms(root.get(), remaining, {});
}

PMTree::~PMTree() = default;

void PMTree::generatePerms(Node* node, std::vector<char>& remaining,
                         std::vector<char> current) const {
    if (!node) return;
    if (node->value != '\0') {
        current.push_back(node->value);
    }
    if (remaining.empty()) {
        if (!current.empty()) {
            const_cast<std::vector<std::vector<char>>&>(getAllPerms()).push_back(current);
        }
        return;
    }
    for (size_t i = 0; i < remaining.size(); ++i) {
        auto child = std::make_unique<Node>(remaining[i]);
        std::vector<char> new_remaining = remaining;
        new_remaining.erase(new_remaining.begin() + i);
        generatePerms(child.get(), new_remaining, current);
        node->children.push_back(std::move(child));
    }
}

std::vector<std::vector<char>> PMTree::getAllPerms() const {
    static std::vector<std::vector<char>> all_perms;
    all_perms.clear();
    if (root && !root->children.empty()) {
        std::vector<char> empty;
        for (const auto& child : root->children) {
            std::vector<char> remaining;
            for (const auto& sibling : root->children) {
                if (sibling.get() != child.get()) {
                    remaining.push_back(sibling->value);
                }
            }
            generatePerms(child.get(), remaining, empty);
        }
    }
    return all_perms;
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
