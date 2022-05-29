// struct node
// {
//     int key;
//     int value;
//     struct node *left;
//     struct node *right;
// };
#include <memory>

class node
{
private:
    int key;
    int value;
    node *left;
    node *right;

public:
    node(int key, int value);
    ~node();
    int get_key();
    int get_value();
    node *get_left();
    node *get_right();

    void set_key(int value);
    void set_value(int value);

    node *find(node *tree, int key);
    void insert_node(node *tree, node *item);
    void delete_element(int key);
    // property int key
    // {
    //     int get() { return key; }
    //     void set(int value)
    //     {
    //         key = value;
    //     }
    // }
};

class tree
{
private:
    node *root;

public:
    tree(int value, int key);
    void add(int key, int value);
    node *remove(node *tree, int key);
    ~tree();
};