
#pragma once

// struct node
// {
//     int key;
//     int value;
//     struct node *left;
//     struct node *right;
// };
#include <memory>
#include <string>
#include <vector>
class node
{
private:
    std::string hash_string;
    node *left;
    node *right;

public:
    node(std::string hash_string);
    ~node();
    int get_key();
    int get_value();
    node *get_left();
    node *get_right();

    void set_hash(int value);

    // node *find(node *tree, int key);
    // void insert_node(node *tree, node *item);
    // void delete_element(int key);
    // property int key
    // {
    //     int get() { return key; }
    //     void set(int value)
    //     {
    //         key = value;
    //     }
    // }
};

class merkle_tree
{
private:
    node *root;

public:
    merkle_tree(std::vector<node *> data);
    // void add(int key, int value);
    node *remove(node *tree, int key);
    ~merkle_tree();
    void print_tree(node *n, int i);
};