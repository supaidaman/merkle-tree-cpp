#pragma once

#include <map>
#include <vector>
#include <string>

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
class PatriciaTrie
{
private:
    PatriciaNode *root;
    void addRecursive(std::string wordPart, PatriciaNode *currentNode);
    void deleteRecursive(std::string wordPart, PatriciaNode *currentNode);
    std::string findPredecessorRecursive(std::string string, PatriciaNode *currentNode, std::string carry);
    void printTree(PatriciaNode *node);

public:
    void addElement(std::string element); // transaction

    PatriciaTrie();
    PatriciaTrie(std::string element);
    ~PatriciaTrie();
    void deleteElement(std::string label);
    std::string findPredecessor(std::string string);
    void printFullTree();
    // bool bit();
    // bool search(int i);
    // Node *search(Node *node);
};