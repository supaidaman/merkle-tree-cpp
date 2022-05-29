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
    std::unique_ptr<node> left;
    std::unique_ptr<node> right;

public:
    node(int key, int value);
    ~node();
    int get_key();
    int get_value();
    void set_key(int value);
    void set_value();
    // property int key
    // {
    //     int get() { return key; }
    //     void set(int value)
    //     {
    //         key = value;
    //     }
    // }
};
