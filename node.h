//
// Created by kamil on 13.11.2024.
//

#ifndef ALGORYTMY_LAB3_NODE_H
#define ALGORYTMY_LAB3_NODE_H

template <typename T>
class Node{
    T data;
    Node* parent;
    Node* left_child;
    Node* right_child;
};

#endif //ALGORYTMY_LAB3_NODE_H
