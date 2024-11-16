#include <iostream>
#include "bst.h"

struct someObject {
    int value1;
    char value2;
};

template <typename T>
unsigned int Node<T>::id = 0;

void Testing() {
    auto* bst = new Bst<someObject>();
    bst->AddNode(someObject{5,'a'});
    bst->AddNode(someObject{6,'b'});
    bst->AddNode(someObject{4,'c'});
    Node<someObject>* node_ptr = bst->FindTreeNode(bst->root, {6,'b'});
    bst->PrintList();
    delete bst;
}

int main() {
    Testing();
    return 0;
}
