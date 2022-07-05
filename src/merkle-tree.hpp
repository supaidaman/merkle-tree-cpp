
#pragma once

#include <memory>
#include <string>
#include <vector>
#include "node.hpp"

class MerkleTree
{
private:
    Node *root;

public:
    MerkleTree(std::vector<Node *> data);
    Node *getRoot() { return root; }
    // void add(int key, int value);
    ~MerkleTree();
    // void printTree(Node *n, int i);
    void printTree(std::string prefix, Node *node, bool isLeft);
    void printFullTree(Node *node);
    bool verify(Node *data); // verify
};