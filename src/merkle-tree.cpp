#include "merkle-tree.hpp"

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

node *node ::get_left() { return left; }
node *node ::get_right() { return right; }
std::string node::get_hash() { return hash_string; }

void node::set_hash(std::string value) { hash_string = value; }
void node::set_left(node *n) { left = n; }
void node::set_right(node *n) { right = n; }

merkle_tree::merkle_tree(std::vector<node *> data)
{
    std::vector<node *> node_blocks;
    while (data.size() != 1)
    {
        for (int i = 0, j = 0; i < data.size(); i = i + 2, j++)
        {
            if (i != data.size() - 1)
            {
                data.push_back(new node(picosha2::hash256_hex_string(data[i]->get_hash() + data[i + 1]->get_hash())));
                node_blocks[j]->set_left(data[i]);
                node_blocks[j]->set_right(data[i + 1]);
            }
            else
            {
                node_blocks.push_back(data[i]);
            }
        }
        data = node_blocks;
        node_blocks.clear();
    }
    this->root = data[0];
}
void merkle_tree::print_tree(node *n, int i)
{
}

merkle_tree::~merkle_tree()
{
}
