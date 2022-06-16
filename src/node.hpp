#pragma once
#include <string>
class Node
{
private:
    std::string hashString;
    std::string data;
    Node *left;
    Node *right;
    int bitLength;

public:
    Node(std::string hashString);
    Node(std::string hashString, std::string data);
    ~Node();

    Node *getLeft();
    Node *getRight();
    std::string getHash();

    void setLeft(Node *n);
    void setRight(Node *n);
    void setHash(std::string value);

    void setData(std::string value);
    std::string getData();

    void setBitLength(int value);
    int getBitLength();
};
