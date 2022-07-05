#include "merkle-tree.hpp"
#include <string>
#include <iomanip>
#include "sha.hpp"

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
                node_blocks.push_back(new Node(hash_sha256(data[i]->getHash() + data[i + 1]->getHash())));
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
// void MerkleTree::printTree(Node *n, int i)
// {
//     if (n)
//     {
//         if (n->getLeft())
//         {
//             printTree(n->getLeft(), i + 4);
//         }
//         if (n->getRight())
//         {
//             printTree(n->getRight(), i + 4);
//         }
//         if (i)
//         {
//             std::cout << std::setw(i) << ' ';
//         }
//         std::cout << n->getHash() << "\n ";
//     }
// }

void MerkleTree::printTree(std::string prefix, Node *node, bool isLeft)
{
    if (node != nullptr)
    {
        std::cout << prefix;

        std::cout << (isLeft ? "├──" : "└──");

        // print the value of the node
        std::cout << node->getHash() << std::endl;

        // enter the next tree level - left and right branch
        printTree(prefix + (isLeft ? "│   " : "    "), node->getLeft(), true);
        printTree(prefix + (isLeft ? "│   " : "    "), node->getRight(), false);
    }
}

void MerkleTree::printFullTree(Node *node)
{
    printTree("", node, false);
}

MerkleTree::~MerkleTree()
{
}
