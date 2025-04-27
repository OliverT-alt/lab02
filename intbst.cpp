// intbst.cpp
// Implements class IntBST
// Oliver Tian, 2025.4.25

#include "intbst.h"

#include <iostream>
using std::cout;

// constructor sets up empty tree
IntBST::IntBST() { 
    root = nullptr;

}

// destructor deletes all nodes
IntBST::~IntBST() {
    clear(root);
    root = nullptr; 
}

// recursive helper for destructor
void IntBST::clear(Node *n) {
    if (n != nullptr) {
        clear(n->left);
        clear(n->right);
        delete n;
    }

}

// insert value in tree; return false if duplicate
bool IntBST::insert(int value) {
    if (root == nullptr) {
        root = new Node(value);
        return true;
    } else {
        return insert(value, root);
    }
}

// recursive helper for insert (assumes n is never 0)
bool IntBST::insert(int value, Node *n) {
    if (value == n->info) {
        return false; 
    } else if (value < n->info) {
        if (n->left == nullptr) {
            n->left = new Node(value);
            n->left->parent = n;
            return true;
        } else {
            return insert(value, n->left);
        }
    } else { // value > n->info
        if (n->right == nullptr) {
            n->right = new Node(value);
            n->right->parent = n;
            return true;
        } else {
            return insert(value, n->right);
        }
    }
}

// print tree data pre-order
void IntBST::printPreOrder() const {
    printPreOrder(root);
    cout << endl;
}

// recursive helper for printPreOrder()
void IntBST::printPreOrder(Node *n) const {
    if (n != nullptr) {
        cout << n->info;
        if (n->left != nullptr || n->right != nullptr) cout << " "; 
        printPreOrder(n->left);
        if (n->left != nullptr && n->right != nullptr) cout << " ";
        printPreOrder(n->right);
    }
}

// print tree data in-order, with helper
void IntBST::printInOrder() const { 
    printInOrder(root);
}

void IntBST::printInOrder(Node *n) const { 
    if (n != nullptr) {
        printInOrder(n->left);
        cout << n->info;
        if (n->left != nullptr || n->right != nullptr) cout << " "; 
        printInOrder(n->right);
    }
}

// prints tree data post-order, with helper
void IntBST::printPostOrder() const { 
    printPostOrder(root);
}

void IntBST::printPostOrder(Node *n) const { 
    if (n != nullptr) {
        printPostOrder(n->left);
        printPostOrder(n->right);
        cout << n->info;
        if (n->left != nullptr || n->right != nullptr) cout << " "; 
    }
}

// return sum of values in tree
int IntBST::sum() const {
    return sum(root);
}

// recursive helper for sum
int IntBST::sum(Node *n) const {
    if (n == nullptr) {
        return 0;
    }
    return n->info + sum(n->left) + sum(n->right);
}

// return count of values
int IntBST::count() const {
    return count(root);
}

// recursive helper for count
int IntBST::count(Node *n) const {
    if (n == nullptr) {
        return 0;
    }
    return 1 + count(n->left) + count(n->right);
}

// IMPLEMENT THIS FIRST: returns the node for a given value or NULL if none exists
// Parameters:
// int value: the value to be found
// Node* n: the node to start with (for a recursive call)
// Whenever you call this method from somewhere else, pass it
// the root node as "n"
IntBST::Node* IntBST::getNodeFor(int value, Node* n) const{
    if (n == nullptr) {
        return nullptr;
    }
    if (value == n->info) {
        return n;
    } else if (value < n->info) {
        return getNodeFor(value, n->left);
    } else {
        return getNodeFor(value, n->right);
    }
}

// returns true if value is in the tree; false if not
bool IntBST::contains(int value) const {
    return getNodeFor(value, root) != nullptr;
}

// returns the Node containing the predecessor of the given value
IntBST::Node* IntBST::getPredecessorNode(int value) const{
    Node* current = getNodeFor(value, root);
    if (current == nullptr) return nullptr;

    if (current->left != nullptr) {
        Node* pred = current->left;
        while (pred->right != nullptr) {
            pred = pred->right;
        }
        return pred;
    }

    //no left subtree
    Node* ancestor = current->parent;
    while (ancestor != nullptr && current == ancestor->left) {
        current = ancestor;
        ancestor = ancestor->parent;
    }
    return ancestor;
}

// returns the predecessor value of the given value or 0 if there is none
int IntBST::getPredecessor(int value) const{
    Node* predNode = getPredecessorNode(value);
    return predNode ? predNode->info : 0;
}

// returns the Node containing the successor of the given value
IntBST::Node* IntBST::getSuccessorNode(int value) const{
     Node* current = getNodeFor(value, root);
    if (current == nullptr) return nullptr;

    if (current->right != nullptr) {
        Node* succ = current->right;
        while (succ->left != nullptr) {
            succ = succ->left;
        }
        return succ;
    }

    // no right subtree
    Node* ancestor = current->parent;
    while (ancestor != nullptr && current == ancestor->right) {
        current = ancestor;
        ancestor = ancestor->parent;
    }
    return ancestor;
}

// returns the successor value of the given value or 0 if there is none
int IntBST::getSuccessor(int value) const{
    Node* succNode = getSuccessorNode(value);
    if (succNode != nullptr) {
        return succNode->info;
    } else {
        return 0;
    }
}

// deletes the Node containing the given value from the tree
// returns true if the node exist and was deleted or false if the node does not exist
bool IntBST::remove(int value){ 
    Node* nodeToRemove = getNodeFor(value, root);
    if (nodeToRemove == nullptr) {
        return false;
    }

    if (nodeToRemove->left == nullptr && nodeToRemove->right == nullptr) {
        if (nodeToRemove == root) {
            delete root;
            root = nullptr;
        } else {
            Node* parent = nodeToRemove->parent;
            if (parent->left == nodeToRemove) {
                parent->left = nullptr;
            } else {
                parent->right = nullptr;
            }
            delete nodeToRemove;
        }
    }
    // one child
    else if (nodeToRemove->left == nullptr || nodeToRemove->right == nullptr) {
        Node* child = (nodeToRemove->left != nullptr) ? nodeToRemove->left : nodeToRemove->right;
        if (nodeToRemove == root) {
            root = child;
            root->parent = nullptr;
        } else {
            Node* parent = nodeToRemove->parent;
            if (parent->left == nodeToRemove) {
                parent->left = child;
            } else {
                parent->right = child;
            }
            child->parent = parent;
        }
        delete nodeToRemove;
    }
    // two children
    else {
        Node* successor = getSuccessorNode(nodeToRemove->info);
        nodeToRemove->info = successor->info;
        if (nodeToRemove->right == successor) {
            nodeToRemove->right = successor->right;
            if (successor->right != nullptr) {
                successor->right->parent = nodeToRemove;
            }
        } else {
            if (successor->parent->left == successor) {
                successor->parent->left = successor->right;
            } else {
                successor->parent->right = successor->right;
            }
            if (successor->right != nullptr) {
                successor->right->parent = successor->parent;
            }
        }
        delete successor;
    }
    return true;
}
