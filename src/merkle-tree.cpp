#include "merkle-tree.hpp"
#include <string>

Node *Node ::getLeft() { return left; }
Node *Node ::getRight() { return right; }
std::string Node::getHash() { return hashString; }

void Node::setHash(std::string value) { hashString = value; }
void Node::setLeft(Node *n) { left = n; }
void Node::setRight(Node *n) { right = n; }

MerkleTree::MerkleTree(std::vector<Node *> data)
{
    std::vector<Node *> node_blocks;
    while (data.size() != 1)
    {
        for (int i = 0, j = 0; i < data.size(); i = i + 2, j++)
        {
            if (i != data.size() - 1)
            {
                data.push_back(new Node(picosha2::hash256_hex_string(data[i]->getHash() + data[i + 1]->getHash())));
                node_blocks[j]->setLeft(data[i]);
                node_blocks[j]->setRight(data[i + 1]);
            }
            else
            {
                node_blocks.push_back(data[i]);
            }
        }
        data = node_blocks;
        node_blocks.clear();
    }
    this->root = data[0];
}
void MerkleTree::printTree(Node *n, int i)
{
}

MerkleTree::~MerkleTree()
{
}
