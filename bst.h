//
// Created by kamil on 13.11.2024.
//

#ifndef ALGORYTMY_LAB3_BST_H
#define ALGORYTMY_LAB3_BST_H
#include "node.h"

template <typename T>
bool StandardOrder(T compared_obj, T inserted_obj) {
    int diff = compared_obj.value1 - inserted_obj.value1;
    if(diff < 0) {
        return true;
    }else if(diff==0) {
        diff = compared_obj.value2 - inserted_obj.value2;
        if(diff<0) {
            return true;
        }
    }
    return false;
}

template <typename T>
class Bst{
public:
    Node<T>* root;

    unsigned int size;

    Bst() {
        root = nullptr;
        size = 0;
    }

    ~Bst() {
        root = nullptr;
        size = 0;
    }
public:
    // void CompareNode(T compared_obj, T inserted_obj, )
// (a) dodanie nowe elementu do drzewa
    void AddNode(T inserted_data) {
        if(root!=nullptr) {
            Node<T>* current_node = this->root;
            Node<T>* current_node_parent = nullptr;
            while(current_node) {
                current_node_parent = current_node;
                if(StandardOrder(current_node->data,inserted_data)) {
                    current_node = current_node->right_child;
                }else {
                    current_node = current_node->left_child;
                }
            }
            if(StandardOrder(current_node_parent->data,inserted_data)) {
                auto* new_node=new Node<T>(current_node_parent,inserted_data);
                current_node_parent->right_child=new_node;
            }else {
                auto* new_node=new Node<T>(current_node_parent,inserted_data);
                current_node_parent->left_child=new_node;
            }
        }else {
            root = new Node<T>(inserted_data);
        }
        size++;
    }
    /*void AddNode(T inserted_data, bool (*comparator)(T,T)) {
        if(root!=nullptr) {
            Node<T>* current_node = root;
            while(current_node) {
                if(comparator(current_node->data,inserted_data)) {
                    current_node = current_node->right_child;
                }else {
                    current_node = current_node->left_child;
                }
            }
            current_node=new Node<T>(current_node->parent,inserted_data);
        }else {
            root = new Node<T>(inserted_data);
        }
        size++;
    }*/

    void PrintNode(Node<T>* node){
        if(node->left_child) {
            PrintNode(node->left_child);
        }
        if(node->right_child) {
            PrintNode(node->right_child);
        }
        std::cout<<node->data.value1<<" "<<node->data.value2<<" ";
    }

    void PrintList() {
        if(root) {
            PrintNode(root);
        }else {
            std::cout<<"Lista pusta"<<std::endl;
        }
    }

    void SearchTree(Node<T>* node, T data_pattern) {
        if(StandardOrder(node->data,data_pattern)) {

        }
    }
// (b) wyszukanie elementu
// bez komparatora
    Node<T>* FindTreeNode(Node<T>* starting_point, T data_pattern) {
        Node<T>* current_node = starting_point;
        if(current_node==nullptr) {
            return nullptr;
        }
        if((current_node->data.value1 == data_pattern.value1) && (current_node->data.value2==data_pattern.value2)) {
            return current_node;
        }
        if(StandardOrder(current_node->data,data_pattern)) {
            FindTreeNode(current_node->right_child,data_pattern);
        }else {
            FindTreeNode(current_node->left_child,data_pattern);
        }
        //return nullptr;

    }
// (c) usuwanie znalezionego wcześniej węzła drzewa
    void DeleteNode(Node<T>* node_to_delete) {
        Node<T>* replacement_node = nullptr;
        if(node_to_delete->right_child) {
            replacement_node=node_to_delete->right_child;
            replacement_node->parent = node_to_delete->parent;

        }
    }
// (d) przejście preorder drzewa
// (e) przejście inorder drzewa
// (f) czyszczenie drzewa
// (h) zwrócenie napisowej reprezentacji drzewa


};

#endif //ALGORYTMY_LAB3_BST_H
