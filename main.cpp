#include <iostream>
#include <cmath>
#include <ctime>
#include <random>
#include "bst.h"

using namespace std;

random_device rd;
mt19937 gen(rd());
uniform_int_distribution<> char_distribution(97, 122);

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
    bst->AddNode(someObject{1,'c'});
    bst->AddNode(someObject{1,'c'});
    unsigned int height = bst->GetHeight(bst->root);
    //bst->AddNode(someObject{7,'c'});
    Node<someObject>* node_ptr = bst->FindTreeNode(bst->root, {1,'c'});
    bst->DeleteNode(node_ptr);
    bst->PrintList();

    bst->InorderTraversal();
    bst->PrintList();
    bst->Clear();
    bst->PrintList();
    delete bst;
}

void Benchmark() {
    constexpr int MAX_ORDER = 7;
    auto* bst = new Bst<someObject>();
    for (int o=1;o<=MAX_ORDER;o++) {
        const int N = static_cast<int>(pow(10,o));
        clock_t t1 = clock();
        for (int i=0;i<N;i++) {
            bst->AddNode(someObject{static_cast<int>(gen()),static_cast<char>(char_distribution(gen))});
        }
        clock_t t2 = clock();
        const double addTime = (t2 - t1) / static_cast<double>(CLOCKS_PER_SEC);
        cout << "Czas dodawania " << N << " elementów do listy: " << addTime << endl;

        const int M = static_cast<int>(pow(10,4));
        unsigned int hits = 0;
        t1 = clock();
        for (int i=0;i<M;i++) {
            const auto* result = bst->FindTreeNode(bst->root,someObject{static_cast<int>(gen()),static_cast<char>(char_distribution(gen))});
            if(result !=nullptr) hits++;
            delete result;
        }
        t2 = clock();
        double searchTime = (t2 - t1) / static_cast<double>(CLOCKS_PER_SEC);
        cout<<"Udalo sie znalezc "<<hits<<" wezlow w czasie "<<searchTime<<" ms"<<endl;
        bst->PrintList(1,true);
        bst->Clear();
    }
    delete bst;
}

int main() {
    Testing();
    Benchmark();
    return 0;
}
