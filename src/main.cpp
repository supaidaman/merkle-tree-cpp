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
    leaves.push_back(new Node(hash_sha256("qwqwqwqdsdfg")));
    leaves.push_back(new Node(hash_sha256("Lorem ipsum dolor sit amet")));
    leaves.push_back(new Node(hash_sha256("Maecenas vitae magna blandit, sagittis tortor quis")));
    leaves.push_back(new Node(hash_sha256("test01234")));
    leaves.push_back(new Node(hash_sha256("5465465489756456")));
    leaves.push_back(new Node(hash_sha256("hitohitohinogotokisamakirara")));
    leaves.push_back(new Node(hash_sha256("mais uma string para testar")));
    leaves.push_back(new Node(hash_sha256("Nam vel elit ligula. Aliquam lacus magna")));
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
    cout << "Nós existentes na trie: " << endl;
    pTree->printFullTree();
    cout << "Caminhos existentes na trie: " << endl;
    pTree->printFullTree(pTree->getRoot());

    for (unsigned int k = 0; k < leaves.size(); k++)
    {
        delete leaves[k];
    }

    delete hashTree;

    delete pTree;
    return 0;
}