
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

    ~MerkleTree();

    void printTree(std::string prefix, Node *node, bool isLeft);
    void printFullTree(Node *node);
};