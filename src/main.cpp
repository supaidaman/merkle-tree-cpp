#include "merkle-tree.hpp"
#include <iostream>
int main()
{
    tree *t = new tree(1, 2);
    delete t;
    std::cout << "Hello World" << std::endl;

    return 0;
}