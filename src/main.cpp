#include "merkle-tree.hpp"
#include "patricia-trie.hpp"
#include "sha.hpp"
#include <iostream>

int main()
{
    // MerkleTree *t = new MerkleTree();
    // delete t;
    // PatriciaTree *pTree = new PatriciaTree();
    // pTree->addElement("romane");

    std::vector<Node *> leaves;
    // create sample data
    leaves.push_back(new Node(hash_sha256("abcdefg")));
    leaves.push_back(new Node(hash_sha256("qwerty12345")));
    leaves.push_back(new Node(hash_sha256("!@(@#)E&")));
    leaves.push_back(new Node(hash_sha256("ajosdhuhsdioa adsijd asjiod q9p0ad a.")));
    leaves.push_back(new Node(hash_sha256("test01234")));
    leaves.push_back(new Node(hash_sha256("7846546521")));
    leaves.push_back(new Node(hash_sha256("asd970123+_?>?< f")));
    leaves.push_back(new Node(hash_sha256("op_) 4654asd21")));
    leaves.push_back(new Node(hash_sha256("12893 d970123+_qweawdf")));
    // initialize leaves
    for (unsigned int i = 0; i < leaves.size(); i++)
    {
        leaves[i]->setLeft(nullptr);
        leaves[i]->setRight(nullptr);
    }

    MerkleTree *hashTree = new MerkleTree(leaves);
    std::cout << hashTree->getRoot()->getHash() << std::endl;
    hashTree->printTree(hashTree->getRoot(), 0);

    for (unsigned int k = 0; k < leaves.size(); k++)
    {
        delete leaves[k];
    }

    delete hashTree;
    std::cout << "Hello World" << std::endl;

    return 0;
}