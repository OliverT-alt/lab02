#include <iostream>
#include "intbst.h"

using namespace std;

int main() {
    IntBST tree;

    // insert
    cout << "Inserting values: 64, 8, 4, 32, 16, 128, 512, 256" << endl;
    tree.insert(64);
    tree.insert(8);
    tree.insert(4);
    tree.insert(32);
    tree.insert(16);
    tree.insert(128);
    tree.insert(512);
    tree.insert(256);

    // traversals
    cout << "Pre-order traversal: ";
    tree.printPreOrder();

    cout << "In-order traversal: ";
    tree.printInOrder();

    cout << "Post-order traversal: ";
    tree.printPostOrder();

    // sum and count
    cout << "Sum of all values: " << tree.sum() << endl;
    cout << "Count of all nodes: " << tree.count() << endl;

    // contains
    cout << "Contains 64? " << (tree.contains(64) ? "Yes" : "No") << endl;
    cout << "Contains 17? " << (tree.contains(17) ? "Yes" : "No") << endl;

    // predecessor and successor
    cout << "Predecessor of 64: " << tree.getPredecessor(64) << endl;
    cout << "Successor of 64: " << tree.getSuccessor(64) << endl;

    // remove
    cout << "Removing 4..." << endl;
    tree.remove(4);
    cout << "In-order traversal after removing 4: ";
    tree.printInOrder();

    cout << "Removing 64..." << endl;
    tree.remove(64);
    cout << "In-order traversal after removing 64: ";
    tree.printInOrder();

    return 0;
}
