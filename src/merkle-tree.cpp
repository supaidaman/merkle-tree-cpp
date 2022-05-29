#include "merkle-tree.hpp"
//

// int main()
// {
//     std::cout << "Hello World" << std::endl;
// }

node ::node(std::string hash_string)
{
    this->hash_string = hash_string;
    left = nullptr;
    right = nullptr;
}

node ::~node()
{
    delete left;
    delete right;
}

// int node ::get_key() { return key; }
// int node ::get_value() { return value; }
node *node ::get_left() { return left; }
node *node ::get_right() { return right; }

// void node ::set_key(int value) { key = value; }
// void node ::set_value(int value) { this->value = value; }

// node *node ::find(node *tree, int key)
// {
//     if (tree == nullptr)
//     {
//         return nullptr;
//     }
//     if (tree->get_value() == key)
//     {
//         return tree;
//     }
//     else if (key < tree->get_key())
//     {
//         return find(tree->left, key);
//     }
//     else
//     {
//         return find(tree->right, key);
//     }
// }

// tree::tree(int key, int value)
// {
//     root = new node(key, value);
// }

// tree::~tree()
// {
//     delete root;
// }

merkle_tree::merkle_tree(std::vector<node *> data)
{
}
void merkle_tree::print_tree(node *n, int i)
{
}

merkle_tree::~merkle_tree()
{
}