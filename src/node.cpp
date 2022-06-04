#include "node.hpp"
#include <string>

Node ::Node(std::string hash_string)
{
    this->hashString = hash_string;
    left = nullptr;
    right = nullptr;
}

Node ::~Node()
{
    delete left;
    delete right;
}