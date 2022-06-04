#include "patricia-trie.hpp"

#include <string>
//#include <vector>
using namespace std;

void PatriciaTree::addElement(string element)
{
    addRecursive(element, root);
}

int matchingConsecutiveChars(string word, PatriciaNode *currentNode)
{
    int matches = 0;
    int minlength = 0;

    // see which string is smaller and save it's lenght
    // when cycling throught the two strings we won't go any further than that
    if (currentNode->stringData.length() >= word.length())
        minlength = word.length();
    else if (currentNode->stringData.length() < word.length())
        minlength = currentNode->stringData.length();

    if (minlength > 0)
        // go throught the two streams
        for (int i = 0; i < minlength; i++)
        {
            // if two characters at the same position have the same value we have one more match
            if (word[i] == currentNode->stringData[i])
                matches++;
            else
                // if at any position the two strings have different characters break the cycle
                break;
        }
    // and return the current number of matches
    return matches;
}

void PatriciaTree::addRecursive(string wordPart, PatriciaNode *currentNode)
{
    auto matches = matchingConsecutiveChars(wordPart, currentNode);

    if ((matches == 0) || (currentNode == root) ||
        ((matches > 0) && (matches < wordPart.length()) && (matches >= currentNode->stringData.length())))
    {
        // remove the current node's label from the word part
        bool inserted = false;
        auto newWordPart = wordPart.substr(matches, wordPart.length() - matches);
        // search the node's subnodes and if the subnode label's first character matches
        // the word part's first character then insert the word part after this node(call the
        // current method recursively)
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
        // foreach (auto child in curNode.childList)
        //     if (child.stringData.StartsWith(newWordPart[0].ToString()))
        //     {
        //         inserted = true;
        //         InsertRec(newWordPart, child);
        //     }
        if (inserted == false)
        {
            currentNode->childList->push_back(new PatriciaNode(newWordPart));
        }
    }
    else if (matches < wordPart.length())
    {
        // in this case we have to nodes that we must add to the tree
        // one is the node that has a label extracted from the current node's label without the string of
        // matching characters(common characters)
        // the other is the node that has it's label extracted from the current word part minus the string
        // of matching characters
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
        // in this case we don't do anything because the word is already added
    }
    else if (matches > currentNode->stringData.length())
    {
        // add the current word part minus the common characters after the current node
        string newNodestringData = currentNode->stringData.substr(currentNode->stringData.length(), wordPart.length());
        auto newNode = new PatriciaNode(newNodestringData);
        currentNode->childList->push_back(newNode);
    }
}

/// <summary>
/// Delete: Delete a string from the tree. First, we delete the corresponding leaf.
/// Then, if its parent only has one child remaining, we delete the parent and merge the two incident edges.
/// </summary>
/// <param name="label"></param>
void PatriciaTree::deleteElement(string label)
{
    deleteRecursive(label, root);
}

/// <summary>
/// delete a word from the tree means delete the last leaf that makes up the stored word
/// </summary>
/// <param name="label"></param>
/// <param name="curNode"></param>
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
    root = nullptr;
}
PatriciaTree::PatriciaTree(string hash, string stringData)
{
    root = new PatriciaNode(stringData);
}
PatriciaTree::~PatriciaTree()
{
    delete root;
}