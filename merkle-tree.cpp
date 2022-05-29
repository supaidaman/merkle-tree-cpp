#include "merkle-tree.hpp"
//

// int main()
// {
//     std::cout << "Hello World" << std::endl;
// }

node ::node(int key, int value)
{
    this->key = key;
    this->value = value;
    this->left = nullptr;
    this->right = nullptr;
}

node ::~node()
{
    // delete this->right;
    // delete this->left;
}