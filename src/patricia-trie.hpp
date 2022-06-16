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
    ~PatriciaNode()
    {
        stringData = "";
        for (int i = 0; i < childList->size(); i++)
        {
            delete childList->at(i);
        }
        childList->clear();
        delete childList;
    }
};
class PatriciaTree
{
private:
    PatriciaNode *root;
    void addRecursive(std::string wordPart, PatriciaNode *currentNode);
    void deleteRecursive(std::string wordPart, PatriciaNode *currentNode);

public:
    void addElement(std::string element); // transaction

    PatriciaTree();
    PatriciaTree(std::string hash, std::string data);
    ~PatriciaTree();
    void deleteElement(std::string label);
    // bool bit();
    // bool search(int i);
    // Node *search(Node *node);
};