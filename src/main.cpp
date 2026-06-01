// Copyright 2021 NNTU-CS
#include "bst.h"
#include <iostream>
#include <string>

void makeTree(BST<std::string>& tree, const char* filename);
void printFreq(BST<std::string>& tree);

int main() {
  BST<std::string> wordTree;
  const char* filename = "war_peace.txt";
  std::cout << "Loading file: " << filename << std::endl;
  makeTree(wordTree, filename);
  printFreq(wordTree);
  std::cout << "\nExample:" << std::endl;
  std::string testWords[] = { "war", "peace", "and", "the", "a", "hello" };
  for (const auto& word : testWords) {
    int count = wordTree.search(word);
    if (count > 0) {
      std::cout << "Word '" << word << "' found " << count << " times" << std::endl;
    }
    else {
      std::cout << "Word '" << word << "' NOT found" << std::endl;
    }
  }
  return 0;
}
