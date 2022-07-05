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

    void printTree(PatriciaNode *node);
    void printPath(std::vector<std::string> vec);
    void printAllPaths(PatriciaNode *root, std::vector<std::string> vec);

public:
    void addElement(std::string element);

    PatriciaTrie();
    PatriciaTrie(std::string element);
    ~PatriciaTrie();
    void deleteElement(std::string element);

    void printFullTree();
    void printFullTree(PatriciaNode *root);
    PatriciaNode *getRoot() { return root; };
};