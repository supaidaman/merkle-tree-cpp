#pragma once

#include <string>
#include <vector>

using namespace std;
class Trie
{
private:
    unsigned char rootNode;
    string hashRoot;
    static vector<unsigned char> emptyByteArray;
    static vector<unsigned char> emptyElementRlp;
    static vector<unsigned char> emptyTrieHash;
    Trie()
    {
        hashRoot = "";
        emptyByteArray.push_back(0);
        // emptyElementRlp.push_back(RLP.enconde())
    }

public:
    void setRoot(string hash)
    {
        hashRoot = hashRoot;
    }
    // vector<unsigned char> getRootHash();
    // void setRootHash(vector<unsigned char> root);

    // virtual get(byte[] key) = 0;
    // auto rootNode;
};