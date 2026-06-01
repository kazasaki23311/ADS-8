// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

template<typename T>
class BST {
  private:
  struct Node {
    T data;
    int count;
    Node* left;
    Node* right;
  };

  Node* root;

  Node* addNode(Node* root, const T& data) {
    if (root == nullptr) {
      root = new Node;
      root->data = data;
      root->count = 1;
      root->left = nullptr;
      root->right = nullptr;
      } else if (data < root->data) {
      root->left = addNode(root->left, data);
    } else if (data > root->data) {
      root->right = addNode(root->right, data);
    } else {
      root->count++;
    }
    return root;
  }

  void delTree(Node* root) {
    if (root == nullptr) return;
    delTree(root->right);
    delTree(root->left);
    delete root;
  }

  int depthI(Node* root) const {
    if (root == nullptr) return 0;
    int leftDepth = depthI(root->left);
    int rightDepth = depthI(root->right);
    return 1 + (leftDepth > rightDepth ? leftDepth : rightDepth);
  }

  int searchI(Node* root, const T& data) const {
    if (root == nullptr) return 0;
    if (data == root->data) return root->count;
    if (data < root->data) return searchI(root->left, data);
    return searchI(root->right, data);
  }

  void collectNodes(Node* root, std::vector<std::pair<T, int>>& nodes) const {
    if (root == nullptr) return;
    collectNodes(root->left, nodes);
    nodes.push_back({ root->data, root->count });
    collectNodes(root->right, nodes);
  }

  public:
  BST() : root(nullptr) {}
  ~BST() { delTree(root); }

  void insert(const T& data) { root = addNode(root, data); }

  int depth() const { return depthI(root); }

  int search(const T& data) const { return searchI(root, data); }

  std::vector<std::pair<T, int>> getWords() const {
    std::vector<std::pair<T, int>> nodes;
    collectNodes(root, nodes);
    return nodes;
  }
};
#endif  // INCLUDE_BST_H_
