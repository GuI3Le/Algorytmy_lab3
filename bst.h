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
// public:
    // void CompareNode(T compared_obj, T inserted_obj, )
// (a) dodanie nowe elementu do drzewa
    void AddNode(T inserted_data) {
        if(root!=nullptr) {
            Node<T>* current_node = this->root;
            Node<T>* current_node_parent = nullptr;
            while(current_node !=nullptr) {
                current_node_parent = current_node;
                if(StandardOrder(current_node->data,inserted_data)) {
                    current_node = current_node->right_child;
                }else {
                    current_node = current_node->left_child;
                }
            }
            if(current_node_parent->data.value1 != inserted_data.value1 && current_node_parent->data.value2 != inserted_data.value2) {
                if(StandardOrder(current_node_parent->data,inserted_data)) {
                    auto* new_node=new Node<T>(current_node_parent,inserted_data);
                    current_node_parent->right_child=new_node;
                }else {
                    auto* new_node=new Node<T>(current_node_parent,inserted_data);
                    current_node_parent->left_child=new_node;
                }
            }else {
                return;
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
        else if(StandardOrder(current_node->data,data_pattern)) {
            return FindTreeNode(current_node->right_child,data_pattern);
        }else {
            return FindTreeNode(current_node->left_child,data_pattern);
        }
        //return nullptr;

    }
    /*void MoveNodes(Node<T>* node_to_move,Node<T>* prev_l_child) {
        Node<T>* replacement_node = node_to_move->right_child;
        replacement_node=node_to_move->right_child;
        node_to_move->parent->right_child = replacement_node;
        replacement_node->parent = node_to_move->parent;
        Node<T>* replacement_node_prev_l_child = replacement_node->left_child;
        if(prev_l_child!=nullptr) {
            replacement_node->left_child = prev_l_child;
            replacement_node->left_child->parent = replacement_node;
        }
        if(replacement_node->right_child) {
            MoveNodes(replacement_node,replacement_node_prev_l_child);
        }

    }*/

    Node<T>* MaxNode(Node<T>* node) {
        if(node->right_child) {
            return  MaxNode(node->left_child);
        }
        if(node->left_child) {
            return MaxNode(node->right_child);
        }
            return node;
    }

// (c) usuwanie znalezionego wcześniej węzła drzewa
    /*void DeleteNode(Node<T>* node_to_delete) {
        if(node_to_delete) {
            if(node_to_delete->right_child) {
                Node<T>* replacement_node_prev_l_child = node_to_delete->right_child->left_child;
                MoveNodes(node_to_delete, replacement_node_prev_l_child);
                delete node_to_delete;

            }else if(node_to_delete->left_child) {
                node_to_delete->parent->left_child = node_to_delete->left_child;
                node_to_delete->left_child->parent = node_to_delete->parent;
            }else {
                if(node_to_delete == node_to_delete->parent->left_child) {
                    node_to_delete->parent->left_child = nullptr;
                }else {
                    node_to_delete->parent->right_child = nullptr;
                }
                delete node_to_delete;
            }
            size--;
        }
    }*/

    void DeleteNode(Node<T>* node_to_delete) {
        if(node_to_delete) {
            Node<T>* replacement_node = nullptr;
            if(node_to_delete->left_child) {
                replacement_node = MaxNode(node_to_delete->left_child);
            }else if(node_to_delete->right_child){
                replacement_node = MaxNode(node_to_delete->right_child);
            }
            if(replacement_node) {
                // Node<T>* tmp_node = node_to_delete;
                if(replacement_node->parent->left_child==replacement_node) {
                    replacement_node->parent->left_child = nullptr;
                    replacement_node->left_child = node_to_delete->left_child;
                    replacement_node->right_child = node_to_delete->right_child;
                }else {
                    replacement_node->parent->right_child = nullptr;
                    replacement_node->left_child = node_to_delete->left_child;
                    replacement_node->right_child = node_to_delete->right_child;
                }

            }
            if(node_to_delete->parent->left_child==node_to_delete) {
                node_to_delete->parent->left_child = replacement_node;
            }else if(node_to_delete->parent->right_child==node_to_delete) {
                node_to_delete->parent->right_child = replacement_node;
            }
            delete node_to_delete;
            size--;
        }
    }

    void PreorderNext(Node<T>* node) {
        std::cout<<"\t "<<node<<": (data: {"<<node->data.value1<<", "<<node->data.value2<<"}),"<<std::endl;
        if(node->left_child) {
            PreorderNext(node->left_child);
        }
        if(node->right_child) {
            PreorderNext(node->right_child);
        }
    }
// (d) przejście preorder drzewa
    void PreorderTraversal() {
        if(root) {
            Node<T>* node = root;
            PreorderNext(node);
        }
    }


// (e) przejście inorder drzewa
    void InorderNext(Node<T>* node) {
        if(node->left_child) {
            InorderNext(node->left_child);
        }
        std::cout<<"\t "<<node<<": (data: {"<<node->data.value1<<", "<<node->data.value2<<"}),"<<std::endl;
        if(node->right_child) {
            InorderNext(node->right_child);
        }
    }
    void InorderTraversal() {
        if(root) {
            Node<T>* node = root;
            InorderNext(node);
        }
    }

// (f) czyszczenie drzewa
    void DeleteRecursive(Node<T>* node) {
        if(node==nullptr) {
            return;
        }
        DeleteRecursive(node->left_child);
        DeleteRecursive(node->right_child);
        if(node->parent) {
            if(node->parent->left_child==node) {
                node->parent->left_child = nullptr;
            }else if(node->parent->right_child == node) {
                node->parent->right_child = nullptr;
            }
        }
        delete node;
        this->root=nullptr;
        size--;
        /*if(node->left_child) {
                DeleteRecursive(node->left_child);
            }
            if(node->right_child) {
                DeleteRecursive(node->right_child);
            }
            if(node->parent) {
                if(node->parent->left_child== node) {
                    node->parent->left_child = nullptr;
                }else {
                    node->parent->right_child = nullptr;
                }
            }else {
                size--;
                delete node;
                root = nullptr;
                return;
            }
            size--;
            delete node;*/
    }

    void Clear() {
        if(root) {
            DeleteRecursive(root);
        }else {
            std::cout<<"Lista pusta"<<std::endl;
        }
    }


// (g) wyznaczenie wysokości drzewa
    int GetHeight(Node<T>* node) {
        if(node==nullptr) return 0;
        int l_height = GetHeight(node->left_child);
        int r_height = GetHeight(node->right_child);
        if(l_height>r_height) {
            return  l_height +1;
        }
            return r_height+1;

    }

// (h) zwrócenie napisowej reprezentacji drzewa
private:
    void PrintNode(Node<T>* node,unsigned int counter=0,bool flag = false){
        std::cout<<"\t "<<node<<": (p:"<<node->parent<<", l: "<<node->left_child<<", r: "<<node->right_child<<", data: {"<<node->data.value1<<", "<<node->data.value2<<"}),"<<std::endl;
        if(flag && counter>=4) {
            return;
        }
        if(node->left_child) {
            PrintNode(node->left_child,counter+1,true);
        }
        if(node->right_child) {
            PrintNode(node->right_child,counter+1,true);
        }
    }
public:
    void PrintList(unsigned int counter=0,bool flag = false) {
        if(root) {
            std::cout<<"Binary search tree: "<<std::endl;
            std::cout<<"Size: "<<this->size<<std::endl;
            std::cout<<"Height: "<<this->GetHeight(this->root)<<std::endl;
            std::cout<<"{"<<std::endl;
            PrintNode(root,counter,flag);
            std::cout<<"}"<<std::endl;
        }else {
            std::cout<<"Lista pusta"<<std::endl;
        }
    }

};

#endif //ALGORYTMY_LAB3_BST_H
