#include "patricia-trie.hpp"

#include <iostream>
#include <string>
//#include <vector>
using namespace std;

void PatriciaTrie::addElement(string element)
{
    addRecursive(element, root);
}

int matchingConsecutiveChars(string word, PatriciaNode *currentNode)
{
    // todo fix:
    int matches = 0;
    int minlength = 0;
    // cout << "match consecutive " << currentNode->stringData << endl;
    if (currentNode->stringData.length() >= word.length())
    {
        minlength = word.length();
    }
    else if (currentNode->stringData.length() < word.length())
    {
        minlength = currentNode->stringData.length();
    }
    // cout << "min consecutive " << minlength << endl;
    if (minlength > 0)
    {

        for (int i = 0; i < minlength; i++)
        {

            if (word[i] == currentNode->stringData[i])
                matches++;
            else

                break;
        }
    }

    return matches;
}

void PatriciaTrie::addRecursive(string wordPart, PatriciaNode *currentNode)
{
    // cout << "current word to add " << wordPart << endl;
    // cout << "current word in tree" << currentNode->stringData << endl;
    auto matches = matchingConsecutiveChars(wordPart, currentNode);

    if ((matches == 0) || (currentNode == root) ||
        ((matches > 0) && (matches < wordPart.length()) && (matches >= currentNode->stringData.length())))
    {

        bool inserted = false;
        auto newWordPart = wordPart.substr(matches, wordPart.length() - matches);
        // cout << currentNode->childList->size() << endl;
        for (int i = 0; i < currentNode->childList->size(); i++)
        {

            // auto stringFromChar = string(1, newWordPart[0]);
            PatriciaNode *child = currentNode->childList->at(i);

            if (child->stringData.rfind(newWordPart[0], 0) == 0)
            {

                // cout << newWordPart << endl;
                inserted = true;
                addRecursive(newWordPart, child);
            }
        }

        if (inserted == false)
        {
            // cout << "insert " << newWordPart << endl;
            currentNode->childList->push_back(new PatriciaNode(newWordPart));
        }
    }
    else if (matches < wordPart.length())
    {
        // cout << "match min " << matches << endl;
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

void PatriciaTrie::deleteElement(string label)
{
    this->deleteRecursive(label, root);
}

void PatriciaTrie::deleteRecursive(string wordPart, PatriciaNode *currentNode)
{
    auto matches = matchingConsecutiveChars(wordPart, currentNode);

    if ((matches == 0) || (currentNode == root) ||
        ((matches > 0) && (matches < wordPart.length()) && (matches >= currentNode->stringData.length())))
    {

        auto newStringData = wordPart.substr(matches, wordPart.length() - matches);
        for (int i = 0; i < currentNode->childList->size(); i++)
        {
            PatriciaNode *child = currentNode->childList->at(i);

            if (child->stringData.rfind(newStringData[0], 0) == 0)
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

PatriciaTrie::PatriciaTrie()
{

    root = new PatriciaNode();
}

PatriciaTrie::~PatriciaTrie()
{
    delete root;
}

PatriciaTrie::PatriciaTrie(string value)
{

    root = new PatriciaNode(value);
}

void PatriciaTrie::printTree(PatriciaNode *node)
{

    if (node != nullptr)
    {
        cout << node->stringData << endl;
        for (int i = 0; i < node->childList->size(); i++)
        {
            // cout << "contador print " << i << endl;
            PatriciaNode *child = node->childList->at(i);
            printTree(child);
        }
    }
}

void PatriciaTrie::printFullTree()
{
    printTree(root);
}

string PatriciaTrie::findPredecessorRecursive(std::string wordPart, PatriciaNode *currentNode, std::string carry)
{
    // //cout << wordPart << endl;
    // cout << currentNode->stringData << endl;

    auto matches = matchingConsecutiveChars(wordPart, currentNode);
    // cout << matches << endl;
    if ((matches == 0) || (currentNode == root) ||
        ((matches > 0) && (matches < wordPart.length()) && (matches >= currentNode->stringData.length())))
    {
        // cout << matches << endl;
        auto newStringData = wordPart.substr(matches, wordPart.length() - matches);
        for (int i = 0; i < currentNode->childList->size(); i++)
        {
            PatriciaNode *child = currentNode->childList->at(i);

            if (child->stringData.rfind(newStringData[0], 0) == 0)
            {
                return findPredecessorRecursive(newStringData, child, carry + currentNode->stringData);
            }
            return carry + currentNode->stringData;
        }
    }
    else if (matches == currentNode->stringData.length())
    {
        return carry + currentNode->stringData;
    }
    else
        return "";
}

string PatriciaTrie::findPredecessor(string value)
{
    string empty = "";
    return findPredecessorRecursive(value, root, empty);
}