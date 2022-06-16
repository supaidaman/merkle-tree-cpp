#include "patricia-trie.hpp"

#include <iostream>
#include <string>
//#include <vector>
using namespace std;

void PatriciaTree::addElement(string element)
{
    cout << "a" << endl;
    addRecursive(element, root);
}

int matchingConsecutiveChars(string word, PatriciaNode *currentNode)
{
    // todo fix:
    int matches = 0;
    int minlength = 0;
    cout << currentNode->stringData << endl;
    if (currentNode->stringData.length() >= word.length())
        minlength = word.length();
    else if (currentNode->stringData.length() < word.length())
        minlength = currentNode->stringData.length();

    cout << "v" << endl;
    if (minlength > 0)

        for (int i = 0; i < minlength; i++)
        {

            if (word[i] == currentNode->stringData[i])
                matches++;
            else

                break;
        }

    return matches;
}

void PatriciaTree::addRecursive(string wordPart, PatriciaNode *currentNode)
{
    auto matches = matchingConsecutiveChars(wordPart, currentNode);

    if ((matches == 0) || (currentNode == root) ||
        ((matches > 0) && (matches < wordPart.length()) && (matches >= currentNode->stringData.length())))
    {

        bool inserted = false;
        auto newWordPart = wordPart.substr(matches, wordPart.length() - matches);

        for (int i = 0; i < currentNode->childList->size(); i++)
        {
            // auto stringFromChar = string(1, newWordPart[0]);
            PatriciaNode *child = currentNode->childList->at(i);

            if (child->stringData.rfind(newWordPart, 0) == 0)
            {
                inserted = true;
                addRecursive(newWordPart, child);
            }
        }

        if (inserted == false)
        {
            currentNode->childList->push_back(new PatriciaNode(newWordPart));
        }
    }
    else if (matches < wordPart.length())
    {

        string commonRoot = wordPart.substr(0, matches);
        string branchPreviousstringData = currentNode->stringData.substr(matches, currentNode->stringData.length() - matches);
        string branchNewstringData = wordPart.substr(matches, wordPart.length() - matches);

        currentNode->stringData = commonRoot;

        auto newNodePreviousstringData = new PatriciaNode(branchPreviousstringData);
        newNodePreviousstringData->childList->insert(newNodePreviousstringData->childList->end(),
                                                     currentNode->childList->begin(), currentNode->childList->end());

        currentNode->childList->clear(); // TODO DELETE ?
        currentNode->childList->push_back(newNodePreviousstringData);

        auto newNodeNewstringData = new PatriciaNode(branchNewstringData);
        currentNode->childList->push_back(newNodeNewstringData);
    }
    else if (matches == currentNode->stringData.length())
    {
    }
    else if (matches > currentNode->stringData.length())
    {

        string newNodestringData = currentNode->stringData.substr(currentNode->stringData.length(), wordPart.length());
        auto newNode = new PatriciaNode(newNodestringData);
        currentNode->childList->push_back(newNode);
    }
}

void PatriciaTree::deleteElement(string label)
{
    this->deleteRecursive(label, root);
}

void PatriciaTree::deleteRecursive(string wordPart, PatriciaNode *currentNode)
{
    auto matches = matchingConsecutiveChars(wordPart, currentNode);

    if ((matches == 0) || (currentNode == root) ||
        ((matches > 0) && (matches < wordPart.length()) && (matches >= currentNode->stringData.length())))
    {

        auto newStringData = wordPart.substr(matches, wordPart.length() - matches);
        for (int i = 0; i < currentNode->childList->size(); i++)
        {
            PatriciaNode *child = currentNode->childList->at(i);

            if (child->stringData.rfind(newStringData, 0) == 0)
            {
                if (newStringData == child->stringData)
                {
                    if (child->childList->size() == 0)
                    {
                        auto it = currentNode->childList->begin();
                        it += i;
                        currentNode->childList->erase(it); // todo check
                        return;
                    }
                }
                deleteRecursive(newStringData, child);
            }
        }
    }
}

PatriciaTree::PatriciaTree()
{
    root = new PatriciaNode();
}
PatriciaTree::PatriciaTree(string hash, string stringData)
{
    root = new PatriciaNode(stringData);
}
PatriciaTree::~PatriciaTree()
{
    delete root;
}