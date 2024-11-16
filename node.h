//
// Created by kamil on 13.11.2024.
//

#ifndef ALGORYTMY_LAB3_NODE_H
#define ALGORYTMY_LAB3_NODE_H

template <typename T>
class Node{
public:
    static unsigned int id;
    Node* parent;
    Node* left_child;
    Node* right_child;
    T data;
    unsigned int node_id;

    Node () {
        this->parent = nullptr;
        this->left_child = nullptr;
        this->right_child = nullptr;
        data = T();//?
        //id = 0;
        node_id = id;
        id +=1;
    }
    explicit Node(T inserted_data) {
        this->parent = nullptr;
        this->left_child = nullptr;
        this->right_child = nullptr;
        data = inserted_data;
        node_id = id;
        id +=1;
    }

    Node(Node<T>* parent_node ,T inserted_data) {
        this->parent = parent_node;
        this->left_child = nullptr;
        this->right_child = nullptr;
        data = inserted_data;
        node_id = id;
        id +=1;
    }

    ~Node() {
        this->parent = nullptr;
        this->left_child= nullptr;
        this->right_child=nullptr;
    }


};

#endif //ALGORYTMY_LAB3_NODE_H
