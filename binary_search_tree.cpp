#include <iostream>
#include "BinarySearchTree.h"

using std::endl;
using std::cout;
using std::cin;

int main(){

    tree::BinarySearchTree<int> mytree;

    mytree.insert(10);
    mytree.insert(5);
    mytree.insert(15);
    mytree.insert(4);
    mytree.insert(7);

    cout << "Tree Height: " << mytree.height() << endl;

    mytree.traversePreOrder();
    mytree.traverseInOrder();
    mytree.traversePostOrder();
    mytree.bfsTraversal();

    mytree.deleteNode(5);

    mytree.traversePreOrder();
    mytree.traverseInOrder();
    mytree.traversePostOrder();
    mytree.bfsTraversal();

    return 0;
}