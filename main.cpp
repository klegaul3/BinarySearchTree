
#include <iostream>
using std::cout;
using std::endl;

#include "BST.h"

int main() {

    BST<int> tree;

    tree.insert(1);
    tree.insert(2);
    tree.insert(5);
    tree.insert(4);

    tree.inorderTraversal();

    return 0;
}