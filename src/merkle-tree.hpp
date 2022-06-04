
#pragma once

#include <memory>
#include <string>
#include <vector>
#include "picosha2.hpp"
#include "node.hpp"

class MerkleTree
{
private:
    Node *root;

public:
    MerkleTree(std::vector<Node *> data);
    // void add(int key, int value);
    ~MerkleTree();
    void printTree(Node *n, int i);
    bool verify(Node *data); // verify
};