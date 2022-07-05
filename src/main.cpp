#include "merkle-tree.hpp"
#include "patricia-trie.hpp"
#include "sha.hpp"
#include <iostream>

using namespace std;

int main()
{
    cout << "ARVORE DE MERKLE " << endl;
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
    // cout << hashTree->getRoot()->getHash() << endl;
    hashTree->printFullTree(hashTree->getRoot());

    cout << "------------------- " << endl;
    cout << "PATRICIA TRIE " << endl;
    PatriciaTrie *pTree = new PatriciaTrie("");
    pTree->addElement("maca");
    pTree->addElement("macaco");
    pTree->addElement("basta");
    pTree->addElement("bastão");
    pTree->addElement("maça");
    pTree->addElement("mato");
    pTree->printFullTree();
    cout << "predecessor " << pTree->findPredecessor("macaco") << endl;

    for (unsigned int k = 0; k < leaves.size(); k++)
    {
        delete leaves[k];
    }

    delete hashTree;

    delete pTree;
    return 0;
}