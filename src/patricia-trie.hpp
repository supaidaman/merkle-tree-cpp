#pragma once

#include <map>
#include <vector>
class PatriciaNode
{
public:
    std::string stringData;
    std::vector<PatriciaNode *> *childList;
    PatriciaNode()
    {
        stringData = "";
        childList = new std::vector<PatriciaNode *>();
    }

    PatriciaNode(std::string l)
    {
        stringData = l;
        childList = new std::vector<PatriciaNode *>();
    }
};
class PatriciaTree
{
private:
    PatriciaNode *root;
    void addRecursive(string wordPart, PatriciaNode *currentNode);
    // std::map<char, Node *> rootMap;

public:
    void addElement(std::string element); // transaction
    PatriciaNode *getElement();
    PatriciaNode *removeElement(); //
    PatriciaTree();
    PatriciaTree(std::string hash, std::string data);
    ~PatriciaTree();
    // bool bit();
    // bool search(int i);
    // Node *search(Node *node);
};