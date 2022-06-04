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
    int minLength = 0;

    // see which string is smaller and save it's lenght
    // when cycling throught the two strings we won't go any further than that
    if (currentNode->stringData.length() >= word.length())
        minLength = word.length();
    else if (currentNode->stringData.length() < word.length())
        minLength = currentNode->stringData.length();

    if (minLength > 0)
        // go throught the two streams
        for (int i = 0; i < minLength; i++)
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
        // foreach (var child in curNode.childList)
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
        string commonRoot = wordPart.Substring(0, matches);
        string branchPreviousLabel = currentNode.stringData.Substring(matches, currentNode.stringData.length() - matches);
        string branchNewLabel = wordPart.Substring(matches, wordPart.length() - matches);

        currentNode.stringData = commonRoot;

        auto newNodePreviousLabel = new Node(branchPreviousLabel);
        newNodePreviousLabel.childList.AddRange(currentNode.childList);

        currentNode.childList.Clear();
        currentNode.childList.Add(newNodePreviousLabel);

        auto newNodeNewLabel = new Node(branchNewLabel);
        currentNode.childList.Add(newNodeNewLabel);
    }
    else if (matches == currentNode.stringData.length())
    {
        // in this case we don't do anything because the word is already added
    }
    else if (matches > currentNode.stringData.length())
    {
        // add the current word part minus the common characters after the current node
        string newNodeLabel = currentNode.stringData.Substring(currentNode.stringData.length(), wordPart.length());
        var newNode = new Node(newNodeLabel);
        currentNode.childList.Add(newNode);
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