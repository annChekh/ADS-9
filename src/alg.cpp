// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "tree.h"

PMTree::PMTree(const std::vector<char>& elements) {
  root = new Node('\0');
  buildTree(elements);
}

void PMTree::buildTree(const std::vector<char>& elements) {
  generatePerms(root, elements, {});
}

void PMTree::generatePerms(Node* node, std::vector<char>& curr, std::vector<std::vector<char>>& res) {
    if (curr.empty()) {
        return;
    }

    for (char c : curr) {
        Node* child = new Node(c);
        node->children.push_back(child);
        
        std::vector<char> remaining = curr;
        remaining.erase(std::remove(remaining.begin(), remaining.end(), c), remaining.end());
        
        generatePerms(child, remaining, res);
    }
}

std::vector<std::vector<char>> PMTree::getAllPerms() {
    std::vector<std::vector<char>> res;
    std::vector<char> curr;
    generatePerms(root, curr, res);
    return res;
}

std::vector<char> PMTree::getPerm1(int n) {
    std::vector<char> res;
    int cnt = 0;
    getPerm1Helper(root, cnt, n, res);
    return res;
}

void PMTree::getPerm1Helper(Node* node, int& cnt, int n, std::vector<char>& res) {
    if (cnt >= n) return;

    if (node->children.empty()) {
        cnt++;
        if (cnt == n) {
            res.push_back(node->value);
        }
        return;
    }

    for (Node* child : node->children) {
        res.push_back(child->value);
        getPerm1Helper(child, cnt, n, res);
        if (cnt >= n) return;
        res.pop_back();
    }
}

std::vector<char> PMTree::getPerm2(int n) {
    std::vector<char> res;
    int cnt = 0;
    getPerm2Helper(root, cnt, n, res);
    return res;
}

void PMTree::getPerm2Helper(Node* node, int& cnt, int n, std::vector<char>& res) {
    if (cnt >= n) return;

    if (node->children.empty()) {
        cnt++;
        if (cnt == n) {
            res.push_back(node->value);
        }
        return;
    }

    for (Node* child : node->children) {
        res.push_back(child->value);
        getPerm2Helper(child, cnt, n, res);
        if (cnt >= n) return;
        res.pop_back();
    }
}

void PMTree::clear(Node* node) {
    for (Node* child : node->children) {
        clear(child);
    }
    delete node;
}

PMTree::~PMTree() {
    clear(root);
}
