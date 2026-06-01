// Copyright 2021 NNTU-CS
#include "bst.h"

#include <fstream>
#include <iostream>
#include <cctype>
#include <string>
#include <algorithm>
#include <vector>

void makeTree(BST<std::string>& tree, const char* filename) {
  std::ifstream file(filename);
  if (!file) {
    std::cout << "File error: Cannot open " << filename << std::endl;
    return;
  }
  std::string word;
  char ch;
  while (file.get(ch)) {
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
      word += tolower(ch);
    } else {
        if (!word.empty()) {
          tree.insert(word);
          word.clear();
          }
      }
  }
  if (!word.empty()) {
    tree.insert(word);
  }
  file.close();
}

void printFreq(BST<std::string>& tree) {
  auto words = tree.getWords();
  if (words.empty()) {
    std::cout << "Tree is empty!" << std::endl;
    return;
  }
  std::sort(words.begin(), words.end(),
    [](const auto& a, const auto& b) {
      return a.second > b.second;
    });
  std::ofstream outputFile("freq.txt");
  if (!outputFile) {
    std::cout << "Error: Cannot create result/freq.txt" << std::endl;
    return;
  }
  std::cout << "Frequency analysis results:" << std::endl;
  outputFile << "Frequency analysis results:" << std::endl;
  for (const auto& pair : words) {
    std::cout << pair.first << ": " << pair.second << std::endl;
    outputFile << pair.first << ": " << pair.second << std::endl;
  }
  outputFile.close();
}
