// intlist.cpp
// Implements class IntList
// YOUR NAME(S), AND DATE

#include "intlist.h"

#include <iostream>
using std::cout;

// copy constructor
IntList::IntList(const IntList& source) {
    head = nullptr;
    Node* curr = source.head;
    while (curr != nullptr) {
        push_back(curr->info);  
        curr = curr->next;
    }
}

// destructor deletes all nodes
IntList::~IntList() {
    Node* curr = head;
    while (curr != nullptr) {
        Node* temp = curr;
        curr = curr->next;
        delete temp;
    }
    head = nullptr;
}


// return sum of values in list
int IntList::sum() const {
    int total = 0;
    Node* curr = head;
    while (curr != nullptr) {
        total += curr->info;
        curr = curr->next;
    }
    return total;
}

// returns true if value is in the list; false if not
bool IntList::contains(int value) const {
    Node* curr = head;
    while (curr != nullptr) {
        if (curr->info == value) {
            return true;
        }
        curr = curr->next;
    }
    return false;
}

// returns maximum value in list, or 0 if empty list
int IntList::max() const {
    Node* curr = head;
    int max = 0;
    while (curr != nullptr) {
        if (curr->info > max) {
            max = curr->info;
        }
        curr = curr->next;
    }
    return max;
}

// returns average (arithmetic mean) of all values, or
// 0 if list is empty
double IntList::average() const {
    if (head == nullptr) return 0.0;
    return static_cast<double>(sum()) / count();
}

// inserts value as new node at beginning of list
void IntList::push_front(int value) {
    Node* newNode = new Node;
    newNode->info = value;
    newNode->next = head;
    head = newNode;
}

// append value at end of list
void IntList::push_back(int value) {
    Node* newNode = new Node;
    newNode->info = value;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* curr = head;
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = newNode;
    }
 
}

// return count of values
int IntList::count() const {
    int cnt = 0;
    Node* curr = head;
    while (curr != nullptr) {
        cnt++;
        curr = curr->next;
    }
    return cnt;
}


//Assignment operator should copy the list from the source
//to this list, deleting/replacing any existing nodes
IntList& IntList::operator=(const IntList& source){
    if (this == &source) return *this;

    Node* curr = head;
    while (curr != nullptr) {
        Node* temp = curr;
        curr = curr->next;
        delete temp;
    }
    head = nullptr;

    curr = source.head;
    while (curr != nullptr) {
        push_back(curr->info);
        curr = curr->next;
    }

    return *this;
}

// constructor sets up empty list
IntList::IntList(){ 
    head = nullptr; 
}


// DO NOT CHANGE ANYTHING BELOW (READ IT THOUGH)

// print values enclose in [], separated by spaces
void IntList::print() const {
    Node *n = head;
    cout << '[';
    while (n) {
        cout << n->info;
        if (n->next)
            cout << " ";
        n = n->next;
    }
    cout << ']';
}

